// ============================================================
//  Servo -- Moving Until an Object Gets Close
//  Source: Day 4 (Kitara-James), Slide 11 (getDistance),
//  combined with a simple sweep-until-close pattern.
// ============================================================
#include <Servo.h>

#define PIN_servo 3
#define ECHO_PIN 12
#define TRIG_PIN 13

Servo myservo;
int pos = 0;
long duration;

int getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 20000);
  int dist = duration * 0.034 / 2;
  return dist;
}

void setup() {
  myservo.attach(PIN_servo);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  if (getDistance() > 10) {
    pos++;
    if (pos > 180) {
      pos = 0;
    }
    myservo.write(pos);
  }
  delay(50);
}
