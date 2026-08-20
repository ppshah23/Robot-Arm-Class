// ============================================================
//  Joystick -- Mapping to a Servo Angle
//  Source: Day 2 (Kitara-James), Slides 52-53
// ============================================================
#include <Servo.h>

#define JOY_X_PIN A0
#define SERVO_PIN 7

Servo myServo;
int x;
int servoPos;

void setup() {
  myServo.attach(SERVO_PIN);
}

void loop() {
  x = analogRead(JOY_X_PIN);
  servoPos = map(x, 0, 1023, 0, 180);
  myServo.write(servoPos);
  delay(100);
}
