#include "StateMachine.hpp"

HX711_ADC load_cell_1(LOAD_CELL_SENSOR1, SCK);
HX711_ADC load_cell_2(LOAD_CELL_SENSOR2, SCK);
HX711_ADC load_cell_3(LOAD_CELL_SENSOR3, SCK);

Adafruit_MAX31855 thermocouple1(SCK, TEMP_SENSOR1, MISO);
Adafruit_MAX31855 thermocouple2(SCK, TEMP_SENSOR2, MISO);
Adafruit_MAX31855 thermocouple3(SCK, TEMP_SENSOR3, MISO);

StateMachineHandler::StateMachineHandler(Adafruit_MCP23X17 expander)
{
    gpioExpander = expander;
}

StateMachineHandler::~StateMachineHandler()
{
}

// Main state machine
void StateMachineHandler::MainStateMachine()
{
    switch(m_currentState)
    {
        case START:
            Start();
            break;
        case CLAMPING:
            Clamping();
            break;
        case PLASTIC_DISPENSES:
            PlasticDispense();
            break;
        case HEATING:
            Heating();
            break;
        case INJECTING:
            Injecting();
            break;
        case EJECTING:
            Unclamping();
            break;
        case FINSHED:
            Finish();
            break;
        default:
            break;
    }
    delay(10);
}

// Updates the current state
void StateMachineHandler::Update(States state)
{
    m_currentState = state;
}

void StateMachineHandler::InitializePins()
{
    //NOTE: TEMPORARILY MADE ALL PINS OUTPUT FOR HARDWARE TESTING
    // GPIO expander pinmodes
    gpioExpander.pinMode(START_PUSHBUTTON_E, OUTPUT);
    gpioExpander.pinMode(SPEAKER_E, OUTPUT);
    gpioExpander.pinMode(HIGH_TEMP_LED_E, OUTPUT);
    gpioExpander.pinMode(IN_PROGRESS_LED_E, OUTPUT);
    gpioExpander.pinMode(LOW_TEMP_LED_E, OUTPUT);
    gpioExpander.pinMode(HIGH_PRESSURE_LED_E, OUTPUT);
    gpioExpander.pinMode(COMPLETE_LED_E, OUTPUT);
    gpioExpander.pinMode(BALL_VALVE_SOLENOID_E, OUTPUT);
    gpioExpander.pinMode(EJECTION_CYLINDER_SOLENOID_E, OUTPUT);
    //gpioExpander.pinMode(HARD_STOP_RELAY_E, OUTPUT);

    pinMode(INJECTION_SOLENOID, OUTPUT);
    pinMode(EJECTION_SOLENOID, OUTPUT);
    pinMode(MISO, OUTPUT);
    pinMode(MOSI, OUTPUT);
    pinMode(SCK, OUTPUT);
    pinMode(TEMP_SENSOR1, OUTPUT);
    pinMode(TEMP_SENSOR2, OUTPUT);
    pinMode(TEMP_SENSOR3, OUTPUT);
    pinMode(INJECTION_SENSOR, OUTPUT);
    pinMode(EJECTION_SENSOR, OUTPUT);
    pinMode(LOAD_CELL_SENSOR1, OUTPUT);
    pinMode(LOAD_CELL_SENSOR2, OUTPUT);
    pinMode(LOAD_CELL_SENSOR3, OUTPUT);
    pinMode(HEATER_RELAY, OUTPUT);
    pinMode(AIR_PUMP_RELAY, OUTPUT);
    pinMode(EXTRA2, OUTPUT);

    load_cell_1.setCalFactor(809.03);
    load_cell_2.setCalFactor(836.88);
    load_cell_3.setCalFactor(771.25);
}

// Triggers state machine
void StateMachineHandler::StartStateMachine()
{
    Update(States::START);
}

// Executes start procedure
void StateMachineHandler::Start()
{
    if (IsStartButtonPressed())
    {
        InProgressLEDOn();
        PlaySpeaker();
        Update(States::CLAMPING);
    }
}

