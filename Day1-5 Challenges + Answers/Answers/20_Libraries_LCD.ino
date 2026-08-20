// ============================================================
//  Libraries -- The LCD Display (I2C)
//  Source: Day 3, Slide 29 ("Adding LCD to Your Servo Code")
// ============================================================
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

hd44780_I2Cexp lcd;

int pos[1] = {90};   // example servo-position value, like the slide's pos[0]

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
}

void loop() {
  // After writing the servo position:
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Servo at:");   // example string
  lcd.print(pos[0]);         // example variable
  delay(200);
}
