/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  Copyright (c) 2019 Infineon Technologies AG
  This file has been modified for the XMC microcontroller series.
*/
#ifndef PINS_ARDUINO_H_
#define PINS_ARDUINO_H_

//****************************************************************************
// @Project Includes
//****************************************************************************
#include <XMC4400.h>

//****************************************************************************
// @Defines
//****************************************************************************
#define XMC_BOARD       XMC 4400 Platform 2GO

/* On board LED is ON when digital output is 0, LOW, False, OFF */
#define XMC_LED_ON          0

// Following were defines now evaluated by compilation as const variables
// After definitions of associated mapping arrays
extern const uint8_t NUM_DIGITAL;
extern const uint8_t GND;
extern const uint8_t NUM_PWM4;
extern const uint8_t NUM_PWM8;
extern const uint8_t NUM_PWM;
extern const uint8_t NUM_INTERRUPT;
extern const uint8_t NUM_ANALOG_INPUTS;
#ifdef DAC
extern const uint8_t NUM_ANALOG_OUTPUTS;
#endif
#define NUM_LEDS            2
#define NUM_BUTTONS         2
#define NUM_SERIAL          1
#define NUM_TONE_PINS       16
#define NUM_TASKS_VARIANT   32

// Indicate unit has RTC/Alarm
#define HAS_RTC                 1

#define PWM4_TIMER_PERIOD (0x11EF)  //Generate 490Hz @fCCU=144MHz
#define PWM8_TIMER_PERIOD (0x11EF)  // Generate 490Hz @fCCU=144MHz

#define PCLK 64000000u

#define PIN_SPI_SS      10
#define PIN_SPI_MOSI    11
#define PIN_SPI_MISO    12
#define PIN_SPI_SCK     13

extern uint8_t SS;
extern uint8_t MOSI;
extern uint8_t MISO;
extern uint8_t SCK;

#define A0  0       // ADC G0CH0 P14.0
#define A1  1       // ADC G0CH1 P14.1
#define A2  2       // ADC G0CH2 P14.2
#define A3  3       // ADC G0CH3 P14.3
#define A4  4       // ADC G0CH4 P14.4
#define A5  5       // ADC G0CH5 P14.5
//Additional ADC ports starting here
#define A6   6      // ADC G0CH6 on P14.6
#define A7   7      // ADC G0CH7 on P14.7
#define A8   8      // ADC G1CH4 on P14.12
#define A9   9      // ADC G1CH5 on P14.13
#define A10  10     // ADC G1CH6 on P14.14
#define A11  11     // ADC G1CH7 on P14.15
#define A12  12     // ADC G2CH2 on P15.2
#define A13  13     // ADC G2CH3 on P15.3
#define A14  14     // ADC G1CH0 on P14.8
#define A15  15     // ADC G1CH1 on P14.9
#define A16  16     // ADC G3CH0 on P15.8
#define A17  17     // ADC G3CH1 on P15.9

#define LED1        82  // Additional LED1
#define LED2        77  // Additional LED2
#define LED_BUILTIN LED1  // Standard Arduino LED: Uses LED1
#define BUTTON1     87  // Additional BUTTON1
#define BUTTON2     69  // Additional BUTTON2

#define digitalPinToInterrupt(p)    ((p) == 2 ? 0 : ((p) == 3 ? 1 : NOT_AN_INTERRUPT))

