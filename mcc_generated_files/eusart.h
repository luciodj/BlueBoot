/**
  EUSART Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    eusart.h

  @Summary
    This is the generated header file for the EUSART driver using MPLAB� Code Configurator

  @Description
    This header file provides APIs for driver for EUSART.
    Generation Information :
        Product Revision  :  MPLAB� Code Configurator - v2.25.2
        Device            :  PIC16F1709
        Driver Version    :  2.00
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

#ifndef _EUSART_H
#define _EUSART_H

/**
  Section: Included Files
 */

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif


    /**
      Section: Macro Declarations
     */

#define EUSART_DataReady  (PIR1bits.RCIF)

    /**
      Section: EUSART APIs
     */

    /**
      @Summary
        Initialization routine that takes inputs from the EUSART GUI.

      @Description
        This routine initializes the EUSART driver.
        This routine must be called before any other EUSART routine is called.

      @Preconditions
        None

      @Param
        None

      @Returns
        None

      @Comment
        Initialize serial port for communication at 115,200Baud redirected to STDIO
     */
    void EUSART_Initialize(void);

    /**
      @Summary
        Read a byte of data from the EUSART.

      @Description
        This routine reads a byte of data from the EUSART.

      @Preconditions
        EUSART_Initialize() function should have been called
        before calling this function. The transfer status should be checked to see
        if the receiver is not empty before calling this function.

      @Param
        None

      @Returns
        A data byte received by the driver.
     */
    uint8_t EUSART_Read(void);

    /**
     @Summary
       Writes a byte of data to the EUSART.

     @Description
       This routine writes a byte of data to the EUSART.

     @Preconditions
       EUSART_Initialize() function should have been called
       before calling this function. The transfer status should be checked to see
       if transmitter is not busy before calling this function.

     @Param
       txData  - Data byte to write to the EUSART

     @Returns
       None
     */
    void EUSART_Write(uint8_t txData);

#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif

#endif  // _EUSART_H
/**
 End of File
 */