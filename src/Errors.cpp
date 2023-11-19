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

bool ErrorHandler::IsPressureHandled(int pin)
{
    if (stateMachineHandler.GetPressureReading(pin) < OPTIMAL_PRESSURE_IN_PSI)
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