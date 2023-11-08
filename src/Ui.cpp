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
    return (digitalRead(buttonOnePin) == HIGH) && (digitalRead(buttonTwoPin) == HIGH);
}

void UiHandler::PlaySpeaker()
{
    digitalWrite(SpeakerPin, HIGH);
    delay(3000);
    digitalWrite(SpeakerPin, LOW);

}

//TODO: HighTempLEDOn
void UiHandler::HighTempLEDOn()
{
    digitalWrite(highTempLED, HIGH);
}

//TODO: HighTempLEDOff
void UiHandler::HighTempLEDOff()
{
    digitalWrite(highTempLED, LOW);
}

//TODO: LowTempLEDOn
void UiHandler::LowTempLEDOn()
{
    digitalWrite(lowTempLED, HIGH);
}

//TODO: LowTempLEDOff
void UiHandler::LowTempLEDOff()
{
    digitalWrite(lowTempLED, LOW);
}

//TODO: HighPressureLEDOn
void UiHandler::HighPressureLEDOn()
{
    digitalWrite(highPressureLED, HIGH);
}

//TODO: HighPressureLEDOff
void UiHandler::HighPressureLEDOff()
{
    digitalWrite(highPressureLED, LOW);
}

//TODO: InProgressLEDOn
void UiHandler::InProgressLEDOn()
{
    digitalWrite(inProgressLED, HIGH);
}

//TODO: InProgressLEDOff
void UiHandler::InProgressLEDOff()
{
    digitalWrite(inProgressLED, LOW);
}

//TODO: CompleteLEDOn
void UiHandler::CompleteLEDOn()
{
    digitalWrite(completeLED, HIGH);
}

//TODO: CompleteLEDOff
void UiHandler::CompleteLEDOff()
{
    digitalWrite(completeLED, HIGH);
}