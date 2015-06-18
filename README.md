# Hello Bluetooth Click© board

Playing with the RN41 Bluetooth Click Board.

Need:

* Device: PIC16F1709 (or other PIC16F1 in 20-pin DIP and a UART)
* Board: PICDEM(tm) Low Pin Count + mikroBUS connector = [Simplicity](https://github.com/luciodj/Simplicity) 
* Debugger: PICkit(tm) 3

## The Basic Idea
1. Add a [MikroBUS](http://www.mikroe.com/mikrobus/) connector to the LPC board 
2. Connect an [Bluetooth Click board](http://www.mikroe.com/click/bluetooth//) 
3. Launch MPLAB X and MPLAB Code Configurator to quickly initialise all the peripherals
4. Pair device (Bluetooth preferences) -> LED0 turns on
5. Connect terminal (CoolTerm) 
6. Push SW1 to say "Hello"!


## Further Development Ideas
* Add commands to turn on/off LEDs
* Add commands to Control Servo 
* ...

## Related Projects and Demos

* Check the [Simplicity](https://github.com/luciodj/Simplicity) project for more demo like this using the MPLAB Code Configurator and the MikroElektronika Click(tm) boards.
