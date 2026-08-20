// ============================================================
//  Joystick -- A Speed Divider for Finer Control
//  Source: Week2_Day2.pptx, Slides 55/57
// ============================================================
#include <Servo.h>

#define JOY_X_PIN A0
#define SERVO_PIN 7
#define CENTER_OFFSET 512
#define DEAD_ZONE 10
#define MIN_POS 20
#define MAX_POS 180

Servo myServo;
int servoPos = 90;
int joyVal;
int speed_divider = 255;   // bigger number = slower, finer control

void setup() {
  myServo.attach(SERVO_PIN);
  myServo.write(servoPos);
}

void loop() {
  joyVal = analogRead(JOY_X_PIN) - CENTER_OFFSET;

  if (abs(joyVal) > DEAD_ZONE) {
    servoPos = servoPos + joyVal / speed_divider;
    if (servoPos > MAX_POS) {
      servoPos = MAX_POS;
    }
    if (servoPos < MIN_POS) {
      servoPos = MIN_POS;
    }
    myServo.write(servoPos);
  }
  delay(100);
}
