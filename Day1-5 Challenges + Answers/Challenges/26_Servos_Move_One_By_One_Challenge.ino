// ============================================================
//  Arrays + For Loop -- 3 Servos Move One-by-One
//  Source: Week2 UCD Robotics Camp, Prachi_Week2_Day3.pptx,
//  Slide 25 (CHALLENGE: "Can you make 3 Servos move one-by-one,
//  using an array?"), blanked version from Slide 26.
// ============================================================
#include <Servo.h>

int servoPins[_] = {_, _, _};   // array of Servo pins
Servo servos[_];                  // array of Servos

void setup() {
  for (int i = _; i < _; i__) {
    servos__.attach(servoPins__); // attach servos to pins
    servos__.write(0);             // initialize servos, set to zero
    delay(500);                     // allow time for servo to move
  }
}

void loop() {
  for (int i = _; i < _; i__) {
    servos__.write(90);   // move servo
    delay(500);            // delay
    servos__.write(0);    // move it back
    delay(500);            // delay
  }
}
