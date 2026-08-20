// ============================================================
//  LiquidCrystal Library -- Scrolling Name Display
//  Source: Week2 UCD Robotics Camp, Prachi_Week2_Day3.pptx,
//  Slide 37 (CHALLENGE: "Can you make your name scroll across
//  the display?"), worked answer from Slide 39.
//  NOTE: the slide's String literal used curly/smart quotes
//  ("John Doe") from PowerPoint's autocorrect, which are not
//  valid C++ string delimiters -- corrected to straight quotes
//  here so this compiles.
// ============================================================
#include <LiquidCrystal.h>  // include the library

// adjust these to match your wiring
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // rs, en, d4, d5, d6, d7

String myName = "John Doe"; // swap this for your own name

void setup() {
  lcd.begin(16, 2); // initialize the display (16 cols, 2 rows)
}

void loop() {
// right to left
  for (int i = 16; i >= 0; i--) {
    lcd.clear();
    lcd.setCursor(i, 0); // index used as cursor position
    lcd.print(myName);
    delay(200); // delay to create the scroll effect
  }
// left to right
  for (int i = 0; i <= 16; i++) {
    lcd.clear();
    lcd.setCursor(i, 0);
    lcd.print(myName);
    delay(200);
  }
}
