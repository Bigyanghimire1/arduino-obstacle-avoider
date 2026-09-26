int enA = 9;
int in1 = 8;
int in2 = 7;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  // test left motor forward
  analogWrite(enA, 150); // set speed (0-255)
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(2000);

  // brake
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(1000);

  // test reverse
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(2000);

  // brake
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(2000);
}