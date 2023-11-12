#include "Init.hpp"


#define BAUD_RATE 115200

void setup()
{
    InitializePins();
    gpioExpander.begin_I2C();
    wdt_disable();
    delay(3000);
    wdt_enable(WATCHDOG_TIMEOUT);

    Serial.begin(9600);

    // Load Cell setup
    // scale.begin(DOUT, CLK);
    // scale.set_scale();
    // scale.tare(); //Reset the scale to 0
    // long zero_factor = scale.read_average(); //Get a baseline reading
    // Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
    // Serial.println(zero_factor);
    stateMachineHandler.Start();
}

void loop()
{
    stateMachineHandler.MainStateMachine();
    wdt_reset();
    //stateMachineHandler.PressureReading();
}

