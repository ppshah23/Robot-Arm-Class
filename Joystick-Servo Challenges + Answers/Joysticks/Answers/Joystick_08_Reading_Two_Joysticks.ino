// ============================================================
//  Joystick -- Reading Two Joysticks, Each Owning a Servo
//  Source: Day 3 (Kitara-James), Slide 22, simplified to 2 joysticks
// ============================================================
#include <Servo.h>

#define JOY1_X_PIN A0
#define JOY2_X_PIN A1
#define CENTER_OFFSET 512
#define DEAD_ZONE 30

Servo myServos[2];
int pins[2] = {2, 3};
int pos[2] = {90, 90};

void setup() {
  myServos[0].attach(pins[0]);
  myServos[1].attach(pins[1]);
}

void loop() {
  int joy1_x = analogRead(JOY1_X_PIN) - CENTER_OFFSET;
  if (abs(joy1_x) > DEAD_ZONE) {
    pos[0] = pos[0] + (joy1_x / 100);
    myServos[0].write(pos[0]);
  }

  int joy2_x = analogRead(JOY2_X_PIN) - CENTER_OFFSET;
  if (abs(joy2_x) > DEAD_ZONE) {
    pos[1] = pos[1] + (joy2_x / 100);
    myServos[1].write(pos[1]);
  }

  delay(100);
}
