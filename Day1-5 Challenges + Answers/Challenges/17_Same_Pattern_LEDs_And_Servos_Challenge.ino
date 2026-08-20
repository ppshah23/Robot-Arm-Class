// ============================================================
//  The Same Pattern, Used Twice -- LEDs and Servos
//  Source: Day 3, Slide 17 ("The Same Pattern, Used Twice")
// ============================================================
#include <Servo.h>

// Set each LED pin to OUTPUT
int ledPins[] = {2, 3, 4};

// Attach each servo to its pin
Servo myServos[3];
int pins[3] = {2, 3, 4};

void setup() {
  // ############################################################
  //  CHALLENGE: SET ALL THREE LED PINS AS OUTPUTS
  // ############################################################
  pinMode(ledPins[__], OUTPUT);
  pinMode(ledPins[__], OUTPUT);
  pinMode(ledPins[__], OUTPUT);

  // ############################################################
  //  CHALLENGE: ATTACH ALL THREE SERVOS TO THEIR PINS
  // ############################################################
  myServos[__].attach(pins[__]);
  myServos[__].attach(pins[__]);
  myServos[__].attach(pins[__]);
}

void loop() {
  // Turn on LED 0
  digitalWrite(ledPins[0], __);

  // Move servo 0 to 90 degrees
  myServos[0].write(__);
}
