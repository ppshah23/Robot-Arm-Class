// ============================================================
//  The Same Pattern, Used Twice -- LEDs and Servos
//  Source: Day 3, Slide 17 ("The Same Pattern, Used Twice")
//  NOTE: the slide shows these calls loose; they were placed
//  into setup()/loop() so this compiles and runs.
// ============================================================
#include <Servo.h>

// Set each LED pin to OUTPUT
int ledPins[] = {2, 3, 4};

// Attach each servo to its pin
Servo myServos[3];
int pins[3] = {2, 3, 4};

void setup() {
  pinMode(ledPins[0], OUTPUT);
  pinMode(ledPins[1], OUTPUT);
  pinMode(ledPins[2], OUTPUT);

  myServos[0].attach(pins[0]);
  myServos[1].attach(pins[1]);
  myServos[2].attach(pins[2]);
}

void loop() {
  // Turn on LED 0
  digitalWrite(ledPins[0], HIGH);

  // Move servo 0 to 90 degrees
  myServos[0].write(90);
}
