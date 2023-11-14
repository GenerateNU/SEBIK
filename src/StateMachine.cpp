#include "StateMachine.hpp"

StateMachineHandler::StateMachineHandler()
{

}

StateMachineHandler::~StateMachineHandler()
{

}

void StateMachineHandler::MainStateMachine()
{
    m_errorHandler.HandleOverheat();
    switch(m_currentState)
    {
        case AIR_PUMP:
            AirPump();
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
}

// Updates the current state
void StateMachineHandler::Update(States state)
{  
    m_currentEvent = state;
}

// Initializes the first state in void setup()
void StateMachineHandler::Start()
{
    // NOTE: TEMPORARILY FOR HARDWARE TESTING
    gpioExpander.digitalWrite(START_PUSHBUTTON_E, HIGH);
    gpioExpander.digitalWrite(SPEAKER_E, HIGH);
    gpioExpander.digitalWrite(HIGH_TEMP_LED_E, HIGH);
    gpioExpander.digitalWrite(IN_PROGRESS_LED_E, HIGH);
    gpioExpander.digitalWrite(LOW_TEMP_LED_E, HIGH);
    gpioExpander.digitalWrite(HIGH_PRESSURE_LED_E, HIGH);
    gpioExpander.digitalWrite(COMPLETE_LED_E, HIGH);
    gpioExpander.digitalWrite(BALL_VALVE_SOLENOID_E, HIGH);
    gpioExpander.digitalWrite(EJECTION_CYLINDER_SOLENOID_E, HIGH);
    gpioExpander.digitalWrite(HARD_STOP_RELAY_E, HIGH);

    digitalWrite(INJECTION_SOLENOID, HIGH);
    digitalWrite(EJECTION_SOLENOID, HIGH);
    digitalWrite(MISO, HIGH);
    digitalWrite(MOSI, HIGH);
    digitalWrite(SCK, HIGH);
    digitalWrite(TEMP_SENSOR1, HIGH);
    digitalWrite(TEMP_SENSOR2, HIGH);
    digitalWrite(TEMP_SENSOR3, HIGH);
    digitalWrite(INJECTION_SENSOR, HIGH);
    digitalWrite(EJECTION_SENSOR, HIGH);
    digitalWrite(LOAD_CELL_SENSOR1, HIGH);
    digitalWrite(LOAD_CELL_SENSOR2, HIGH);
    digitalWrite(LOAD_CELL_SENSOR3, HIGH);
    digitalWrite(HEATER_RELAY, HIGH);
    digitalWrite(EXTRA1, HIGH);
    digitalWrite(EXTRA2, HIGH);


    // if (m_uiHandler.IsStartButtonPressed())
    // {
    //     m_uiHandler.InProgressLEDOn();
    //     m_uiHandler.PlaySpeaker();
    //     //If start sequence then statemachine
    //     // Change Update parameter if you want to test a specific state
    //     Update(States::AIR_PUMP);
    // }
}

// Turns on the air pump
void StateMachineHandler::AirPump()
{   
    // if desired pressure 
    Update(States::CLAMPING);
}

// Clamps the mold
void StateMachineHandler::Clamping()
{
    Update(States::PLASTIC_DISPENSES);
}

// Dispenses plastic
void StateMachineHandler::PlasticDispense()
{
    // if (readWeight and it is below optimal weight)
    // dispense plastic
    // else
        Update(States::HEATING);
}

// Starts the heating process
void StateMachineHandler::Heating()
{
    Update(States::INJECTING);
}

// Turns off the heater
void StateMachineHandler::TurnOffHeater()
{

}

// Injects melted plastic
void StateMachineHandler::Injecting()
{
    Update(States::EJECTING);
}

// Unclamps mold
void StateMachineHandler::Unclamping()
{
    digitalWrite(EJECTION_CYLINDER_SOLENOID_E, HIGH);
    Update(States::FINSHED);
}

// Finishing procedure
void StateMachineHandler::Finish()
{
    if (IsPlasticSafeToTouch())
    {
        m_uiHandler.CompleteLEDOn();
        delay(1000);
        m_uiHandler.CompleteLEDOff();
        Update(States::CLAMPING);
    }
}

// Gets the temperature reading from the specified pin
int StateMachineHandler::GetTempReading(int pin)
{

}

// Gets the load cell reading 
void StateMachineHandler::LoadCellReading()
{
    // scale.begin(MISO, SCK);
    // scale.set_scale(calibration_factor); //Adjust to this calibration factor

    // Serial.print("Reading: ");
    // Serial.print((scale.get_units())* 453.592, 3);
    // Serial.print(" g"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
    // Serial.print(" calibration_factor: ");
    // Serial.print(calibration_factor);
    // Serial.println();

    // if(Serial.available())
    // {
    //     char temp = Serial.read();
    //     if(temp == '+' || temp == 'a')
    //     calibration_factor += 10;
    //     else if(temp == '-' || temp == 'z')
    //     calibration_factor -= 10;
    // }
}

// Checks if the plastic is safe to touch
bool StateMachineHandler::IsPlasticSafeToTouch()
{
    m_EjectionTempReading = analogRead(ejectionTempPin);
    return m_EjectionTempReading <= SAFE_TEMP_TO_TOUCH_IN_CELSIUS;
}