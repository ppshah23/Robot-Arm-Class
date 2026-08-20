// ============================================================
//  Arrays + For Loop -- 3 Servos Move One-by-One
//  Source: Week2 UCD Robotics Camp, Prachi_Week2_Day3.pptx,
//  Slide 25 (CHALLENGE: "Can you make 3 Servos move one-by-one,
//  using an array?"), worked answer from Slide 27.
// ============================================================
#include <Servo.h>

int servoPins[3] = {9, 10, 11};   // array of Servo pins
Servo servos[3];                  // array of Servos

void setup() {
  for (int i = 0; i < 3; i++) {
    servos[i].attach(servoPins[i]); // attach servos to pins
    servos[i].write(0);             // initialize servos, set to zero
    delay(500);                     // allow time for servo to move
  }
}

void loop() {
  for (int i = 0; i < 3; i++) {
    servos[i].write(90);   // move servo
    delay(500);            // delay
    servos[i].write(0);    // move it back
    delay(500);            // delay
  }
}
