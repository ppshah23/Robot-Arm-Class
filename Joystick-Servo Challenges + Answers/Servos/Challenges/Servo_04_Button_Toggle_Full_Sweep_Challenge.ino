// ============================================================
//  Servo -- Button Click Sweeps Full Range
//  Source: Week2_Day2.pptx, Slide 33 (challenge, solved)
// ============================================================
#include <Servo.h>

#define PIN_servo   3
#define BUTTON_PIN  2

Servo myservo;
bool button_state;
int servoPos = 0;

void setup() {
  myservo.attach(PIN_servo);
  myservo.write(servoPos);

  pinMode(BUTTON_PIN, __);
}

void loop() {
  button_state = digitalRead(BUTTON_PIN);

  // ############################################################
  //  CHALLENGE: WHEN THE BUTTON IS PRESSED (LOW), FLIP servoPos
  //  BETWEEN 0 AND 180, WRITE IT, THEN WAIT UNTIL RELEASED SO
  //  ONE CLICK = ONE MOVE
  // ############################################################
  if (button_state == __) {
    if (servoPos == 0) {
      servoPos = __;
    } else {
      servoPos = __;
    }
    myservo.write(servoPos);

    while (button_state == __) {
      delay(__);
      button_state = digitalRead(__);
    }
  }
}
