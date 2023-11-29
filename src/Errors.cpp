#include "StateMachine.hpp"

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