#ifdef ARDUINO_MAIN
// Mapping of digital pins and comments
const XMC_PORT_PIN_t mapping_port_pin[]=
    {
    /* 0  */    {XMC_GPIO_PORT2, 15},   // RX                           P2.15
    /* 1  */    {XMC_GPIO_PORT2, 14},   // TX                           P2.14
    /* 2  */    {XMC_GPIO_PORT1, 0},    // GPIO / External INT 0        P1.0
    /* 3  */    {XMC_GPIO_PORT3, 6},    // PWM42-0(PWM0)/ External INT 1  P3.6
    /* 4  */    {XMC_GPIO_PORT1, 6},    // GPIO                         P1.6
    /* 5  */    {XMC_GPIO_PORT3, 3},    // PWM42-3 output / PWM1        P3.3
    /* 6  */    {XMC_GPIO_PORT3, 4},    // PWM42-2 output / PWM2        P3.4
    /* 7  */    {XMC_GPIO_PORT1, 14},   // GPIO                         P1.14
    /* 8  */    {XMC_GPIO_PORT4, 1},    // GPIO                         P4.1
    /* 9  */    {XMC_GPIO_PORT0, 11},   // PWM80-31 output / PWM3       P0.11
    /* 10 */    {XMC_GPIO_PORT0, 2},    // SPI-SS / PWM80-01 / PWM4     P0.2
    /* 11 */    {XMC_GPIO_PORT1, 9},    // SPI-MOSI / PWM41-2 / PWM5    P1.9
    /* 12 */    {XMC_GPIO_PORT0, 0},    // SPI-MISO                     P0.0
    /* 13 */    {XMC_GPIO_PORT1, 8},    // SPI-SCK                      P1.8
    /* 14 */    {XMC_GPIO_PORT2, 3},    // AREF TODO:                   P2.3
    /* 15 */    {XMC_GPIO_PORT2, 5},    // I2C Data / Address SDA / A4  P2.5  (Hardwired to A4)
    /* 16 */    {XMC_GPIO_PORT3, 0},    // I2C Clock SCL  / A5          P3.0  (Hardwired to A5)
    /* 17  */   {XMC_GPIO_PORT14, 0},   // A0 / ADC Input               P14.0 (INPUT ONLY)
    /* 18  */   {XMC_GPIO_PORT14, 1},   // A1 / ADC Input               P14.1 (INPUT ONLY)
    /* 19  */   {XMC_GPIO_PORT14, 2},   // A2 / ADC Input               P14.2 (INPUT ONLY)
    /* 20  */   {XMC_GPIO_PORT14, 3},   // A3 / ADC Input               P14.3 (INPUT ONLY)
    /* 21  */   {XMC_GPIO_PORT14, 4},   // A4 / ADC Input / SDA         P14.4 (Hardwired to SDA)
    /* 22  */   {XMC_GPIO_PORT14, 5},   // A5 / ADC Input / SCL         P14.5 (Hardwired to SCL)
    /* 23  */   {XMC_GPIO_PORT1, 15},   // USB Debug RX                 P1.15
    /* 24  */   {XMC_GPIO_PORT0, 5},    // USB Debug TX                 P0.5

    //Additional pins for port X1 starting here
    /* 25  */   {XMC_GPIO_PORT2, 10},   // GPIO / ETH_LED               P2.10
    /* 26  */   {XMC_GPIO_PORT2, 8},    // GPIO / ETH_TXDO              P2.8
    /* 27  */   {XMC_GPIO_PORT2, 4},    // GPIO / ETH_RXER              P2.4
    /* 28  */   {XMC_GPIO_PORT2, 2},    // GPIO / ETH_RXDO              P2.2
    /* 29  */   {XMC_GPIO_PORT2, 0},    // GPIO / ETH_MDIO              P2.0
    /* 30  */   {XMC_GPIO_PORT2, 6},    // PWM8 -  / PWM / GPIO4_2GO_2  P2.6
    /* 31  */   {XMC_GPIO_PORT5, 2},    // GPIO / RST                   P5.2
    /* 32  */   {XMC_GPIO_PORT5, 0},    // GPIO1_2GO_1                  P5.0
    /* 33  */   {XMC_GPIO_PORT1, 14},   // GPIO / IO_1                  P1.14
    /* 34  */   {XMC_GPIO_PORT1, 12},   // GPIO / CAN_TX                P1.12
    /* 35  */   {XMC_GPIO_PORT1, 10},   // GPIO / GPIO2_2GO_1           P1.10
    /* 36  */   {XMC_GPIO_PORT1, 4},    // GPIO / QSPI_IO1              P1.4
    /* 37  */   {XMC_GPIO_PORT1, 2},    // GPIO / QSPI_IO3              P1.2
    /* 38  */   {XMC_GPIO_PORT1, 0},    // GPIO / External INT 0        P1.0
    /* 39  */   {XMC_GPIO_PORT1, 8},    // GPIO / SPI-SCK               P1.8
    /* 40  */   {XMC_GPIO_PORT1, 6},    // GPIO / IO_0                  P1.6
    /* 41  */   {XMC_GPIO_PORT4, 0},    // GPIO / GPIO2_2GO_2           P1.0
    /* 42  */   {XMC_GPIO_PORT2, 14},   // UART TX                      P2.14
    /* 43  */   {XMC_GPIO_PORT2, 15},   // UART RX                      P2.15
    /* 44  */   {XMC_GPIO_PORT4, 1},    // GPIO / IO_2                  P4.1.
    /* 45  */   {XMC_GPIO_PORT1, 7},    // GPIO / SPI_CS_2GO_2          P1.7 (Chip Select - Slot 2)
    /* 46  */   {XMC_GPIO_PORT1, 9},    // SPI-MOSI / PWM41-2 / PWM5    P1.9
    /* 47  */   {XMC_GPIO_PORT1, 1},    // GPIO1_2GO_2                  P1.1
    /* 48  */   {XMC_GPIO_PORT1, 3},    // GPIO / QSPI_IO3              P1.3
    /* 49  */   {XMC_GPIO_PORT1, 5},    // GPIO / QSPI_IO0              P1.5
    /* 50  */   {XMC_GPIO_PORT1, 11},   // GPIO / QSPI_CS               P1.11
    /* 51  */   {XMC_GPIO_PORT1, 13},   // GPIO / CAN_RX                P1.13
    /* 52  */   {XMC_GPIO_PORT1, 15},   // USB Debug RX                 P1.15
    /* 53  */   {XMC_GPIO_PORT5, 1},    // GPIO / ETH_INT               P5.1
    /* 54  */   {XMC_GPIO_PORT5, 7},    // PWM8 -  / PWM                P5.7
    /* 55  */   {XMC_GPIO_PORT2, 7},    // PWM8 -  / PWM  / ETH_MDC     P2.7
    /* 56  */   {XMC_GPIO_PORT2, 1},    // SWV   ""DEBUG Do NOT Use **  P2.1
    /* 57  */   {XMC_GPIO_PORT2, 3},    // AREF TODO: / ETH_RXD1        P2.3
    /* 58  */   {XMC_GPIO_PORT2, 5},    // I2C Data - SDA / A4          P2.5 (Hardwired to A4)
    /* 59  */   {XMC_GPIO_PORT2, 9},    // PWM8 -  / PWM / ETH_TXD1     P2.9
    /* 60  */   {XMC_GPIO_PORT15, 8},   // A16 / ETH_CLK                P15.8

    //Additional pins for port X2 starting here
    /* 61  */   {XMC_GPIO_PORT14, 8},   // A14 / DAC 0 Output           P14.8
    /* 62  */   {XMC_GPIO_PORT15, 2},   // A12 - ADC Input              P15.2 (INPUT ONLY)
    /* 63  */   {XMC_GPIO_PORT14, 15},  // A11 - ADC Input              P14.15 (INPUT ONLY)
    /* 64  */   {XMC_GPIO_PORT15, 9},   // A17 - ADC Input / ETH_CRS    P15.9
    /* 65  */   {XMC_GPIO_PORT14, 6},   // A6 / AN1_2GO_1 - ADC Input   P14.6 (INPUT ONLY)
    /* 66  */   {XMC_GPIO_PORT14, 12},  // A8 / AN1_2GO_2 - ADC Input   P14.12 (INPUT ONLY)
    /* 67  */   {XMC_GPIO_PORT14, 14},  // A10 / ADC Input              P14.14 (INPUT ONLY)
    /* 68  */   {XMC_GPIO_PORT3, 0},    // I2C Clk SCL / A5 - ADC Input P3.0  (Hardwired to A5)
    /* 69  */   {XMC_GPIO_PORT3, 2},    // BUTTON2                      P3.2
    /* 70  */   {XMC_GPIO_PORT0, 10},   // INT / GPIO3_2GO_1            P0.10
    /* 71  */   {XMC_GPIO_PORT0, 1},    // INT                          P0.1
    /* 72  */   {XMC_GPIO_PORT0, 3},    // INT / GPIO3_2GO_2            P0.3
    /* 73  */   {XMC_GPIO_PORT0, 5},    // USB Debug TX                 P0.5
    /* 74  */   {XMC_GPIO_PORT0, 11},   // PWM80-31 output / PWM3       P0.11
    /* 75  */   {XMC_GPIO_PORT3, 3},    // PWM42-3 output / PWM1        P3.3
    /* 76  */   {XMC_GPIO_PORT3, 5},    // CS_2GO_1                     P3.5 (Chip Select - Slot 1)
    /* 77  */   {XMC_GPIO_PORT0, 7},    // LED2                         P0.7
    /* 78  */   {XMC_GPIO_PORT0, 8},    // QSPI_CLK                     P0.8
    /* 79  */   {XMC_GPIO_PORT3, 6},    // PWM42-0(PWM0)/ External INT 1 P3.6
    /* 80  */   {XMC_GPIO_PORT3, 4},    // PWM42-2 output / PWM2        P3.4
    /* 81  */   {XMC_GPIO_PORT0, 12},   // CS_MB                        P0.12
    /* 82  */   {XMC_GPIO_PORT0, 6},    // LED1                         P0.6
    /* 83  */   {XMC_GPIO_PORT0, 4},    // ETH_TXEN                     P0.4
    /* 84  */   {XMC_GPIO_PORT0, 2},    // SPI-CS / PWM80-01 / PWM4     P0.2
    /* 85  */   {XMC_GPIO_PORT0, 0},    // SPI-MISO                     P0.0
    /* 86  */   {XMC_GPIO_PORT0, 9},    // GPIO4_2GO_1 / PWM80-01 / PWM P0.9
    /* 87  */   {XMC_GPIO_PORT3, 1},    // BUTTON1                      P3.1
    /* 88  */   {XMC_GPIO_PORT14, 4},   // A4 - ADC Input / SDA         P14.4 (Hardwired to SDA)
    /* 89  */   {XMC_GPIO_PORT14, 13},  // A9 / AN2_2GO_2 - ADC Input   P14.13 (INPUT ONLY)
    /* 90  */   {XMC_GPIO_PORT14, 7},   // A7 / AN2_2GO_1 - ADC Input   P14.7 (INPUT ONLY)
    /* 91  */   {XMC_GPIO_PORT14, 5},   // A5 - ADC Input / SCL         P14.5 (Hardwired to SCL)
    /* 92  */   {XMC_GPIO_PORT14, 3},   // A3 - ADC Input               P14.3 (INPUT ONLY)
    /* 93  */   {XMC_GPIO_PORT15, 3},   // A13 - ADC Input              P15.3 (INPUT ONLY)
    /* 94  */   {XMC_GPIO_PORT14, 9}    // A15 / DAC 1 Output           P14.9
    };
