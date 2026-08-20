// ============================================================
//  Servo -- Initializing Several Servos with a For Loop
//  Source: Day 3 (Kitara-James), Slide 12
// ============================================================
#include <Servo.h>

Servo myServos[5];
int pins[5] = {2, 3, 4, 5, 6};

void setup() {
  for (int i = 0; i < __; i++) {
     myServos[i].attach(pins[i]);
     myServos[i].write(__);
     delay(500);
  }
}

void loop() {
  // ############################################################
  //  CHALLENGE: THE SAME LOOP, BUT IN REVERSE
  // ############################################################
  for (int i = __; i __ 0; __) {
     myServos[i].write(90);
     delay(500);
  }
}
