# obstacle avoider bot 

building an arduino car with an l298n motor driver and hc-sr04 sensor. 

current status: renamed the main sketch file to match the repository name for arduino ide compatibility. added differential steering logic (turnLeft and turnRight). the chassis can now spin in place by driving the wheels in opposite directions.

pins for left motor:
enA -> 9
in1 -> 8
in2 -> 7

pins for right motor:
enB -> 10
in3 -> 6
in4 -> 5

next step is adding the hc-sr04 ultrasonic sensor and printing distance readings to the serial monitor.