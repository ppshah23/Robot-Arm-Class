// ============================================================
//  Variables -- Introducing "int"
//  Source: Day 2, Slide 35
//  ("New variable type! 'int' variables can be any value
//    from -32768 to 32767")
// ============================================================
#include <Servo.h>

#define PIN_servo  3

Servo myservo;
int pos = 0;

void setup()
{
  myservo.attach(PIN_servo);
  myservo.write(pos);
  delay(500);
}

void loop()
{
  pos = pos __ 180;    // Rotate clockwise
  myservo.write(pos);
  delay(1000);
  // ############################################################
  //  CHALLENGE: GO BACK THE OTHER WAY -- ADD OR SUBTRACT?
  // ############################################################
  pos = pos __ 180;
  myservo.write(pos);
  delay(1000);
}
