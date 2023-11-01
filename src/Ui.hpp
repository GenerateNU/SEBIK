#ifndef UI_HPP
#define UI_HPP

enum UiState
{
    START_BUTTON_PRESSED,
    // HARD_STOP_BUTTON_PRESSED,
    HIGH_TEMP_LED_ON,
    HIGH_TEMP_LED_OFF,
    LOW_TEMP_LED_ON,
    LOW_TEMP_LED_OFF,
    HIGH_PRESSURE_LED_ON,
    HIGH_PRESSURE_LED_OFF,
    IN_PROGRESS_LED_ON,
    IN_PROGRESS_LED_OFF,
    COMPLETE_LED_ON,
    COMPLETE_LED_OFF
};

class UiHandler
{
    private:
        enum UiState m_currentUiState;

    public:
        UiHandler();

        ~UiHandler();

        //TODO: StartButtonPressed
        void StartButtonPressed();

        //TODO: HardStopButtonPressed
        void HardStopButtonPressed();

        //TODO: HighTempLEDOn
        void HighTempLEDOn();

        //TODO: HighTempLEDOff
        void HighTempLEDOff();

        //TODO: LowTempLEDOn
        void LowTempLEDOn();

        //TODO: LowTempLEDOff
        void LowTempLEDOff();

        //TODO: HighPressureLEDOn
        void HighPressureLEDOn();

        //TODO: HighPressureLEDOff
        void HighPressureLEDOff();

        //TODO: InProgressLEDOn
        void InProgressLEDOn();

        //TODO: InProgressLEDOff
        void InProgressLEDOff();

        //TODO: CompleteLEDOn
        void CompleteLEDOn();

        //TODO: CompleteLEDOff
        void CompleteLEDOff();

};

#endif