const uint8_t GND = ( sizeof( mapping_port_pin ) / sizeof( XMC_PORT_PIN_t ) );
const uint8_t NUM_DIGITAL = ( sizeof( mapping_port_pin ) / sizeof( XMC_PORT_PIN_t ) );;

const XMC_PIN_INTERRUPT_t mapping_interrupt[] =
    {
    /* 0  */    {CCU40, CCU40_CC43, 3, 0, CCU40_IN3_P1_0},
    /* 1  */    {CCU42, CCU42_CC40, 0, 1, CCU42_IN0_P3_6}
    };
const uint8_t NUM_INTERRUPT = ( sizeof( mapping_interrupt ) / sizeof( XMC_PIN_INTERRUPT_t ) );

/* Mapping of Arduino Pins to PWM4 channels as pin and index in PWM4 channel
   mapping array XMC_PWM4_t mapping_pwm4[]
   last entry 255 for both parts.
   Putting both parts in array means if a PWM4 channel gets reassigned for
   another function later a gap in channel numbers will not mess things up */
const uint8_t mapping_pin_PWM4[][ 2 ] = {
                                        { 3, 0 },   // PWM0
                                        { 5, 1 },   // PWM1
                                        { 6, 2 },   // PWM2
                                        { 11, 3 },  // PWM5
                                        { 27, 4 },  // PWM
                                        { 28, 5 },  // PWM
                                        { 57, 6 },  // PWM
                                        { 58, 7 },  // PWM
                                        { 255, 255 } };

