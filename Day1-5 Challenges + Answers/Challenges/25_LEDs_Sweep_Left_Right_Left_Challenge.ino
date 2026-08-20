// ============================================================
//  Arrays + For Loop -- 3 LEDs Sweep Left-Right-Left
//  Source: Week2 UCD Robotics Camp, Prachi_Week2_Day3.pptx,
//  Slide 16 (CHALLENGE: "Can you make 3 LEDs light up one-by-one
//  from left to right to left, using an array?"), blanked
//  version from Slide 17.
//  Same challenge prompt also appears in Kitara-James,
//  Day3_Final.pptx, Slide 13 -- that deck has no worked answer
//  slide, so this file is sourced from Week2's Slide 17.
// ============================================================
int ledPins[_] = {_, _, _}; // change these to whatever pins your LEDs are on

void setup() {
  for (int i = _; i < _; i__) {
    pinMode(_, _);
  }
}

void loop() {
  // left to right
  for (int i = _; i < _; i__) {
    digitalWrite(ledPins[i], __);
    delay(200);
    digitalWrite(ledPins[i], __);
  }
  // right to left
  for (int i = _; i >= _; i__) {
    digitalWrite(ledPins[i], __);
    delay(200);
    digitalWrite(ledPins[i], __);
  }
}
