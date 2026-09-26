# obstacle avoider bot 

building an arduino car with an l298n motor driver and hc-sr04 sensor. 

current status: combined the motor and sensor logic for basic obstacle avoidance. the bot now drives forward continuously. if the ultrasonic sensor detects an object closer than 20cm, it slams the brakes, reverses for half a second to get clearance, and spins right to find a new path.

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

note: added a quick failsafe in getDistance() because sometimes cheap hc-sr04 sensors return 0 when they glitch out, which made the car randomly reverse when the path was empty.

next step is refactoring the delay() functions to use millis() so the microcontroller doesn't completely freeze up while waiting.