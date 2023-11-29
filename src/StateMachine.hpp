#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include <HX711_ADC.h>
#include <Adafruit_MCP23X17.h>
#include <Adafruit_MAX31855.h>

// UI pins
#define START_PUSHBUTTON_E 8
#define SPEAKER_E 9
#define HIGH_TEMP_LED_E 0
#define IN_PROGRESS_LED_E 1
#define LOW_TEMP_LED_E 2
#define HIGH_PRESSURE_LED_E 3
#define COMPLETE_LED_E 4
//#define HARD_STOP_BUTTON_E 7

// Solenoid pins
#define INJECTION_SOLENOID 8
#define EJECTION_SOLENOID 7
#define BALL_VALVE_SOLENOID_E 11
#define EJECTION_CYLINDER_SOLENOID_E 12

// SPI
#define MISO 12
#define MOSI 11
#define SCK 13

// Sensor pins
#define TEMP_SENSOR1 10
#define TEMP_SENSOR2 9
#define TEMP_SENSOR3 6
#define INJECTION_SENSOR 17
#define EJECTION_SENSOR 16
#define LOAD_CELL_SENSOR1 5
#define LOAD_CELL_SENSOR2 4
#define LOAD_CELL_SENSOR3 2

// Relays
#define HARD_STOP_RELAY_E 10
#define HEATER_RELAY 3
#define AIR_PUMP_RELAY 14

#define EXTRA2 15

const int HIGH_TEMP_IN_CELSIUS = 175;
const int OPTIMAL_TEMP_IN_CELSIUS = 165;

const int SAFE_TEMP_TO_TOUCH_IN_CELSIUS = 40;

const int HIGH_PRESSURE_IN_PSI = 100;
const int OPTIMAL_PRESSURE_IN_PSI = 90; 
const int LOW_PRESSURE_IN_PSI = 80;

const float PETRI_DISH_WEIGHT = 100; // g, change this later to actual weight

const float calibration_factor = 199900; //-7050 worked for my 440lb max scale setup

enum States
{
    START,
    CLAMPING,
    PLASTIC_DISPENSES,
    HEATING,
    INJECTING,
    EJECTING,
    FINSHED,
    HARD_STOP
};

class StateMachineHandler
{
    private:
        enum States m_currentState;
        int m_timeHeated = 0; 
        float m_plastic_dispensed = 0;
        float m_previous_weight;
        Adafruit_MCP23X17 gpioExpander;

    public:
        StateMachineHandler(Adafruit_MCP23X17 expander);

        ~StateMachineHandler();

        void InitializePins();

        void StartStateMachine();

        // Updates the current state
        void Update(States state);

        // Triggers state machine

        // Main state machine
        void MainStateMachine();

        // Executes start procedure
        void Start();

        // Executes clamping procedure
        void Clamping();

        // Executes the plastic dispensing procedure
        void PlasticDispense();

        // Gets the current hopper weight
        float GetTotalHopperWeight();

        // Executes the heating procedure
        void Heating();

        // Executes the injecting procedure
        void Injecting();

        // Executes the unclamping procedure
        void Unclamping();

        // Executes the finish procedure
        void Finish();

        // Gets the pressure reading from the supplied pressure sensor pin
        float GetPressureReading(int pin);

        // Gets the temperature reading from the supplied thermocouple
        double GetTempReading(Adafruit_MAX31855 thermocouple);

        // Returns if the plastic in the ejection drawer is safe to touch
        bool IsPlasticSafeToTouch();

        void HardwareTest();

        bool IsStartButtonPressed();

        void PlaySpeaker();

        void HighTempLEDOn();
        
        void HighTempLEDOff();

        void LowTempLEDOn();

        void LowTempLEDOff();

        void HighPressureLEDOn();

        void HighPressureLEDOff();

        void InProgressLEDOn();

        void InProgressLEDOff();

        void CompleteLEDOn();

        void CompleteLEDOff();

        void HandleOverheat();

        bool IsPressureHandled(int pin);
};

#endif