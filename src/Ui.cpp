#include "StateMachine.hpp"

// Checks if the start button is pressed
bool StateMachineHandler::IsStartButtonPressed()
{
    return gpioExpander.digitalRead(START_PUSHBUTTON_E) == HIGH;
}

// Plays the speaker
void StateMachineHandler::PlaySpeaker()
{
    gpioExpander.digitalWrite(SPEAKER_E, HIGH);
    delay(3000);
    gpioExpander.digitalWrite(SPEAKER_E, LOW);
}

// Turns on the high temp LED
void StateMachineHandler::HighTempLEDOn()
{
    gpioExpander.digitalWrite(HIGH_TEMP_LED_E, HIGH);
}

// Turns off the high temp LED
void StateMachineHandler::HighTempLEDOff()
{
    gpioExpander.digitalWrite(HIGH_TEMP_LED_E, LOW);
}

// Turns on the low temp LED
void StateMachineHandler::LowTempLEDOn()
{
    gpioExpander.digitalWrite(LOW_TEMP_LED_E, HIGH);
}

// Turns off the low temp LED
void StateMachineHandler::LowTempLEDOff()
{
    gpioExpander.digitalWrite(LOW_TEMP_LED_E, LOW);
}

// Turns on the high pressure LED
void StateMachineHandler::HighPressureLEDOn()
{
    gpioExpander.digitalWrite(HIGH_PRESSURE_LED_E, HIGH);
}

// Turns off the high pressure LED
void StateMachineHandler::HighPressureLEDOff()
{
    gpioExpander.digitalWrite(HIGH_PRESSURE_LED_E, LOW);
}

// Turns on the in progress LED
void StateMachineHandler::InProgressLEDOn()
{
    gpioExpander.digitalWrite(IN_PROGRESS_LED_E, HIGH);
}

// Turns off the in progress LED
void StateMachineHandler::InProgressLEDOff()
{
    gpioExpander.digitalWrite(IN_PROGRESS_LED_E, LOW);
}

// Turns on the complete LED
void StateMachineHandler::CompleteLEDOn()
{
    gpioExpander.digitalWrite(COMPLETE_LED_E, HIGH);
}

// Turns off the complete LED
void StateMachineHandler::CompleteLEDOff()
{
    gpioExpander.digitalWrite(COMPLETE_LED_E, LOW);
}