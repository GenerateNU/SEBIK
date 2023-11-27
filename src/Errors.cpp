#include "StateMachine.hpp"

//TODO: handleOverheat
void StateMachineHandler::HandleOverheat()
{
    // // If temperature is over this threshold 
    // if (stateMachineHandler.GetTempReading() > HIGH_TEMP_IN_CELSIUS)
    // {
    //     uiHandler.HighTempLEDOn();
    //     stateMachineHandler.TurnOffHeater();
    // }
    // else
    // {
    //     uiHandler.HighTempLEDOff();
    // }
}

bool StateMachineHandler::IsPressureHandled(int pin)
{
    if (GetPressureReading(pin) < OPTIMAL_PRESSURE_IN_PSI)
    {
        digitalWrite(AIR_PUMP_RELAY, HIGH);
        return false;
    }
    else
    {
        digitalWrite(AIR_PUMP_RELAY, LOW);
        return true;
    }
}