/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB® Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.10.3
        Device            :  PIC16F1709
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.34
        MPLAB             :  MPLAB X 2.26
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

#include "mcc_generated_files/mcc.h"

#define APP_START     0x200

#define cmdESCAPE       '%'
#define cmdConnect      'C'
#define cmdDisconnect   'D'
#define cmdREBOOT       'R'
#define cmdWRITE        'W'
#define cmdACK          'A'

// globals
uint16_t data[32];
uint16_t add;
//uint8_t  checksum;

#define putch   EUSART_Write
#define getch   EUSART_Read

inline void runApp(void) { // ljmp to application
#asm
    PAGESEL APP_START
            goto APP_START
#endasm
}

void interrupt isr(void) {
#asm
    PAGESEL APP_START
            goto (APP_START + 4)
#endasm
}

void delay(uint8_t times) { // multiples of 16ms
    while (times-- > 0)
        while (!TMR0_HasOverflowOccured());
}

void RN41_SetEscape(void) {
    delay(30);
//    putch('$');    putch('$');    putch('$');     putch('\n'); // enter cmd mode
    puts("$$$");
    delay(30);
//        putch( 'S'); putch('O'); putch(','); putch(cmdESCAPE); putch('\n'); // enter cmd mode
    puts("SO,%"); // enable connection notifications with escape "%"
    delay(30);
//    putch('R'); putch(','); putch('1'); putch('\n'); // reboot to make changes effective
    puts("R,1");
    delay(30);
}

/**
 * Send a word (lsb first)
 * @param w
 */
void putw(uint16_t w) {
    putch(w); // lsb
    putch(w >> 8); // msb
}

/**
 *  Receive a word (lsb First)
 *  @return unsigned 16-bit value
 */
uint16_t getw(void) {

    union {
        uint8_t byte[2];
        uint16_t word;
    } r;

    r.byte[0] = getch();
    r.byte[1] = getch();
    return r.word;
} // getw

/**
 * Receive a block of data (words)
 */
void get_data(void) {
    uint8_t count = 32;
    uint16_t *pdata = data;
    while (count-- > 0) {
        *pdata++ = getw();
    }
} // get_data

/**
 * unlock Flash Sequence
 */
void _unlock(void) {
#asm
    BANKSEL PMCON2
    MOVLW 0x55
    MOVWF PMCON2 & 0x7F
    MOVLW 0xAA
    MOVWF PMCON2 & 0x7F
    BSF PMCON1 & 0x7F,1     ;set WR bit
    NOP
    NOP
#endasm
} // unlock

/**
 * Write a block of data to flash
 */
void write(void) {
    uint8_t count = 32;
    uint16_t* pdata = data;

    // 1. disable interrupts (remember setting)
    char temp = INTCONbits.GIE;
    INTCONbits.GIE = 0;

    // 2. perform a row erase
    PMADR = add;
    PMCON1bits.CFGS = 0; // de-select the configuration space
    PMCON1bits.WREN = 1; // enable flash memory write/erase
    PMCON1bits.FREE = 1; // first perform an erase
    _unlock(); // perform unlock and set WR sequence

    // 3. perform a row write
    PMCON1bits.FREE = 0; // next prepare for write operations
    PMCON1bits.LWLO = 1; // 1 = latch
    while (count-- > 1) {
        PMADR = add++;
        PMDAT = *pdata++; // load latches
        _unlock(); // perform unlock and set WR sequence

    }
    // write last word and entire row
    PMCON1bits.LWLO = 0; // 0 = write row
    PMDAT = *pdata++; // write row
    _unlock(); // perform unlock and set WR sequence

    // 4. restore interrupts
    if (temp)
        INTCONbits.GIE = 1;
}

void main(void) {
    bool connected = false;
    char c;

    SYSTEM_Initialize();

    if (SW1_GetValue()) // check if bootloader entry requested
        runApp();

    LED1_SetHigh(); // show entry into bootloader waiting for connection
    while (!SW1_GetValue()); // ensure button released
    RN41_SetEscape();

    while (1) {
        LED0_LAT = connected; // report status
        c = getch();
        // capture escape notifications
        if (cmdESCAPE == c) {
            c = getch(); // %Connected - %Disconnected
            connected = (cmdConnect == c); // toggle status accordingly
        } else {
            switch (c) {
                case cmdREBOOT: // run application
                    runApp();
                    break;
                case cmdWRITE: // erase/write a row of 32 words
                    add = getw(); // get address (word)
                    get_data();
                    write();
                    putch(cmdACK);
                    break;
                default:
                    break;
            } // switch
        }
    } // main loop
}
