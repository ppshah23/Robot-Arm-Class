// ============================================================
//  For Loop -- Stepping Through an Array
//  Source: Day 3, Slide 12 ("Stepping Through an Array")
// ============================================================
#include <Servo.h>

Servo arm_servos[5];

void setup() {
  for (int i = 0; i < 5; i++) {
     arm_servos[i].write(__);   // initialize servos
     delay(500);                 // allow time for servo to move
  }
}

void loop() {
  // ############################################################
  //  CHALLENGE: THE SAME LOOP, BUT IN REVERSE
  // ############################################################
  for (int i = __; i __ 0; __) {
     arm_servos[i].write(__);
     delay(500);
  }
}
