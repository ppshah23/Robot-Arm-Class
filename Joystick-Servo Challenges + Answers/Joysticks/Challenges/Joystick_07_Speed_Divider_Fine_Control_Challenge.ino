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
int speed_divider = 255;

void setup() {
  myServo.attach(SERVO_PIN);
  myServo.write(servoPos);
}

void loop() {
  joyVal = analogRead(JOY_X_PIN) - CENTER_OFFSET;

  if (abs(joyVal) > DEAD_ZONE) {
    // ############################################################
    //  CHALLENGE: ADD joyVal / speed_divider TO servoPos, CLAMP
    //  IT BETWEEN MIN_POS AND MAX_POS, THEN WRITE IT
    // ############################################################
    servoPos = servoPos + joyVal / __;
    if (servoPos > MAX_POS) {
      servoPos = __;
    }
    if (servoPos < MIN_POS) {
      servoPos = __;
    }
    myServo.write(__);
  }
  delay(100);
}
