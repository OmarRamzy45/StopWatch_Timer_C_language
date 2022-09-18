# StopWatch 
The image below shows the circuit of the stopwatch. It consists of a 7-segment connected to Atmega32 using multiplexed technique.
A 7447 Decoder was used to control the numbers displayed on the 6 digits of the 7-segment. and three push buttons were connected to
generate interrupts to pause, resume and reset the stopwatch! 

![Screenshot_2](https://user-images.githubusercontent.com/100040470/190920134-c5a85554-f4bb-40b7-9d4d-8f698e7dfa29.png)

## Circuit Specifications:
- ATmega32 Microcontroller with frequency 1Mhz.
- Timer1 in ATmega32 set to CTC mode.
- six Common Anode 7-segments.
- 7447 decoder 4-pins connected to the first 4-pins in PORTC.
- First 6-pins in PORTA as the enable/disable pins for the six 7-segments.
- Configure External Interrupt INT0 with falling edge. Connect a push button with the internal pull-up resistor.
If a falling edge is detected the Stop Watch time should be reset
- Configure External Interrupt INT1 with raising edge. Connect a push button with the external pull-down resistor.
If a raising edge is detected the Stop Watch time should be paused.
- Configure External Interrupt INT2 with falling edge. Connect a push button with the internal pull-up resistor.
If a falling edge is detected the Stop Watch time should be resumed.

That's All. Hope you found this useful. Thank you for reading :)
