// ============================================================
//  Variables -- Introducing "int"
//  Source: Day 2, Slide 35
//  ("New variable type! 'int' variables can be any value
//    from -32768 to 32767")
// ============================================================
#include <Servo.h>

#define PIN_servo  3   // we will attach servo to pin 3

Servo myservo;   // Creates object that we can use
int pos = 0;

void setup()
{
  myservo.attach(PIN_servo);
  myservo.write(pos);   // Move to 0 deg
  delay(500);             // Wait for it to reach 0
}

void loop()
{
  pos = pos + 180;
  myservo.write(pos);   // rotates clockwise 180 deg
  delay(1000);            // delay to allow time to rotate
  pos = pos - 180;
  myservo.write(pos);    // rotates counter-clockwise 180 deg
  delay(1000);
}
