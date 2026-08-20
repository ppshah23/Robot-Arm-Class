// ============================================================
//  Servo -- Staying Within Min/Max Limits
//  Source: Day 2 (Kitara-James) & Week2_Day2.pptx, Slide 47
//  (MIN_POS/MAX_POS clamp pattern), isolated into its own sweep
//  so the limit-checking logic stands on its own.
// ============================================================
#include <Servo.h>

#define PIN_servo  3
#define MIN_POS 20     // servo won't go below this angle
#define MAX_POS 160    // servo won't go above this angle

Servo myservo;
int pos = 20;
int step = 5;   // how far pos moves each loop

void setup()
{
  myservo.attach(PIN_servo);
  myservo.write(pos);
}

void loop()
{
  pos = pos + step;

  if (pos > MAX_POS) {
    pos = MAX_POS;
    step = -step;   // turn around at the top
  }
  if (pos < MIN_POS) {
    pos = MIN_POS;
    step = -step;   // turn around at the bottom
  }

  myservo.write(pos);
  delay(50);
}
