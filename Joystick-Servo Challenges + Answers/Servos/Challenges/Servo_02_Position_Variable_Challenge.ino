// ============================================================
//  Servo -- Using a Position Variable
//  Source: Day 2 (Kitara-James), Slide 35
// ============================================================
#include <Servo.h>

#define PIN_servo  3

Servo myservo;
int pos = 0;

void setup()
{
  myservo.attach(__);
  myservo.write(__);
  delay(500);
}

void loop()
{
  pos = pos __ 180;
  myservo.write(pos);
  delay(1000);
  // ############################################################
  //  CHALLENGE: GO BACK THE OTHER WAY -- ADD OR SUBTRACT?
  // ############################################################
  pos = pos __ 180;
  myservo.write(pos);
  delay(1000);
}
