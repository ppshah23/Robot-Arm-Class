// ============================================================
//  Servo -- Using a Position Variable
//  Source: Day 2 (Kitara-James), Slide 35
// ============================================================
#include <Servo.h>

#define PIN_servo  3

Servo myservo;
int pos = 0;      // variable to hold the servo's position

void setup()
{
  myservo.attach(PIN_servo);
  myservo.write(pos);
  delay(500);
}

void loop()
{
  pos = pos + 180;
  myservo.write(pos);
  delay(1000);
  pos = pos - 180;
  myservo.write(pos);
  delay(1000);
}
