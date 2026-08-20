// ============================================================
//  Waiting for a Value in Range -- LCD Error Loop
//  Source: original -- combines analog reading (Day 2, Slides
//  50-51), the while loop (Day 2, Slides 54-57), and the LCD
//  library (Day 3, Slide 29) into the calibration-check pattern
//  used in Middle_School_Arduino_Complete_Code.ino's setup().
// ============================================================
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

#define JOY_X_PIN A0
#define CENTER_OFFSET 512

hd44780_I2Cexp lcd;
int joyVal;

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();

  joyVal = analogRead(__) - __;

  // ############################################################
  //  CHALLENGE: KEEP SHOWING AN ERROR MESSAGE AS LONG AS THE
  //  JOYSTICK ISN'T CENTERED (abs(joyVal) > 20)
  // ############################################################
  while (abs(joyVal) __ 20) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("JOYSTICK X Error:");
    lcd.setCursor(0, 1);
    lcd.print(__);
    delay(1000);
  }

  lcd.clear();
  lcd.print("Centered!");
}

void loop() {
}
