// ============================================================
//  Servo -- An Array of Servos
//  Source: Day 3 (Kitara-James), Slide 17
// ============================================================
#include <Servo.h>

Servo myServos[3];
int pins[3] = {2, 3, 4};

void setup() {
  myServos[__].attach(pins[__]);
  myServos[__].attach(pins[__]);
  myServos[__].attach(pins[__]);
}

void loop() {
  myServos[0].write(__);
  myServos[1].write(__);
  myServos[2].write(__);
  delay(1000);
  // ############################################################
  //  CHALLENGE: NOW WRITE ALL THREE TO THE OPPOSITE END (180)
  // ############################################################
  myServos[0].write(__);
  myServos[1].write(__);
  myServos[2].write(__);
  delay(1000);
}
