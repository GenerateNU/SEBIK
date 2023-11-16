#include "Init.hpp"


#define BAUD_RATE 115200

void setup()
{
    InitializePins();
    wdt_disable();
    delay(3000);
    wdt_enable(WATCHDOG_TIMEOUT);

    Serial.begin(9600);
    gpioExpander.begin_I2C();
    SPI.begin();
    SPI.setClockDivider(SPI_CLOCK_DIV8);

    // Load Cell setup
    // scale.begin(DOUT, CLK);
    // scale.set_scale();
    // scale.tare(); //Reset the scale to 0
    // long zero_factor = scale.read_average(); //Get a baseline reading
    // Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
    // Serial.println(zero_factor);
    stateMachineHandler.Start();
    
    //Initialize thermocouples
    thermocouple1.begin();
    thermocouple2.begin();
    thermocouple3.begin();
}

void loop()
{
    stateMachineHandler.MainStateMachine();
    wdt_reset();
    //stateMachineHandler.PressureReading();
}

