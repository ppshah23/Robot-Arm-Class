// ============================================================
//  Servo -- Smooth Sweep with a While Loop
//  Source: Week2_Day4.pptx, Slide 25 (challenge, solved),
//  simplified to one button and one servo.
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
  if (digitalRead(BUTTON_PIN) == LOW) {
    pos = MIN_POS;
    myservo.write(pos);

    while (pos < MAX_POS) {
      pos++;
      myservo.write(pos);
      delay(15);         // small delay = smooth, slow motion
    }
  }
}
