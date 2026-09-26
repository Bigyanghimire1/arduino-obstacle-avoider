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

void setup() {
  Serial.begin(9600); // initialize serial monitor for sensor readings

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // set base speed for both motors
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
  // clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // send a 10 microsecond pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // read the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);
  
  // calculate the distance in cm
  int distance = duration * 0.034 / 2;
  return distance;
}

void loop() {
  // motor testing is temporarily commented out to isolate sensor testing
  /*
  moveForward();
  delay(2000);
  stopMotors();
  delay(1000);
  */

  // test sensor
  int currentDistance = getDistance();
  Serial.print("Distance: ");
  Serial.print(currentDistance);
  Serial.println(" cm");
  
  delay(500); // short delay to make the serial monitor readable
}