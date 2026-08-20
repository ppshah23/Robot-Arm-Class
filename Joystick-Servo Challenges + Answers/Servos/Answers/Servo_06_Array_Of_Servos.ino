// ============================================================
//  Servo -- An Array of Servos
//  Source: Day 3 (Kitara-James), Slide 17
// ============================================================
#include <Servo.h>

Servo myServos[3];
int pins[3] = {2, 3, 4};

void setup() {
  myServos[0].attach(pins[0]);
  myServos[1].attach(pins[1]);
  myServos[2].attach(pins[2]);
}

void loop() {
  myServos[0].write(0);
  myServos[1].write(0);
  myServos[2].write(0);
  delay(1000);
  myServos[0].write(180);
  myServos[1].write(180);
  myServos[2].write(180);
  delay(1000);
}
