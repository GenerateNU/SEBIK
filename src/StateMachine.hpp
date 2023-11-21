#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include "Init.hpp"

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
        
    public:

        StateMachineHandler();

        ~StateMachineHandler();

        void Update(States state);

        void MainStateMachine();
        
        void Start();

        void StartStateMachine();

        //TODO: CLAMPING method
        void Clamping();

        //TODO: PLASTIC_DISPENSE method
        void PlasticDispense();

        //TODO: HEATING method
        void Heating();

        //TODO: INJECTING method
        void Injecting();

        //TODO: UNCLAMPING method
        void Unclamping();

        //TODO: FINISHED method
        void Finish();

        float GetPressureReading(int pin);

        void PushPneumaticCylinder();

        double GetTempReading(Adafruit_MAX31855 thermocouple);
        
        void LoadCellReading();

        bool IsPlasticSafeToTouch();

        void PowerOff();

        void TurnOffHeater();
};

#endif