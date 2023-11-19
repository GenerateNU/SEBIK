#ifndef INIT_H
#define INIT_H

#include <Arduino.h>
#include <avr/wdt.h>
#include <SPI.h>
#include "HX711.h"
#include <Adafruit_MCP23X17.h>
#include <Adafruit_MAX31855.h>
#include "StateMachine.hpp"
#include "Ui.hpp"
#include "Errors.hpp"


// Crystal Oscillator
#define F_CPU 16000000UL

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

#define WATCHDOG_TIMEOUT WDTO_8S

const int HIGH_TEMP_IN_CELSIUS = 175;
const int OPTIMAL_TEMP_IN_CELSIUS = 165;

const int SAFE_TEMP_TO_TOUCH_IN_CELSIUS = 40;

const int HIGH_PRESSURE_IN_PSI = 100;
const int OPTIMAL_PRESSURE_IN_PSI = 90; 
const int LOW_PRESSURE_IN_PSI = 80;

const int PRESSURE_ZERO = 102.4; // analog read of pressure sensor at 0 psi
const int PRESSURE_MAX = 512;// analog read of pressure sensor at 100 psi
const int MAX_PSI = 100; // psi value of pressure sensor
const int SENSOR_READ_DELAY= 250; // sensor read delay

float calibration_factor = 199900; //-7050 worked for my 440lb max scale setup

StateMachineHandler stateMachineHandler;
ErrorHandler errorHandler;
UiHandler uiHandler;
Adafruit_MCP23X17 gpioExpander;
HX711 scale;

Adafruit_MAX31855 thermocouple1(SCK, TEMP_SENSOR1, MISO);
Adafruit_MAX31855 thermocouple2(SCK, TEMP_SENSOR2, MISO);
Adafruit_MAX31855 thermocouple3(SCK, TEMP_SENSOR3, MISO);

static void InitializePins()
{
    //NOTE: TEMPORARILY MADE ALL PINS OUTPUT FOR HARDWARE TESTING
    // GPIO expander pinmodes
    gpioExpander.pinMode(START_PUSHBUTTON_E, OUTPUT);
    gpioExpander.pinMode(SPEAKER_E, OUTPUT);
    gpioExpander.pinMode(HIGH_TEMP_LED_E, OUTPUT);
    gpioExpander.pinMode(IN_PROGRESS_LED_E, OUTPUT);
    gpioExpander.pinMode(LOW_TEMP_LED_E, OUTPUT);
    gpioExpander.pinMode(HIGH_PRESSURE_LED_E, OUTPUT);
    gpioExpander.pinMode(COMPLETE_LED_E, OUTPUT);
    gpioExpander.pinMode(BALL_VALVE_SOLENOID_E, OUTPUT);
    gpioExpander.pinMode(EJECTION_CYLINDER_SOLENOID_E, OUTPUT);
    gpioExpander.pinMode(HARD_STOP_RELAY_E, OUTPUT);

    pinMode(INJECTION_SOLENOID, OUTPUT);
    pinMode(EJECTION_SOLENOID, OUTPUT);
    pinMode(MISO, OUTPUT);
    pinMode(MOSI, OUTPUT);
    pinMode(SCK, OUTPUT);
    pinMode(TEMP_SENSOR1, OUTPUT);
    pinMode(TEMP_SENSOR2, OUTPUT);
    pinMode(TEMP_SENSOR3, OUTPUT);
    pinMode(INJECTION_SENSOR, OUTPUT);
    pinMode(EJECTION_SENSOR, OUTPUT);
    pinMode(LOAD_CELL_SENSOR1, OUTPUT);
    pinMode(LOAD_CELL_SENSOR2, OUTPUT);
    pinMode(LOAD_CELL_SENSOR3, OUTPUT);
    pinMode(HEATER_RELAY, OUTPUT);
    pinMode(AIR_PUMP_RELAY, OUTPUT);
    pinMode(EXTRA2, OUTPUT);
}

#endif