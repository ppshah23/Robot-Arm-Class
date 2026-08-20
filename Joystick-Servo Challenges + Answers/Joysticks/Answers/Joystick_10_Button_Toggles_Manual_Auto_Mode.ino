// ============================================================
//  Joystick -- Button Toggles Manual vs. Automatic Mode
//  Source: original -- inspired by "Manual Mode" printed
//  throughout Middle_School_Arduino_Complete_Code.ino (the real
//  final project). No slide shows an explicit auto/manual
//  toggle; this combines the button-toggle technique
//  (Week2_Day2 Slide 53) with the smooth-sweep technique
//  (Week2_Day4 Slide 25) into a new example.
// ============================================================
#include <Servo.h>

#define JOY_X_PIN A0
#define JOY_BUTTON_PIN 2
#define SERVO_PIN 7
#define CENTER_OFFSET 512
#define DEAD_ZONE 30
#define MIN_POS 0
#define MAX_POS 180

Servo myServo;
int servoPos = 90;
bool autoMode = false;
bool sweepingUp = true;
bool btn_state;

void setup() {
  pinMode(JOY_BUTTON_PIN, INPUT_PULLUP);
  myServo.attach(SERVO_PIN);
  myServo.write(servoPos);
}

void loop() {
  btn_state = digitalRead(JOY_BUTTON_PIN);

  if (btn_state == 0) {
    autoMode = !autoMode;

    while (btn_state == 0) {
      delay(50);
      btn_state = digitalRead(JOY_BUTTON_PIN);
    }
  }

  if (autoMode) {
    if (sweepingUp) {
      servoPos++;
      if (servoPos >= MAX_POS) { sweepingUp = false; }
    } else {
      servoPos--;
      if (servoPos <= MIN_POS) { sweepingUp = true; }
    }
    myServo.write(servoPos);
    delay(15);
  } else {
    int joyVal = analogRead(JOY_X_PIN) - CENTER_OFFSET;
    if (abs(joyVal) > DEAD_ZONE) {
      servoPos = servoPos + joyVal / 100;
      myServo.write(servoPos);
    }
    delay(100);
  }
}
