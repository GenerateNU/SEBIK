#include "StateMachine.hpp"
#include <Arduino.h>
#include <Adafruit_MCP23X08.h>
#include <Adafruit_MCP23X17.h>


#define BAUD_RATE 115200

void setup()
{
    // pinMode(temp2_I, INPUT);
    // pinMode(temp1_I, INPUT);
    // pinMode(clock_I, INPUT);
    // pinMode(ejectionPressure_I, INPUT);
    // pinMode(injectionPressure_I, INPUT);
    // pinMode(SDA_I, INPUT);
    // pinMode(reset_I, INPUT);
    // pinMode(RX_I, INPUT);
    // pinMode(temp3_I, INPUT);
    // pinMode(injectionSolenoid_O, OUTPUT);
    // pinMode(MISO_O, OUTPUT);
    // pinMode(SCK_O, OUTPUT);
    // pinMode(clock_O, OUTPUT);
    //pinMode(SDA_O, OUTPUT);
    // pinMode(gpioExpanderSCK_O, OUTPUT);
    // pinMode(TX_O, OUTPUT);
    // pinMode(heaterRelay_O, OUTPUT);
    // pinMode(ejectionSolenoid_O, OUTPUT);

    // Serial.begin(9600);

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
    //stateMachineHandler.PressureReading();
}

