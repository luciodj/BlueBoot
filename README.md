# BlueBoot 

A Bootloader for the PIC16F1 using a Bluetooth Click© Board.

Need:

* Device: PIC16F1709 (or other PIC16F1 in 20-pin DIP and a UART)
* RN41 based [Bluetooth Click© Board](http://www.mikroe.com/click/bluetooth/)
* Board: PICDEM(tm) Low Pin Count + mikroBUS connector = [Simplicity](https://github.com/luciodj/Simplicity) 
* Debugger: PICkit(tm) 3

## The Basic Idea
1. Add a [MikroBUS](http://www.mikroe.com/mikrobus/) connector to the LPC board 
2. Connect an [Bluetooth Click board](http://www.mikroe.com/click/bluetooth//) 
3. Launch MPLAB X and MPLAB Code Configurator to quickly initialise all the peripherals
4. Enter Boot mode (Power up Simplicity while pressing the SW1 button) -> LED2 on
5. Pair device (Bluetooth preferences) 
6. Launch ./BlueBoot blinky.hex  -> LED1 turns on, board is programmed
7. See the blinky app running (LED1 blinking)

## A bit more detail
* BlueBoot is a "low side" bootloader, meaning it uses a small (512 words) segment of code at the beginning of the program memory space (reset vector). 
* The target application (blinky.X) must be "built" accordingly by instructing the compiler to add an offset (0x200) to the reset and interrupt vectors. This can be accomplished simply by:
  * Open the "Project Properties" in the MPLAB X IDE and select the "XC8 linker options". 
    * In the "Options Categories", select "Additional Options" 
      * In the "Code Offset" field type: 0x200
* Note, 512 words is the size of the smallest code protection window of these small PIC devices, so the bootloader can be code-protected while the application space is left open.

## Further Development Ideas
* Port to [Curiosity Board](http://www.microchip.com/Developmenttools/ProductDetails.aspx?PartNO=DM164137)
* Add checksums 
* Pair with different ID while in bootloader mode
* ...

## Related Projects and Demos
* Check the {Rocket](https://github.com/luciodj/Rocket) projects for more demos like this one using Mplab Code Configurator and the MikoE CLick(tm) boards.
* Check the [Simplicity](https://github.com/luciodj/Simplicity) project for more demos like this one using the MPLAB Code Configurator and the MikroE Click(tm) boards.
