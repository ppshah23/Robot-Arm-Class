// ============================================================
//  Libraries -- The LCD Display (I2C)
//  Source: Day 3, Slide 29 ("Adding LCD to Your Servo Code")
// ============================================================
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

hd44780_I2Cexp lcd;

int pos[1] = {90};

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
}

void loop() {
  lcd.clear();
  // ############################################################
  //  CHALLENGE: COLUMN 0, ROW 0 (TOP-LEFT)
  // ############################################################
  lcd.setCursor(__, __);
  lcd.print("Servo at:");
  lcd.print(__);
  delay(200);
}
