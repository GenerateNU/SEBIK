#ifndef INIT_H
#define INIT_H

#include <Arduino.h>
#include "HX711.h"
#include <Adafruit_MCP23X08.h>
#include <Adafruit_MCP23X17.h>

#define START_PUSHBUTTON B0
#define SPEAKER B1
#define HIGH_TEMP_LED A0
#define IN_PROGRESS_LED A1
#define LOW_TEMP_LED A2
#define HIGH_PRESSURE_LED A3
#define COMPLETE_LED

#define MISO B4
#define SCK B5
#define TEMP_SENSOR1 B2
#define TEMP_SENSOR2 B1
#define TEMP_SENSOR3 D6

const int HIGH_TEMP_IN_CELSIUS = 175;
const int OPTIMAL_TEMP_IN_CELSIUS = 165;
const int LOW_TEMP_IN_CELSIUS = 175;

const int SAFE_TEMP_TO_TOUCH_IN_CELSIUS = 40;

const int HIGH_PRESSURE_IN_PSI = 100;
const int OPTIMAL_PRESSURE_IN_PSI = 90; 
const int LOW_PRESSURE_IN_PSI = 80;

#define pressureInput = A0; // input pin for pressure sensor
const int PRESSURE_ZERO = 102.4; // analog read of pressure sensor at 0 psi
const int PRESSURE_MAX = 512;// analog read of pressure sensor at 100 psi
const int MAX_PSI = 100; // psi value of pressure sensor
const int SENSOR_READ_DELAY= 250; // sensor read delay

#define DOUT  3
#define CLK  2
float calibration_factor = 199900; //-7050 worked for my 440lb max scale setup

StateMachineHandler stateMachineHandler;
Adafruit_MCP23X17 gpioExpander;

static void InitializePins()
{
    gpioExpander.pinMode(START_PUSHBUTTON, INPUT);
    gpioExpander.pinMode(SPEAKER, OUTPUT);
    gpioExpander.pinMode(HIGH_TEMP_LED, OUTPUT);
    gpioExpander.pinMode(IN_PROGRESS_LED, OUTPUT);
    gpioExpander.pinMode(LOW_TEMP_LED, OUTPUT);
    gpioExpander.pinMode(HIGH_PRESSURE_LED, OUTPUT);

}

#endif