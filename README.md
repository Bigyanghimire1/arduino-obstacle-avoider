# obstacle avoider bot 

building an arduino car with an l298n motor driver and hc-sr04 sensor. 

current status: wired up both the left and right motors. tested them to run forward and backward in sync. 

pins for left motor:
enA -> 9
in1 -> 8
in2 -> 7

pins for right motor:
enB -> 10
in3 -> 6
in4 -> 5

note: if your bot spins in a circle when trying to go forward, it means the motors are mounted mirrored. just swap the HIGH and LOW states for the right motor in the code to fix it. 

next step is abstracting these messy digitalWrite chunks into clean moveForward() and stop() functions.