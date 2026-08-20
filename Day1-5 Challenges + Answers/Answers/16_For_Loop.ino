// ============================================================
//  For Loop -- Stepping Through an Array
//  Source: Day 3, Slide 12 ("Stepping Through an Array")
//  NOTE: "arm_servos" is used on the slide but not declared on
//  it -- declared here as a 5-element Servo array so it compiles.
//  A typo ("i---" for "i--") was also corrected.
// ============================================================
#include <Servo.h>

Servo arm_servos[5];

void setup() {
  for (int i = 0; i < 5; i++) {
     arm_servos[i].write(90);   // initialize servos
     delay(500);                 // allow time for servo to move
  }
}

void loop() {
  for (int i = 4; i >= 0; i--) {
     arm_servos[i].write(90);   // initialize servos
     delay(500);                 // allow time for servo to move
  }
}
