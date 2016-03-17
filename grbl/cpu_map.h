/*
  cpu_map.h - CPU and pin mapping configuration file
  Part of Grbl

  Copyright (c) 2012-2015 Sungeun K. Jeon

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

/* The cpu_map.h files serve as a central pin mapping selection file for different processor
   types, i.e. AVR 328p or AVR Mega 2560. Each processor has its own pin mapping file.
   (i.e. cpu_map_atmega328p.h)  Grbl officially supports the Arduino Uno, but the 
   other supplied pin mappings are supplied by users, so your results may vary. */

// NOTE: With new processors, only add the define name and filename to use.

#ifndef cpu_map_h
#define cpu_map_h


#ifdef CPU_MAP_ATMEGA328P // (Arduino Uno) Officially supported by Grbl.
  #include "cpu_map_atmega328p.h"
#endif

#ifdef CPU_MAP_ATMEGA2560 // (Arduino Mega 2560) Working @EliteEng
  #include cpu_map_atmega2560.h"
#endif


#ifdef CPU_MAP_ATMEGA2560_6AXIS // (Arduino Mega 2560 Six Axis) By Denhv

  // Serial port pins
  #define SERIAL_RX USART0_RX_vect
  #define SERIAL_UDRE USART0_UDRE_vect

  // Increase Buffers to make use of extra SRAM
  //#define RX_BUFFER_SIZE		256
  //#define TX_BUFFER_SIZE		128
  //#define BLOCK_BUFFER_SIZE	36
  //#define LINE_BUFFER_SIZE	100

  // Define step pulse output pins. NOTE: All step bit pins must be on the same port.
  #define STEP_DDR      DDRA
  #define STEP_PORT     PORTA
  #define STEP_PIN      PINA
  #define X_STEP_BIT        0 // MEGA2560 Digital Pin 22
  #define Y_STEP_BIT        2 // MEGA2560 Digital Pin 24
  #define Z_STEP_BIT        4 // MEGA2560 Digital Pin 26
  #define A_STEP_BIT        1 // MEGA2560 Digital Pin 23
  #define B_STEP_BIT        3 // MEGA2560 Digital Pin 25
  #define C_STEP_BIT        5 // MEGA2560 Digital Pin 27
  
  #define STEP_MASK ((1<<X_STEP_BIT)|(1<<Y_STEP_BIT)|(1<<Z_STEP_BIT)|(1<<A_STEP_BIT)|(1<<B_STEP_BIT)|(1<<C_STEP_BIT)) // All step bits

  // Define step direction output pins. NOTE: All direction pins must be on the same port.
  #define DIRECTION_DDR      DDRC
  #define DIRECTION_PORT     PORTC
  #define DIRECTION_PIN      PINC
  #define X_DIRECTION_BIT   7 // MEGA2560 Digital Pin 30
  #define Y_DIRECTION_BIT   5 // MEGA2560 Digital Pin 32
  #define Z_DIRECTION_BIT   3 // MEGA2560 Digital Pin 34
  #define A_DIRECTION_BIT   6 // MEGA2560 Digital Pin 31
  #define B_DIRECTION_BIT   4 // MEGA2560 Digital Pin 33
  #define C_DIRECTION_BIT   2 // MEGA2560 Digital Pin 35
  
  #define DIRECTION_MASK ((1<<X_DIRECTION_BIT)|(1<<Y_DIRECTION_BIT)|(1<<Z_DIRECTION_BIT)|(1<<A_DIRECTION_BIT)|(1<<B_DIRECTION_BIT)|(1<<C_DIRECTION_BIT)) // All direction bits

  // Define stepper driver enable/disable output pin.
  #define STEPPERS_DISABLE_DDR   DDRG
  #define STEPPERS_DISABLE_PORT  PORTG
  #define STEPPERS_DISABLE_BIT   5 // MEGA2560 Digital Pin 4
  #define STEPPERS_DISABLE_MASK (1<<STEPPERS_DISABLE_BIT)

  // NOTE: All limit bit pins must be on the same port
  #define LIMIT_DDR       DDRK
  #define LIMIT_PORT      PORTK
  #define LIMIT_PIN       PINK
  #define X_LIMIT_BIT     0 // MEGA2560 Analog Pin 8
  #define Y_LIMIT_BIT     1 // MEGA2560 Analog Pin 9
  #define Z_LIMIT_BIT     2 // MEGA2560 Analog Pin 10
  #define A_LIMIT_BIT     3 // MEGA2560 Analog Pin 11
  #define B_LIMIT_BIT     4 // MEGA2560 Analog Pin 12
  #define C_LIMIT_BIT     5 // MEGA2560 Analog Pin 13
  
  #define LIMIT_INT       PCIE2  // Pin change interrupt enable pin
  #define LIMIT_INT_vect  PCINT2_vect 
  #define LIMIT_PCMSK     PCMSK2 // Pin change interrupt register
  #define LIMIT_MASK ((1<<X_LIMIT_BIT)|(1<<Y_LIMIT_BIT)|(1<<Z_LIMIT_BIT)|(1<<A_LIMIT_BIT)|(1<<A_LIMIT_BIT)|(1<<A_LIMIT_BIT)) // All limit bits

  // Define spindle enable and spindle direction output pins.
  #define SPINDLE_ENABLE_DDR   DDRE
  #define SPINDLE_ENABLE_PORT  PORTE
  #define SPINDLE_ENABLE_BIT   3 // MEGA2560 Digital Pin 5
  #define SPINDLE_DIRECTION_DDR   DDRH
  #define SPINDLE_DIRECTION_PORT  PORTH
  #define SPINDLE_DIRECTION_BIT   5 // MEGA2560 Digital Pin 8

  // Define flood and mist coolant enable output pins.
  // NOTE: Uno analog pins 4 and 5 are reserved for an i2c interface, and may be installed at
  // a later date if flash and memory space allows.
  #define COOLANT_FLOOD_DDR   DDRH
  #define COOLANT_FLOOD_PORT  PORTH
  #define COOLANT_FLOOD_BIT   3 // MEGA2560 Digital Pin 6
  #ifdef ENABLE_M7 // Mist coolant disabled by default. See config.h to enable/disable.
    #define COOLANT_MIST_DDR   DDRH
    #define COOLANT_MIST_PORT  PORTH
    #define COOLANT_MIST_BIT   4 // MEGA2560 Digital Pin 7
  #endif  

  // Define user-control pinouts (cycle start, reset, feed hold) input pins.
  // NOTE: All pinouts pins must be on the same port and not on a port with other input pins (limits).
  #define PINOUT_DDR       DDRB
  #define PINOUT_PIN       PINB
  #define PINOUT_PORT      PORTB
  #define PIN_RESET        4  // MEGA2560 Digital Pin 10
  #define PIN_FEED_HOLD    5  // MEGA2560 Digital Pin 11
  #define PIN_CYCLE_START  6  // MEGA2560 Digital Pin 12
  #define PINOUT_INT       PCIE0  // Pin change interrupt enable pin
  #define PINOUT_INT_vect  PCINT0_vect
  #define PINOUT_PCMSK     PCMSK0 // Pin change interrupt register
  #define PINOUT_MASK ((1<<PIN_RESET)|(1<<PIN_FEED_HOLD)|(1<<PIN_CYCLE_START))

  // Define probe switch input pin.
  #define PROBE_DDR       DDRK
  #define PROBE_PIN       PINK
  #define PROBE_PORT      PORTK
  #define PROBE_BIT       6  // MEGA2560 Analog Pin 14
  #define PROBE_MASK      (1<<PROBE_BIT)

  // Start of PWM & Stepper Enabled Spindle
  #ifdef VARIABLE_SPINDLE
    // Advanced Configuration Below You should not need to touch these variables
    // Set Timer up to use TIMER2B which is attached to Digital Pin 9
    #define TCCRA_REGISTER		TCCR2A
    #define TCCRB_REGISTER		TCCR2B
    #define OCR_REGISTER		OCR2B

    #define COMB_BIT			COM2B1
    #define WAVE0_REGISTER		WGM20
    #define WAVE1_REGISTER		WGM21
    #define WAVE2_REGISTER		WGM22
    #define WAVE3_REGISTER		WGM23

    #define SPINDLE_PWM_DDR		DDRH
    #define SPINDLE_PWM_PORT    PORTH
    #define SPINDLE_PWM_BIT		6 // MEGA2560 Digital Pin 9 <--- DO NOT TOUCH
#endif // End of VARIABLE_SPINDLE

#endif

/* 
#ifdef CPU_MAP_CUSTOM_PROC
  // For a custom pin map or different processor, copy and edit one of the available cpu
  // map files and modify it to your needs. Make sure the defined name is also changed in
  // the config.h file.
#endif
*/

#endif
