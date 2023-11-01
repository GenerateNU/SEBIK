#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include "Errors.hpp"
#include "Ui.hpp"

enum States
{
    AIR_PUMP,
    CLAMPING,
    PLASTIC_DISPENSES,
    HEATING,
    INJECTING,
    EJECTING,
    FINSHED    
};

class StateMachineHandler
{
    private:
        enum States m_currentEvent;
        
    public:
        static ErrorHandler m_errorHandler;

        static UiHandler m_uiHandler;

        StateMachineHandler();

        ~StateMachineHandler();

        void Update(States state);

        void MainStateMachine();

        //TODO: START method
        void Start();

        //TODO: AIR_PUMP method
        void AirPump();

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
};

#endif