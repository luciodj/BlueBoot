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
6. Launch ./BlueBoot bliny.hex  -> LED1 turns on, board is programmed
7. See the blinky app running (LED1 blinking)


## Further Development Ideas
* Add checksums 
* Pair with different ID while in bootloader mode
* ...

## Related Projects and Demos

* Check the [Simplicity](https://github.com/luciodj/Simplicity) project for more demo like this using the MPLAB Code Configurator and the MikroElektronika Click(tm) boards.
