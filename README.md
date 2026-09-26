# obstacle avoider bot 

building an arduino car with an l298n motor driver and hc-sr04 sensor. 

current status: hooked up the hc-sr04 ultrasonic sensor. wrote a getDistance() function that uses pulseIn to calculate how far away objects are in cm. i commented out the motor movement in the loop for now just to make sure the sensor numbers look accurate in the serial monitor.

pins for left motor:
enA -> 9
in1 -> 8
in2 -> 7

pins for right motor:
enB -> 10
in3 -> 6
in4 -> 5

pins for sensor:
trig -> 11
echo -> 12

next step is combining both systems: making the car drive forward, but call stopMotors() if the distance drops below a certain threshold.