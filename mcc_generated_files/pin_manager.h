/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB� Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB� Code Configurator - v2.25.2
        Device            :  PIC16F1709
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.34
        MPLAB             :  MPLAB X v2.35 or v3.00
 */

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 */

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SW1 aliases
#define SW1_TRIS               TRISA2
#define SW1_LAT                LATA2
#define SW1_PORT               RA2
#define SW1_WPU                WPUA2
#define SW1_ANS                ANSA2
#define SW1_SetHigh()    do { LATA2 = 1; } while(0)
#define SW1_SetLow()   do { LATA2 = 0; } while(0)
#define SW1_Toggle()   do { LATA2 = ~LATA2; } while(0)
#define SW1_GetValue()         RA2
#define SW1_SetDigitalInput()    do { TRISA2 = 1; } while(0)
#define SW1_SetDigitalOutput()   do { TRISA2 = 0; } while(0)

#define SW1_SetPullup()    do { WPUA2 = 1; } while(0)
#define SW1_ResetPullup()   do { WPUA2 = 0; } while(0)
#define SW1_SetAnalogMode()   do { ANSA2 = 1; } while(0)
#define SW1_SetDigitalMode()   do { ANSA2 = 0; } while(0)
// get/set RX aliases
#define RX_TRIS               TRISB5
#define RX_LAT                LATB5
#define RX_PORT               RB5
#define RX_WPU                WPUB5
#define RX_ANS                ANSB5
#define RX_SetHigh()    do { LATB5 = 1; } while(0)
#define RX_SetLow()   do { LATB5 = 0; } while(0)
#define RX_Toggle()   do { LATB5 = ~LATB5; } while(0)
#define RX_GetValue()         RB5
#define RX_SetDigitalInput()    do { TRISB5 = 1; } while(0)
#define RX_SetDigitalOutput()   do { TRISB5 = 0; } while(0)

#define RX_SetPullup()    do { WPUB5 = 1; } while(0)
#define RX_ResetPullup()   do { WPUB5 = 0; } while(0)
#define RX_SetAnalogMode()   do { ANSB5 = 1; } while(0)
#define RX_SetDigitalMode()   do { ANSB5 = 0; } while(0)
// get/set TX aliases
#define TX_TRIS               TRISB7
#define TX_LAT                LATB7
#define TX_PORT               RB7
#define TX_WPU                WPUB7
#define TX_SetHigh()    do { LATB7 = 1; } while(0)
#define TX_SetLow()   do { LATB7 = 0; } while(0)
#define TX_Toggle()   do { LATB7 = ~LATB7; } while(0)
#define TX_GetValue()         RB7
#define TX_SetDigitalInput()    do { TRISB7 = 1; } while(0)
#define TX_SetDigitalOutput()   do { TRISB7 = 0; } while(0)

#define TX_SetPullup()    do { WPUB7 = 1; } while(0)
#define TX_ResetPullup()   do { WPUB7 = 0; } while(0)
// get/set LED0 aliases
#define LED0_TRIS               TRISC0
#define LED0_LAT                LATC0
#define LED0_PORT               RC0
#define LED0_WPU                WPUC0
#define LED0_ANS                ANSC0
#define LED0_SetHigh()    do { LATC0 = 1; } while(0)
#define LED0_SetLow()   do { LATC0 = 0; } while(0)
#define LED0_Toggle()   do { LATC0 = ~LATC0; } while(0)
#define LED0_GetValue()         RC0
#define LED0_SetDigitalInput()    do { TRISC0 = 1; } while(0)
#define LED0_SetDigitalOutput()   do { TRISC0 = 0; } while(0)

#define LED0_SetPullup()    do { WPUC0 = 1; } while(0)
#define LED0_ResetPullup()   do { WPUC0 = 0; } while(0)
#define LED0_SetAnalogMode()   do { ANSC0 = 1; } while(0)
#define LED0_SetDigitalMode()   do { ANSC0 = 0; } while(0)
// get/set LED1 aliases
#define LED1_TRIS               TRISC1
#define LED1_LAT                LATC1
#define LED1_PORT               RC1
#define LED1_WPU                WPUC1
#define LED1_ANS                ANSC1
#define LED1_SetHigh()    do { LATC1 = 1; } while(0)
#define LED1_SetLow()   do { LATC1 = 0; } while(0)
#define LED1_Toggle()   do { LATC1 = ~LATC1; } while(0)
#define LED1_GetValue()         RC1
#define LED1_SetDigitalInput()    do { TRISC1 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISC1 = 0; } while(0)

#define LED1_SetPullup()    do { WPUC1 = 1; } while(0)
#define LED1_ResetPullup()   do { WPUC1 = 0; } while(0)
#define LED1_SetAnalogMode()   do { ANSC1 = 1; } while(0)
#define LED1_SetDigitalMode()   do { ANSC1 = 0; } while(0)

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    GPIO and peripheral I/O initialization
 * @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);

#endif // PIN_MANAGER_H
/**
 End of File
 */