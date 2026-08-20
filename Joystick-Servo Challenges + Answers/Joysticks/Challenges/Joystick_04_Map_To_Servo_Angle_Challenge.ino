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
  myServo.attach(__);
}

void loop() {
  x = analogRead(JOY_X_PIN);
  // ############################################################
  //  CHALLENGE: map() x FROM 0-1023 INTO servoPos FROM 0-180,
  //  THEN WRITE servoPos TO THE SERVO
  // ############################################################
  servoPos = map(x, __, __, __, __);
  myServo.write(__);
  delay(100);
}
