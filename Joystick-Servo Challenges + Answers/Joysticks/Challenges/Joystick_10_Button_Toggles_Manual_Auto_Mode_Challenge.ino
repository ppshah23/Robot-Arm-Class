// ============================================================
//  Joystick -- Button Toggles Manual vs. Automatic Mode
//  Source: original -- inspired by "Manual Mode" printed
//  throughout Middle_School_Arduino_Complete_Code.ino
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

  // ############################################################
  //  CHALLENGE: IF autoMode IS TRUE, SWEEP servoPos UP TO
  //  MAX_POS THEN BACK DOWN TO MIN_POS (FLIP sweepingUp AT EACH
  //  END) AND WRITE IT WITH A SMALL delay(15)
  // ############################################################
  if (autoMode) {
    if (sweepingUp) {
      servoPos__;
      if (servoPos >= MAX_POS) { sweepingUp = __; }
    } else {
      servoPos__;
      if (servoPos <= MIN_POS) { sweepingUp = __; }
    }
    myServo.write(servoPos);
    delay(__);
  } else {
    // ############################################################
    //  CHALLENGE: MANUAL MODE -- READ THE JOYSTICK, APPLY THE
    //  DEAD ZONE, UPDATE servoPos, WRITE IT
    // ############################################################
    int joyVal = analogRead(JOY_X_PIN) - CENTER_OFFSET;
    if (abs(joyVal) > DEAD_ZONE) {
      servoPos = servoPos + joyVal / __;
      myServo.write(__);
    }
    delay(100);
  }
}
