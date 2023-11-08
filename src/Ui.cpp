#include "Ui.hpp"

UiHandler::UiHandler()
{
}

UiHandler::~UiHandler()
{
}

//TODO: StartButtonPressed
bool UiHandler::IsStartButtonPressed()
{
    return gpioExpander.digitalRead(START_BUTTON_PRESSED) == HIGH;
}

void UiHandler::PlaySpeaker()
{
    gpioExpander.digitalWrite(SPEAKER, HIGH);
    delay(3000);
    gpioExpander.digitalWrite(SPEAKER, LOW);
}

//TODO: HighTempLEDOn
void UiHandler::HighTempLEDOn()
{
    gpioExpander.digitalWrite(HIGH_TEMP_LED, HIGH);
}

//TODO: HighTempLEDOff
void UiHandler::HighTempLEDOff()
{
    gpioExpander.digitalWrite(HIGH_TEMP_LED, LOW);
}

//TODO: LowTempLEDOn
void UiHandler::LowTempLEDOn()
{
    gpioExpander.digitalWrite(LOW_TEMP_LED, HIGH);
}

//TODO: LowTempLEDOff
void UiHandler::LowTempLEDOff()
{
    gpioExpander.digitalWrite(LOW_TEMP_LED, LOW);
}

//TODO: HighPressureLEDOn
void UiHandler::HighPressureLEDOn()
{
    gpioExpander.digitalWrite(HIGH_PRESSURE_LED, HIGH);
}

//TODO: HighPressureLEDOff
void UiHandler::HighPressureLEDOff()
{
    gpioExpander.digitalWrite(HIGH_PRESSURE_LED, LOW);
}

//TODO: InProgressLEDOn
void UiHandler::InProgressLEDOn()
{
    gpioExpander.digitalWrite(IN_PROGRESS_LED, HIGH);
}

//TODO: InProgressLEDOff
void UiHandler::InProgressLEDOff()
{
    gpioExpander.digitalWrite(IN_PROGRESS_LED, LOW);
}

//TODO: CompleteLEDOn
void UiHandler::CompleteLEDOn()
{
    gpioExpander.digitalWrite(COMPLETE_LED, HIGH);
}

//TODO: CompleteLEDOff
void UiHandler::CompleteLEDOff()
{
    gpioExpander.digitalWrite(COMPLETE_LED, LOW);
}