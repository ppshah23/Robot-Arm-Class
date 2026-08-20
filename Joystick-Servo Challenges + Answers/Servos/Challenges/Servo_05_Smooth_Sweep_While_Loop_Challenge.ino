// ============================================================
//  Servo -- Smooth Sweep with a While Loop
//  Source: Week2_Day4.pptx, Slide 25 (challenge, solved)
// ============================================================
#include <Servo.h>

#define PIN_servo    3
#define BUTTON_PIN   2
#define MIN_POS 0
#define MAX_POS 180

Servo myservo;
int pos = MIN_POS;

void setup() {
  myservo.attach(PIN_servo);
  myservo.write(pos);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == __) {
    pos = __;
    myservo.write(pos);

    // ############################################################
    //  CHALLENGE: WALK pos UP TO MAX_POS ONE DEGREE AT A TIME,
    //  WRITING IT EACH STEP WITH A SMALL delay(15)
    // ############################################################
    while (pos < __) {
      pos__;
      myservo.write(pos);
      delay(__);
    }
  }
}
