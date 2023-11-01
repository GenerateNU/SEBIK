#include "StateMachine.hpp"

StateMachineHandler::StateMachineHandler()
{

}

StateMachineHandler::~StateMachineHandler()
{

}

void StateMachineHandler::MainStateMachine()
{
    switch(m_currentEvent)
    {
        case AIR_PUMP:
            AirPump();
            Update(States::CLAMPING);
            break;
        case CLAMPING:
            Clamping();
            Update(States::PLASTIC_DISPENSES);
            break;
        case PLASTIC_DISPENSES:
            PlasticDispense();
            Update(States::HEATING);
            break;
        case HEATING:
            Heating();
            Update(States::INJECTING);
            break;
        case INJECTING:
            Injecting();
            Update(States::EJECTING);
            break;
        case EJECTING:
            Unclamping();
            Update(States::FINSHED);
            break;
        case FINSHED:
            Finish();
            Update(States::AIR_PUMP);
            break;
    }
}

void StateMachineHandler::Update(States state)
{  
    m_currentEvent = state;
}

//TODO: START method
void StateMachineHandler::Start()
{
    //If start sequence then statemachine

    //Update UI
    m_uiHandler.InProgressLEDOn();
    Update(States::AIR_PUMP);

    // Check for errors
    m_errorHandler.HandleOverheat();
    m_errorHandler.HandleOverpressure();
}

//TODO: AIR_PUMP method
void StateMachineHandler::AirPump()
{
    // Check for errors
    m_errorHandler.HandleOverheat();
    m_errorHandler.HandleOverpressure();
}

//TODO: CLAMPING method
void StateMachineHandler::Clamping()
{
    // Check for errors
    m_errorHandler.HandleOverheat();
    m_errorHandler.HandleOverpressure();
}

//TODO: PLASTIC_DISPENSE method
void StateMachineHandler::PlasticDispense()
{
    // Check for errors
    m_errorHandler.HandleOverheat();
    m_errorHandler.HandleOverpressure();
}

//TODO: HEATING method
void StateMachineHandler::Heating()
{
    // Check for errors
    m_errorHandler.HandleOverheat();
    m_errorHandler.HandleOverpressure();
}

//TODO: INJECTING method
void StateMachineHandler::Injecting()
{
    // Check for errors
    m_errorHandler.HandleOverheat();
    m_errorHandler.HandleOverpressure();
}

//TODO: UNCLAMPING method
void StateMachineHandler::Unclamping()
{
    // Check for errors
    m_errorHandler.HandleOverheat();
    m_errorHandler.HandleOverpressure();
}

//TODO: FINISHED method
void StateMachineHandler::Finish()
{
    // Check for errors
    m_errorHandler.HandleOverheat();
    m_errorHandler.HandleOverpressure();
}