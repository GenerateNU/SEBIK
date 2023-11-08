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
    switch(m_currentEvent)
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
    if (m_uiHandler.IsStartButtonPressed())
    {
        m_uiHandler.InProgressLEDOn();
        m_uiHandler.PlaySpeaker();
        //If start sequence then statemachine
        // Change Update parameter if you want to test a specific state
        Update(States::AIR_PUMP);
    }
}

// Turns on the air pump
void StateMachineHandler::AirPump()
{   
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
    digitalWrite(EjectionPin);
    Update(States::FINISHED);
}

// Finishing procedure
void StateMachineHandler::Finish()
{
    if (IsPlasticSafeToTouch())
    {
        m_uiHandler.CompleteLEDOn();
        delay(3000);
        m_uiHandler.CompleteLEDOff();
        Update(States::CLAMPING);
    }
}

// Gets the temperature reading from the specified pin
int StateMachineHandler::GetTempReading(int pin)
{
    int tempReading = analogRead(pin);
    return tempReading;
}

// Gets the load cell reading 
void StateMachineHandler::LoadCellReading()
{
    scale.set_scale(calibration_factor); //Adjust to this calibration factor

    Serial.print("Reading: ");
    Serial.print((scale.get_units())* 453.592, 3);
    Serial.print(" g"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
    Serial.print(" calibration_factor: ");
    Serial.print(calibration_factor);
    Serial.println();

    if(Serial.available())
    {
        char temp = Serial.read();
        if(temp == '+' || temp == 'a')
        calibration_factor += 10;
        else if(temp == '-' || temp == 'z')
        calibration_factor -= 10;
    }
}

// Checks if the plastic is safe to touch
bool StateMachineHandler::IsPlasticSafeToTouch()
{
    m_EjectionTempReading = analogRead(ejectionTempPin);
    return m_EjectionTempReading <= SAFE_TEMP_TO_TOUCH_IN_CELSIUS
}