// ============================================================
//  Servo -- Initializing Several Servos with a For Loop
//  Source: Day 3 (Kitara-James), Slide 12
// ============================================================
#include <Servo.h>

Servo myServos[5];
int pins[5] = {2, 3, 4, 5, 6};

void setup() {
  for (int i = 0; i < 5; i++) {
    myServos[i].attach(pins[i]);
    myServos[i].write(90);   // initialize servos
    delay(500);                // allow time for servo to move
  }
}

void loop() {
  for (int i = 4; i >= 0; i--) {
    myServos[i].write(90);
    delay(500);
  }
}
