// ============================================================
//  Joystick -- Controlling One Servo Inside an Array
//  Source: Week2_Day4.pptx, Slide 24 (challenge, solved)
// ============================================================
#include <Servo.h>

#define JOY1_Y_PIN A1
#define CENTER_OFFSET 512
#define DEAD_ZONE 10

Servo arm_servos[3];
int pins[3] = {2, 3, 4};
int pos[3]     = {90, 90, 90};
int min_pos[3] = {0, 0, 0};
int max_pos[3] = {180, 180, 180};

void setup() {
  for (int i = 0; i < 3; i++) {
    arm_servos[i].attach(pins[i]);
    arm_servos[i].write(__);
  }
}

void loop() {
  int joy1_y = analogRead(JOY1_Y_PIN) - CENTER_OFFSET;

  // ############################################################
  //  CHALLENGE: IF joy1_y IS PAST DEAD_ZONE, UPDATE pos[2], CLAMP
  //  IT BETWEEN min_pos[2] AND max_pos[2], THEN WRITE arm_servos[2]
  // ############################################################
  if (abs(joy1_y) > DEAD_ZONE) {
    pos[2] = pos[2] + (joy1_y / __);

    if (pos[2] > max_pos[2]) {
      pos[2] = __;
    }
    if (pos[2] < min_pos[2]) {
      pos[2] = __;
    }

    arm_servos[2].write(__);
  }
  delay(50);
}