/* Configurations of PWM channels for CCU4 type */
XMC_PWM4_t mapping_pwm4[] =
    {
    {CCU42, CCU42_CC40, 0, mapping_port_pin[3], P3_6_AF_CCU42_OUT0,  XMC_CCU4_SLICE_PRESCALER_64, PWM4_TIMER_PERIOD, DISABLED}, // PWM disabled  3  P3.6
    {CCU42, CCU42_CC43, 3, mapping_port_pin[5], P3_3_AF_CCU42_OUT3,  XMC_CCU4_SLICE_PRESCALER_64, PWM4_TIMER_PERIOD, DISABLED}, // PWM disabled  5  P3.3
    {CCU42, CCU42_CC42, 2, mapping_port_pin[6], P3_4_AF_CCU42_OUT2,  XMC_CCU4_SLICE_PRESCALER_64, PWM4_TIMER_PERIOD, DISABLED}, // PWM disabled  6  P3.4

    //additional pwm outputs starting here
    {CCU41, CCU41_CC41, 1, mapping_port_pin[27], P2_4_AF_CCU41_OUT1, XMC_CCU4_SLICE_PRESCALER_64, PWM4_TIMER_PERIOD, DISABLED}, // PWM disabled  27   P2.4
    {CCU41, CCU41_CC43, 3, mapping_port_pin[28], P2_2_AF_CCU41_OUT3, XMC_CCU4_SLICE_PRESCALER_64, PWM4_TIMER_PERIOD, DISABLED}, // PWM disabled  28   P2.2
    {CCU41, CCU41_CC42, 2, mapping_port_pin[57], P2_3_AF_CCU41_OUT2, XMC_CCU4_SLICE_PRESCALER_64, PWM4_TIMER_PERIOD, DISABLED}, // PWM disabled  57   P2.3
    {CCU41, CCU41_CC41, 0, mapping_port_pin[58], P2_5_AF_CCU41_OUT0, XMC_CCU4_SLICE_PRESCALER_64, PWM4_TIMER_PERIOD, DISABLED}, // PWM disabled  58   P2.5
    };
