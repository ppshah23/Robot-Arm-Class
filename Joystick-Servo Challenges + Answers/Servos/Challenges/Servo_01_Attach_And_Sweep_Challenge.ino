// ============================================================
//  Servo Basics -- Attach and Sweep
//  Source: Day 1 (Kitara-James), Slides 81-83
// ============================================================
#include <Servo.h>

#define PIN_servo  3

Servo myservo;

void setup()
{
  myservo.attach(__);
}

void loop()
{
  myservo.write(__);   // rotates clockwise 180 deg
  delay(1000);
  // ############################################################
  //  CHALLENGE: NOW ROTATE THE OTHER WAY (0 DEG), AND WAIT AGAIN
  // ############################################################
  myservo.write(__);
  delay(1000);
}
