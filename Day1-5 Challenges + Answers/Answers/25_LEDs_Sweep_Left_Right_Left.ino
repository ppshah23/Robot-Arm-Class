// ============================================================
//  Arrays + For Loop -- 3 LEDs Sweep Left-Right-Left
//  Source: Week2 UCD Robotics Camp, Prachi_Week2_Day3.pptx,
//  Slide 16 (CHALLENGE: "Can you make 3 LEDs light up one-by-one
//  from left to right to left, using an array?"), worked answer
//  from Slide 18 ("ANSWER").
//  Same challenge prompt also appears in Kitara-James,
//  Day3_Final.pptx, Slide 13 -- that deck has no worked answer
//  slide, so this file is sourced from Week2's Slide 18.
// ============================================================
int ledPins[3] = {2, 3, 4}; // change these to whatever pins your LEDs are on

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // left to right
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(200);
    digitalWrite(ledPins[i], LOW);
  }
  // right to left
  for (int i = 2; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(200); digitalWrite(ledPins[i], LOW);
  }
}