const uint8_t NUM_PWM4 = ( sizeof( mapping_pwm4 ) / sizeof( XMC_PWM4_t ) );

/* Mapping in same manner as PWM4 for PWM8 channels */
const uint8_t mapping_pin_PWM8[][ 2 ] = {
                                        { 9,  0 },  // PWM3
                                        { 10, 1 },  // PWM4
                                        { 26, 2 },  // PWM
                                        { 29, 3 },  // PWM
                                        { 30, 4 },  // PWM
                                        { 54, 5 },  // PWM
                                        { 55, 6 },  // PWM
                                        { 59, 7 },  // PWM
                                        { 86, 8 },  // PWM
                                        { 255, 255 } };

/* Configurations of PWM channels for CCU8 type */
XMC_PWM8_t mapping_pwm8[] =
    {
    {CCU80, CCU80_CC83, 3, XMC_CCU8_SLICE_COMPARE_CHANNEL_2, mapping_port_pin[9],  P0_11_AF_CCU80_OUT31, XMC_CCU8_SLICE_PRESCALER_64, PWM8_TIMER_PERIOD, DISABLED}, // PWM disabled  9  P0.11
    {CCU80, CCU80_CC80, 0, XMC_CCU8_SLICE_COMPARE_CHANNEL_2, mapping_port_pin[10],  P0_2_AF_CCU80_OUT01, XMC_CCU8_SLICE_PRESCALER_64, PWM8_TIMER_PERIOD, DISABLED}, // PWM disabled  10 P0.2

    //additional pwm outputs starting here
    {CCU80, CCU80_CC80, 0, XMC_CCU8_SLICE_COMPARE_CHANNEL_1, mapping_port_pin[55], P2_7_AF_CCU80_OUT03, XMC_CCU8_SLICE_PRESCALER_64, PWM8_TIMER_PERIOD, DISABLED},  // PWM disabled  55 P2.7
    {CCU80, CCU80_CC81, 1, XMC_CCU8_SLICE_COMPARE_CHANNEL_1, mapping_port_pin[86], P0_9_AF_CCU80_OUT12,  XMC_CCU8_SLICE_PRESCALER_64, PWM8_TIMER_PERIOD, DISABLED}, // PWM disabled  86 P0.9
    {CCU80, CCU80_CC81, 1, XMC_CCU8_SLICE_COMPARE_CHANNEL_2, mapping_port_pin[30], P2_6_AF_CCU80_OUT13,  XMC_CCU8_SLICE_PRESCALER_64, PWM8_TIMER_PERIOD, DISABLED}, // PWM disabled  30 P2.6
    {CCU80, CCU80_CC82, 2, XMC_CCU8_SLICE_COMPARE_CHANNEL_1, mapping_port_pin[59], P2_9_AF_CCU80_OUT22,  XMC_CCU8_SLICE_PRESCALER_64, PWM8_TIMER_PERIOD, DISABLED}, // PWM disabled  59 P2.9
    {CCU80, CCU80_CC83, 3, XMC_CCU8_SLICE_COMPARE_CHANNEL_1, mapping_port_pin[26], P2_8_AF_CCU80_OUT32,  XMC_CCU8_SLICE_PRESCALER_64, PWM8_TIMER_PERIOD, DISABLED}, // PWM disabled  26 P2.8
    {CCU81, CCU81_CC80, 0, XMC_CCU8_SLICE_COMPARE_CHANNEL_1, mapping_port_pin[54], P5_7_AF_CCU81_OUT02, XMC_CCU8_SLICE_PRESCALER_64, PWM8_TIMER_PERIOD, DISABLED},  // PWM disabled  54 P5.7
    {CCU81, CCU81_CC82, 1, XMC_CCU8_SLICE_COMPARE_CHANNEL_2, mapping_port_pin[29], P2_0_AF_CCU81_OUT21,  XMC_CCU8_SLICE_PRESCALER_64, PWM8_TIMER_PERIOD, DISABLED}  // PWM disabled  29 P2.0
/*  {CCU81, CCU81_CC81, 1, XMC_CCU8_SLICE_COMPARE_CHANNEL_2, mapping_port_pin[82], P5_5_AF_CCU81_OUT12,  XMC_CCU8_SLICE_PRESCALER_64, PWM8_TIMER_PERIOD, DISABLED}, // PWM disabled  82 P5.5
    {CCU81, CCU81_CC82, 2, XMC_CCU8_SLICE_COMPARE_CHANNEL_2, mapping_port_pin[81], P5_3_AF_CCU81_OUT22,  XMC_CCU8_SLICE_PRESCALER_64, PWM8_TIMER_PERIOD, DISABLED}  // PWM disabled  81 P5.3*/
    };
