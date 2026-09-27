// left motor
int enA = 9;
int in1 = 8;
int in2 = 7;

// right motor
int enB = 10;
int in3 = 6;
int in4 = 5;

// ultrasonic sensor
int trigPin = 11;
int echoPin = 12;

// obstacle threshold
int safeDistance = 20; // cm

// state machine for non-blocking timing
enum State { FORWARD, HALT, REVERSE, TURN };
State currentState = FORWARD;
unsigned long stateStartTime = 0;

void setup() {
  Serial.begin(9600);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  analogWrite(enA, 150); 
  analogWrite(enB, 150);
}

void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveBackward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}**motor_with_sensor.ino**
```cpp
// left motor
int enA = 9;
int in1 = 8;
int in2 = 7;

// right motor
int enB = 10;
int in3 = 6;
int in4 = 5;

// ultrasonic sensor
int trigPin = 11;
int echoPin = 12;

int safeDistance = 20; // cm

// non-blocking timer variables
unsigned long previousMillis = 0;
int interval = 0; 

// state machine tracker
enum BotState { DRIVING, STOPPING, REVERSING, TURNING };
BotState currentState = DRIVING;

void setup() {
  Serial.begin(9600);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  analogWrite(enA, 150); 
  analogWrite(enB, 150);
}

void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveBackward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // added a 30000 microsecond (30ms) timeout so pulseIn doesnt block the loop if no echo returns
  long duration = pulseIn(echoPin, HIGH, 30000); 
  
  if (duration == 0) {
    return 100; 
  }
  return duration * 0.034 / 2;
}

void loop() {
  unsigned long currentMillis = millis();
  int currentDistance = getDistance();

  // switch-case state machine for non-blocking logic
  switch (currentState) {
    case DRIVING:
      moveForward();
      if (currentDistance < safeDistance) {
        currentState = STOPPING;
        previousMillis = currentMillis;
        interval = 300; // wait 300ms in STOPPING state
      }
      break;

    case STOPPING:
      stopMotors();
      if (currentMillis - previousMillis >= interval) {
        currentState = REVERSING;
        previousMillis = currentMillis;
        interval = 500; // wait 500ms in REVERSING state
      }
      break;

    case REVERSING:
      moveBackward();
      if (currentMillis - previousMillis >= interval) {
        currentState = TURNING;
        previousMillis = currentMillis;
        interval = 600; // wait 600ms in TURNING state
      }
      break;

    case TURNING:
      turnRight();
      if (currentMillis - previousMillis >= interval) {
        currentState = DRIVING; // back to default state
      }
      break;
  }
}