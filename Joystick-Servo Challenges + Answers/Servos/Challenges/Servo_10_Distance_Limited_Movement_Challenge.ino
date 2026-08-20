// ============================================================
//  Servo -- Moving Until an Object Gets Close
//  Source: Day 4 (Kitara-James), Slide 11 (getDistance)
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
  delayMicroseconds(__);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(__);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(__, __, __);
  int dist = duration * __ / __;
  return dist;
}

void setup() {
  myservo.attach(PIN_servo);
  pinMode(TRIG_PIN, __);
  pinMode(ECHO_PIN, __);
}

void loop() {
  // ############################################################
  //  CHALLENGE: IF getDistance() IS GREATER THAN 10cm, KEEP
  //  MOVING THE SERVO (WRAP pos BACK TO 0 AFTER 180)
  // ############################################################
  if (getDistance() > __) {
    pos++;
    if (pos > 180) {
      pos = __;
    }
    myservo.write(pos);
  }
  delay(50);
}
