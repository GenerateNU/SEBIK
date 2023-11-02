#include <Arduino.h>
#include "StateMachine.hpp"


#define BAUD_RATE 115200

// Input PIN
#define temp2_I 13
#define temp1_I 14
#define clock_I 8
#define ejectionPressure_I 25
#define injectionPressure_I 26
#define SDA_I 27
#define reset_I 29
#define RX_I 30
#define temp3_I 10

// Output PORT
#define injectionSolenoid_O 12
#define MISO_O 16
#define SCK_O 17
#define clock_O 7
//#define SDA_O = 27
#define gpioExpanderSCK_O 28
#define TX_O 31
#define heaterRelay_O 1
#define ejectionSolenoid_O 11

StateMachineHandler stateMachineHandler;

void setup()
{
    pinMode(temp2_I, INPUT);
    pinMode(temp1_I, INPUT);
    pinMode(clock_I, INPUT);
    pinMode(ejectionPressure_I, INPUT);
    pinMode(injectionPressure_I, INPUT);
    pinMode(SDA_I, INPUT);
    pinMode(reset_I, INPUT);
    pinMode(RX_I, INPUT);
    pinMode(temp3_I, INPUT);
    pinMode(injectionSolenoid_O, OUTPUT);
    pinMode(MISO_O, OUTPUT);
    pinMode(SCK_O, OUTPUT);
    pinMode(clock_O, OUTPUT);
    //pinMode(SDA_O, OUTPUT);
    pinMode(gpioExpanderSCK_O, OUTPUT);
    pinMode(TX_O, OUTPUT);
    pinMode(heaterRelay_O, OUTPUT);
    pinMode(ejectionSolenoid_O, OUTPUT);
}

void loop()
{
    stateMachineHandler.Start();
}

