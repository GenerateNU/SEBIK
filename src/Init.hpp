#ifndef INIT_H
#define INIT_H

#include <Arduino.h>
#include "HX711.h"

const int HIGH_TEMP_IN_CELSIUS = 175;
const int OPTIMAL_TEMP_IN_CELSIUS = 165;
const int LOW_TEMP_IN_CELSIUS = 175;

const int SAFE_TEMP_TO_TOUCH_IN_CELSIUS = 40;

const int HIGH_PRESSURE_IN_PSI = 100;
const int OPTIMAL_PRESSURE_IN_PSI = 90; 
const int LOW_PRESSURE_IN_PSI = 80;

const int pressureInput = A0; // input pin for pressure sensor
const int PRESSURE_ZERO = 102.4; // analog read of pressure sensor at 0 psi
const int PRESSURE_MAX = 512;// analog read of pressure sensor at 100 psi
const int MAX_PSI = 100; // psi value of pressure sensor
const int SENSOR_READ_DELAY= 250; // sensor read delay

#define DOUT  3
#define CLK  2
float calibration_factor = 199900; //-7050 worked for my 440lb max scale setup


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

// #include "Arduino.h"

// struct IO{
//     char portID;
//     uint8_t pinRegister;
// };

// enum port_mode {
// 	PORT_OFF,
// 	PORT_ON,
// };

// // Input PIN
// static const IO temp2_I = {'B', PINB1};
// static const IO temp1_I = {'B', PINB2};
// static const IO clock_I = {'B', PINB7};
// static const IO ejectionPressure_I = {'C', PINC2};
// static const IO injectionPressure_I = {'C', PINC3};
// static const IO SDA_I = {'C', PINC4};
// static const IO reset_I = {'C', PINC6};
// static const IO RX_I = {'D', PIND0};
// static const IO temp3_I = {'D', PIND6};

// // Output PORT
// static const IO injectionSolenoid_O = {'B', PORTB0};
// static const IO MISO_O = {'B', PORTB4};
// static const IO SCK_O = {'B', PORTB5};
// static const IO clock_O = {'B', PORTB6};
// static const IO SDA_O = {'C', PORTC4};
// static const IO gpioExpanderSCK_O = {'C', PORTC5};
// static const IO TX_O = {'D', PORTD1};
// static const IO heaterRelay_O = {'D', PORTD3};
// static const IO ejectionSolenoid_O = {'D', PORTD7};


// /**
//  * Set PORTB pin mode
//  *
//  * Configure pin to turn on or off with the supplied portID, pin, and pull_mode
//  *
//  * param[in] IO        The IO pin 
//  * param[in] port_mode Pin pull mode
//  */
// static inline void SetOutputPinMode(IO pin, const enum port_mode pull_mode)
// {
//     switch(pin.portID)
//     {
//         case 'B':
//             if (pull_mode == PORT_ON)
//             {
//                 PORTB |= 1 << pin.pinRegister;
//             }
//             else if (pull_mode == PORT_OFF)
//             {
//                 PORTB &= ~(1 << pin.pinRegister);
//             }
//             break;

//         case 'C':
//             if (pull_mode == PORT_ON)
//             {
//                 PORTC |= 1 << pin.pinRegister;
//             }
//             else if (pull_mode == PORT_OFF)
//             {
//                 PORTC &= ~(1 << pin.pinRegister);
//             }
//             break;

//         case 'D':
//             if (pull_mode == PORT_ON)
//             {
//                 PORTD |= 1 << pin.pinRegister;
//             }
//             else if (pull_mode == PORT_OFF)
//             {
//                 PORTD &= ~(1 << pin.pinRegister);
//             }
//             break;
//     }
// }

// /**
//  * Get input pin status true or false
//  *
//  * Gets the input pin as a boolean. Only works effectively for digital pins.
//  *
//  * param[in] IO       The IO pin 
//  */
// static inline bool IsInputPinHigh(IO pin)
// {
//     switch(pin.portID)
//     {
//         case 'B':
//             return (PINB & (1<<pin.pinRegister));
//         case 'C':
//             return (PINC & (1<<pin.pinRegister));
//         case 'D':
//             return (PIND & (1<<pin.pinRegister));
//     }
// }

// static inline void Init()
// {
//     DDRB |= (1 << injectionSolenoid_O.pinRegister);
//     DDRB |= (1 << MISO_O.pinRegister);
//     DDRB |= (1 << SCK_O.pinRegister);
//     DDRB |= (1 << clock_O.pinRegister);
//     DDRC |= (1 << SDA_O.pinRegister);
//     DDRC |= (1 << gpioExpanderSCK_O.pinRegister);
//     DDRD |= (1 << TX_O.pinRegister);
//     DDRD |= (1 << heaterRelay_O.pinRegister);
//     DDRD |= (1 << ejectionSolenoid_O.pinRegister);
// }

#endif