const uint8_t NUM_PWM8 = ( sizeof( mapping_pwm8 ) / sizeof( XMC_PWM8_t ) );
const uint8_t NUM_PWM  = ( sizeof( mapping_pwm4 ) / sizeof( XMC_PWM4_t ) )
                        + ( sizeof( mapping_pwm8 ) / sizeof( XMC_PWM8_t ) );

/* Analog Pin mappings and configurations */
#ifdef DAC
const uint8_t mapping_pin_DAC[][ 2 ] = {
                                        { 61, 0 },
                                        { 94, 1 },
                                        { 255, 255 } };

/* Analog Pin mappings and configurations */
XMC_ARD_DAC_t mapping_dac[] =
    {
    {XMC_DAC0, 1, 12},
    {XMC_DAC0, 0, 12}
    };
const uint8_t NUM_ANALOG_OUTPUTS = ( sizeof( mapping_dac ) / sizeof( XMC_ARD_DAC_t ) );
#endif

XMC_ADC_t mapping_adc[] =
    {
    //Result reg numbers are now equal to channel numbers
    {VADC, 0, VADC_G0, 0, 0, DISABLED},
    {VADC, 1, VADC_G0, 0, 1, DISABLED},
    {VADC, 2, VADC_G1, 1, 2, DISABLED},
    {VADC, 3, VADC_G1, 1, 3, DISABLED},
    {VADC, 0, VADC_G2, 2, 0, DISABLED},
    {VADC, 1, VADC_G2, 2, 1, DISABLED},
    //Additional ADC channels starting here
    {VADC, 6, VADC_G2, 2, 6, DISABLED},
    {VADC, 5, VADC_G2, 2, 5, DISABLED},
    {VADC, 3, VADC_G2, 2, 3, DISABLED},
    {VADC, 7, VADC_G1, 1, 7, DISABLED},
    {VADC, 5, VADC_G1, 1, 5, DISABLED},
    {VADC, 7, VADC_G0, 0, 7, DISABLED},
    {VADC, 7, VADC_G3, 3, 7, DISABLED},
    {VADC, 1, VADC_G1, 1, 1, DISABLED},
    {VADC, 0, VADC_G1, 1, 0, DISABLED},
    {VADC, 6, VADC_G3, 3, 6, DISABLED},
    {VADC, 6, VADC_G0, 0, 6, DISABLED},
    {VADC, 4, VADC_G1, 1, 4, DISABLED},
    };
const uint8_t NUM_ANALOG_INPUTS = ( sizeof( mapping_adc ) / sizeof( XMC_ADC_t ) );

/*
 * UART objects
 *
 * See many XMC1x00 pins_arduino.h for proper way to handle HOSTPC
 * NUM_SERIAL defines number of PHYSICAL ports NOT configurations
 */
