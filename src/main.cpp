#include <Arduino.h>
#include <avr/wdt.h>
#include <Adafruit_MCP23X17.h>
#include <Adafruit_MAX31855.h>
#include "StateMachine.hpp"

#define BAUD_RATE 115200

// Crystal Oscillator
#define F_CPU 16000000UL

// Watchdog timer
#define WATCHDOG_TIMEOUT WDTO_8S

Adafruit_MCP23X17 gpioExpander;


StateMachineHandler stateMachineHandler(gpioExpander);

void setup()
{   
    stateMachineHandler.InitializePins();
    wdt_disable();
    delay(3000);
    wdt_enable(WATCHDOG_TIMEOUT);

    Serial.begin(9600);
    gpioExpander.begin_I2C();
    stateMachineHandler.StartStateMachine();
}

void loop()
{
    stateMachineHandler.MainStateMachine();
    wdt_reset();
}
