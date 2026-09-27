# obstacle avoider bot 

building an arduino car with an l298n motor driver and hc-sr04 sensor. 

current status: massive refactor. ripped out all the delay() functions and replaced them with a millis() state machine. using delay() pauses the entire microcontroller, which meant the bot was literally blind to new obstacles while it was executing a turn or reverse. now it evaluates sensor data continuously without freezing. 

also added a 30ms timeout to pulseIn() inside the getDistance() function, as default pulseIn will freeze the board for a full second if a sound wave gets lost.

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

next step is adding an overall schematic, final wiring map, and deployment instructions so someone else can build this.