RingBuffer rx_buffer_0;
RingBuffer tx_buffer_0;
#if (NUM_SERIAL > 1)
RingBuffer rx_buffer_1;
RingBuffer tx_buffer_1;
#endif

#ifdef SERIAL_HOSTPC
XMC_UART_t XMC_UART_0 =
  {
  .channel              = XMC_UART1_CH0,
  .rx                   = { .port = (XMC_GPIO_PORT_t*)PORT0_BASE,
                            .pin  = (uint8_t)5
                          },
  .rx_config            = { .mode = XMC_GPIO_MODE_INPUT_TRISTATE,
                            .output_level     = XMC_GPIO_OUTPUT_LEVEL_HIGH,
                            .output_strength  = XMC_GPIO_OUTPUT_STRENGTH_STRONG_SOFT_EDGE
                          },
  .tx                   = { .port = (XMC_GPIO_PORT_t*)PORT1_BASE,
                            .pin  = (uint8_t)15
                          },
  .tx_config            = { .mode = (XMC_GPIO_MODE_t) XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT4,
                            .output_level     = XMC_GPIO_OUTPUT_LEVEL_HIGH,
                            .output_strength  = XMC_GPIO_OUTPUT_STRENGTH_STRONG_SOFT_EDGE
                          },
  .input_source_dx0     = (XMC_USIC_INPUT_t)USIC1_C0_DX0_P0_5,
  .input_source_dx1     = XMC_INPUT_INVALID,
  .input_source_dx2     = XMC_INPUT_INVALID,
  .input_source_dx3     = XMC_INPUT_INVALID,
  .irq_num              = USIC1_0_IRQn,
  .irq_service_request  = 0
  };

// Debug port
HardwareSerial Serial( &XMC_UART_0, &rx_buffer_0, &tx_buffer_0 );

#elif SERIAL_ONBOARD
XMC_UART_t XMC_UART_0 =
  {
  .channel              = XMC_UART1_CH0,
  .rx                   = { .port = (XMC_GPIO_PORT_t*)PORT2_BASE,
                            .pin  = (uint8_t)15
                          },
  .rx_config            = { .mode = XMC_GPIO_MODE_INPUT_TRISTATE,
                            .output_level     = XMC_GPIO_OUTPUT_LEVEL_HIGH,
                            .output_strength  = XMC_GPIO_OUTPUT_STRENGTH_STRONG_SOFT_EDGE
                          },
  .tx                   = { .port = (XMC_GPIO_PORT_t*)PORT2_BASE,
                            .pin  = (uint8_t)14
                          },
  .tx_config            = { .mode = (XMC_GPIO_MODE_t) XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT2,
                            .output_level     = XMC_GPIO_OUTPUT_LEVEL_HIGH,
                            .output_strength  = XMC_GPIO_OUTPUT_STRENGTH_STRONG_SOFT_EDGE
                          },
  .input_source_dx0     = (XMC_USIC_INPUT_t)USIC1_C0_DX0_P2_15,
  .input_source_dx1     = XMC_INPUT_INVALID,
  .input_source_dx2     = XMC_INPUT_INVALID,
  .input_source_dx3     = XMC_INPUT_INVALID,
  .irq_num              = USIC0_5_IRQn,
  .irq_service_request  = 0
   };

// Debug port
HardwareSerial Serial( &XMC_UART_0, &rx_buffer_0, &tx_buffer_0 );
#endif

// Serial Interrupt and event handling
#ifdef __cplusplus
extern "C" {
#endif
void serialEventRun( );
void serialEvent( ) __attribute__((weak));
void serialEvent1( ) __attribute__((weak));


void serialEventRun( )
{
if( serialEvent )
  {
  if( Serial.available( ) )
    serialEvent( );
  }
#if (NUM_SERIAL > 1)
if( serialEvent1 )
  {
  if( Serial1.available( ) )
    serialEvent1( );
  }
#endif
}


void USIC1_0_IRQHandler( )
{
Serial.IrqHandler( );
}

#if (NUM_SERIAL > 1)
void USIC0_5_IRQHandler( void )
{
Serial1.IrqHandler();
}
#endif

#ifdef __cplusplus
}
#endif
#endif /* ARDUINO_MAIN*/

#ifdef __cplusplus
extern HardwareSerial Serial;
#if (NUM_SERIAL > 1)
extern HardwareSerial Serial1;
#endif
#endif  /* cplusplus */

#endif