// Executes clamping procedure
void StateMachineHandler::Clamping()
{
    delay(300);
    digitalWrite(EJECTION_SOLENOID, LOW);
    m_previous_weight = GetTotalHopperWeight(); // weight before plastic is dispensed: hopper and plastic
    Update(States::PLASTIC_DISPENSES);
}

// Executes the plastic dispensing procedure
void StateMachineHandler::PlasticDispense()
{
    float curr_weight = GetTotalHopperWeight();

    // Calculates the plastic dispensed by keeping track of the previous and current weight
    if (m_plastic_dispensed >= PETRI_DISH_WEIGHT) 
    {
        gpioExpander.digitalWrite(BALL_VALVE_SOLENOID_E, LOW);
        Update(States::HEATING);
        m_plastic_dispensed = m_plastic_dispensed - PETRI_DISH_WEIGHT;
    }
    else 
    {
        gpioExpander.digitalWrite(BALL_VALVE_SOLENOID_E, HIGH);
        m_plastic_dispensed = m_plastic_dispensed + m_previous_weight - curr_weight;
        m_previous_weight = curr_weight;
    }
}

// Gets the current hopper weight
float StateMachineHandler::GetTotalHopperWeight()
{
    return load_cell_1.getData() + load_cell_2.getData() + load_cell_3.getData();
}

// Executes the heating procedure
void StateMachineHandler::Heating()
{
    // PLastic must be heated at optimal temp for 4 min
    if (m_timeHeated <= 240000)
    {
        int heatingStartTime = millis();
        if (GetTempReading(thermocouple1) >= OPTIMAL_TEMP_IN_CELSIUS)
        {
            // turn heater off
            int heatingOptimalTempTime = millis();
            m_timeHeated = m_timeHeated + heatingOptimalTempTime - heatingStartTime;
            digitalWrite(HEATER_RELAY, LOW);
        }
        else
        {
            digitalWrite(HEATER_RELAY, HIGH);
        }
    }
    else
    {
        m_timeHeated = 0;
        Update(States::INJECTING);
    }
}

// Executes the injecting procedure
void StateMachineHandler::Injecting()
{
if (IsPressureHandled(INJECTION_SENSOR))
    {
        digitalWrite(INJECTION_SOLENOID, HIGH);
        Update(States::EJECTING);
    }
}

// Executes the unclamping procedure
void StateMachineHandler::Unclamping()
{
    if (IsPressureHandled(EJECTION_SENSOR))
    {
            //injection cylinder
            digitalWrite(INJECTION_SOLENOID, LOW);
            delay(1000);
            //ejection cylinder
            digitalWrite(EJECTION_SOLENOID, LOW);
            //some kind of timer
            delay(1000);
            //mini little air cylinder
            digitalWrite(EJECTION_CYLINDER_SOLENOID_E, HIGH);
            Update(States::FINSHED);
    }
}

// Executes the finish procedure
void StateMachineHandler::Finish()
{
    digitalWrite(EJECTION_CYLINDER_SOLENOID_E, LOW);
    if (IsPlasticSafeToTouch())
    {
        CompleteLEDOn();
        delay(1000);
        CompleteLEDOff();
        Update(States::CLAMPING);
    }
}

// Gets the temperature reading from the supplied thermocouple
double StateMachineHandler::GetTempReading(Adafruit_MAX31855 thermocouple)
{
    thermocouple.begin();
    return thermocouple.readCelsius();
}

// Returns if the plastic in the ejection drawer is safe to touch
bool StateMachineHandler::IsPlasticSafeToTouch()
{
    return GetTempReading(thermocouple3) < SAFE_TEMP_TO_TOUCH_IN_CELSIUS;
}

// Gets the pressure reading from the supplied pressure sensor pin
float StateMachineHandler::GetPressureReading(int pin) 
{
    float currentPressureValue = analogRead(pin);
    currentPressureValue = currentPressureValue / 1000;
    return currentPressureValue;
}
