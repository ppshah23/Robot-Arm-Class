// ============================================================
//  Joystick -- Controlling One Servo Inside an Array
//  Source: Week2_Day4.pptx, Slide 24 (challenge, solved),
//  simplified from the real 5-servo arm down to 3 servos.
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
    arm_servos[i].write(pos[i]);
  }
}

void loop() {
  int joy1_y = analogRead(JOY1_Y_PIN) - CENTER_OFFSET;

  if (abs(joy1_y) > DEAD_ZONE) {
    pos[2] = pos[2] + (joy1_y / 100);

    if (pos[2] > max_pos[2]) {
      pos[2] = max_pos[2];
    }
    if (pos[2] < min_pos[2]) {
      pos[2] = min_pos[2];
    }

    arm_servos[2].write(pos[2]);
  }
  delay(50);
}
