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
        Product Revision  :  MPLAB� Code Configurator - v2.25.1
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

// get/set LED1 aliases
#define LED1_TRIS               TRISC0
#define LED1_LAT                LATC0
#define LED1_PORT               RC0
#define LED1_WPU                WPUC0
#define LED1_ANS                ANSC0
#define LED1_SetHigh()    do { LATC0 = 1; } while(0)
#define LED1_SetLow()   do { LATC0 = 0; } while(0)
#define LED1_Toggle()   do { LATC0 = ~LATC0; } while(0)
#define LED1_GetValue()         RC0
#define LED1_SetDigitalInput()    do { TRISC0 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISC0 = 0; } while(0)

#define LED1_SetPullup()    do { WPUC0 = 1; } while(0)
#define LED1_ResetPullup()   do { WPUC0 = 0; } while(0)
#define LED1_SetAnalogMode()   do { ANSC0 = 1; } while(0)
#define LED1_SetDigitalMode()   do { ANSC0 = 0; } while(0)

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