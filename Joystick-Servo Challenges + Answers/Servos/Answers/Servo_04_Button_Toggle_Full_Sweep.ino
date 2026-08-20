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

  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  button_state = digitalRead(BUTTON_PIN);

  if (button_state == LOW) {          // INPUT_PULLUP: pressed = LOW
    if (servoPos == 0) {
      servoPos = 180;
    } else {
      servoPos = 0;
    }
    myservo.write(servoPos);

    // wait for the button to be released so one click = one move
    while (button_state == LOW) {
      delay(50);
      button_state = digitalRead(BUTTON_PIN);
    }
  }
}
