// ============================================================
//  Libraries -- The Servo Library
//  Source: Day 1, Slides 80-83 (built up step by step)
// ============================================================
#include <Servo.h>       // servo library

#define PIN_servo  3     // we will attach servo to pin 3

Servo myservo;            // Creates object that we can use

void setup()
{
  myservo.attach(__);
}

void loop()
{
  myservo.write(180);   // rotates clockwise 180 deg
  delay(1000);
  // ############################################################
  //  CHALLENGE: ROTATE BACK THE OTHER WAY (0 DEG)
  // ############################################################
  myservo.write(__);
  delay(1000);

  delay(15);
}
