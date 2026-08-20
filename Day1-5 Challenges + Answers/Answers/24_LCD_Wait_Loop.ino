// ============================================================
//  Waiting for a Value in Range -- LCD Error Loop
//  Source: original -- combines analog reading (Day 2, Slides
//  50-51), the while loop (Day 2, Slides 54-57), and the LCD
//  library (Day 3, Slide 29) into the calibration-check pattern
//  used in Middle_School_Arduino_Complete_Code.ino's setup().
//  No single slide shows this exact combination.
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

  joyVal = analogRead(JOY_X_PIN) - CENTER_OFFSET;

  // Keep showing an error message as long as the joystick isn't centered
  while (abs(joyVal) > 20) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("JOYSTICK X Error:");
    lcd.setCursor(0, 1);
    lcd.print(joyVal);
    delay(1000);
  }

  lcd.clear();
  lcd.print("Centered!");
}

void loop() {
}
