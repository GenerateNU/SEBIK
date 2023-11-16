#include "Errors.hpp"

ErrorHandler::ErrorHandler()
{

}

ErrorHandler::~ErrorHandler()
{

}

// //TODO: handleOverpressure
// void ErrorHandler::HandleOverpressure()
// {
//     // If pressure is over this threshold
//     if (stateMachineHandler.GetPressureReading() > HIGH_PRESSURE_IN_PSI)
//     {
//         //Relieve pressure via Ejection solenoid
//     }
// }

//TODO: handleOverheat
void ErrorHandler::HandleOverheat()
{
    // If temperature is over this threshold 
    if (stateMachineHandler.GetTempReading() > HIGH_TEMP_IN_CELSIUS)
    {
        UiHandler.HighTempLEDOn();
        stateMachineHandler.TurnOffHeater();
    }
    else
    {
        UiHandler.HighTempLEDOff();
    }
}

void ErrorHandler::HandleUnderPressure()
{
    do
    {
        //stateMachineHandler.TurnOnAirPump();
        //needs to update the pressure sensor value here
    } while (stateMachineHandler.GetPressureReading() < OPTIMAL_PRESSURE_IN_PSI)
    //stateMachineHandler.TurnOffAirPump();
}