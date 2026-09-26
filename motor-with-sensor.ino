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
  
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  
  // if sensor reads 0 (error), return a high number so it doesnt false trigger
  if (distance == 0) {
    return 100; 
  }
  return distance;
}

void loop() {
  int currentDistance = getDistance();
  
  Serial.print("Distance: ");
  Serial.print(currentDistance);
  Serial.println(" cm");

  if (currentDistance < safeDistance) {
    // obstacle detected!
    stopMotors();
    delay(300);
    
    // back up a little bit
    moveBackward();
    delay(500);
    
    // turn to avoid it
    turnRight();
    delay(600); 
  } else {
    // path is clear
    moveForward();
  }
  
  delay(50); // small delay to stabilize sensor readings
}