// ============================================================
//  Joystick -- Button Resets the Servo Position
//  Source: Day 2 (Kitara-James), Slide 57
// ============================================================
#include <Servo.h>

#define JOY_X_PIN A0
#define JOY_BUTTON_PIN 2
#define SERVO_PIN 7
#define CENTER_OFFSET 512
#define DEAD_ZONE 10

Servo myServo;
int servoPos = 90;
int joyVal;
bool btn_state;

void setup() {
  pinMode(JOY_BUTTON_PIN, INPUT_PULLUP);
  myServo.attach(SERVO_PIN);
  myServo.write(servoPos);
}

void loop() {
  joyVal = analogRead(JOY_X_PIN) - CENTER_OFFSET;
  btn_state = digitalRead(JOY_BUTTON_PIN);

  if (abs(joyVal) > DEAD_ZONE) {
    servoPos = servoPos + joyVal / 100;
    myServo.write(servoPos);
  }

  // When the button is pressed, reset back to center
  if (btn_state == 0) {
    servoPos = 90;
    myServo.write(servoPos);

    while (btn_state == 0) {
      delay(50);
      btn_state = digitalRead(JOY_BUTTON_PIN);
    }
  }
  delay(100);
}
