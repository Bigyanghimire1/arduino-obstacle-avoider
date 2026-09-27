# arduino obstacle avoider bot

finalizing the documentation for the obstacle-avoiding rover. the code uses a non-blocking state machine (millis instead of delay) to keep the ultrasonic sensor polling while the motors are running.

### components used
- arduino uno r3
- l298n motor driver
- hc-sr04 ultrasonic sensor
- 2x dc motors (with standard smart car chassis)
- 18650 battery pack (for motors)
- 9v battery or separate power bank (for arduino logic)

### wiring & pinout
**left motor (via l298n)**
- enA -> pin 9
- in1 -> pin 8
- in2 -> pin 7

**right motor (via l298n)**
- enB -> pin 10
- in3 -> pin 6
- in4 -> pin 5

**hc-sr04 sensor**
- trig -> pin 11
- echo -> pin 12
- vcc -> 5v on arduino
- gnd -> gnd on arduino

### power setup warning
do not try to power the dc motors directly from the arduino's 5v pin. it will fry the board or just keep resetting when the motors draw too much current. 
connect your main battery pack directly to the 12v and gnd terminals on the l298n. you must route a wire from the gnd terminal on the l298n to the arduino gnd so the whole system shares a common ground.

### how to run
1. wire everything up according to the map above.
2. open `motor_with_sensor.ino` in the arduino ide or vs code.
3. compile and upload to your arduino uno.
4. put it on the floor and turn on the battery pack.