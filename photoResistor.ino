#include <Servo.h>
Servo myservo;
int button = 2;
int val;
int photocell;
void setup() {
  myservo.attach(9);
  pinMode(button, INPUT);
  Serial.begin(9600);
}
void loop() {
  photocell = analogRead(A0);
  photocell = map(photocell, 0, 1023, 0, 180);
  val = digitalRead(button);
  if (val == 1) {
    Serial.println(val);
    myservo.write(70);
    delay(10);
  }
  else {
    myservo.write(photocell);
    delay(10);
    Serial.println(photocell);
  }
  delay(10);
}
