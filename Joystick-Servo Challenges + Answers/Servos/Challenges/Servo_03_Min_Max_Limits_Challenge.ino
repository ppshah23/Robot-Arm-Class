// ============================================================
//  Servo -- Staying Within Min/Max Limits
//  Source: Day 2 (Kitara-James) & Week2_Day2.pptx, Slide 47
// ============================================================
#include <Servo.h>

#define PIN_servo  3
#define MIN_POS 20
#define MAX_POS 160

Servo myservo;
int pos = 20;
int step = 5;

void setup()
{
  myservo.attach(PIN_servo);
  myservo.write(pos);
}

void loop()
{
  pos = pos + step;

  // ############################################################
  //  CHALLENGE: IF pos IS ABOVE MAX_POS, CLAMP IT AND FLIP step
  //  NEGATIVE. IF pos IS BELOW MIN_POS, CLAMP IT AND FLIP step
  //  POSITIVE.
  // ############################################################
  if (pos > MAX_POS) {
    pos = __;
    step = __;
  }
  if (pos < MIN_POS) {
    pos = __;
    step = __;
  }

  myservo.write(pos);
  delay(50);
}
