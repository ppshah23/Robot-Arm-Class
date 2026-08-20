// ============================================================
//  LiquidCrystal Library -- Scrolling Name Display
//  Source: Week2 UCD Robotics Camp, Prachi_Week2_Day3.pptx,
//  Slide 37 (CHALLENGE: "Can you make your name scroll across
//  the display?"), blanked version from Slide 38.
//  NOTE: the slide's String literal used curly/smart quotes
//  ("John Doe") from PowerPoint's autocorrect, which are not
//  valid C++ string delimiters -- corrected to straight quotes
//  here so this compiles.
// ============================================================
#include <LiquidCrystal.h>  // DO NOT CHANGE THIS LIBRARY CALL

// adjust these to match your wiring
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // rs, en, d4, d5, d6, d7

String myName = "John Doe"; // swap this for your own name

void setup() {
  lcd.begin(_,_); // initialize the display
}

void loop() {
// right to left
  for (int i = _; i >= _; i__) {
    lcd.clear();
    lcd.setCursor(_, 0); // index used as cursor position
    lcd.print(__);
    delay(200); // delay to create the scroll effect
  }
// left to right
  for (int i = _; i <= _; i__) {
    lcd.clear();
    lcd.setCursor(_, 0);
    lcd.print(__);
    delay(200);
  }
}
