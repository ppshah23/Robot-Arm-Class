// ============================================================
//  Servo -- Showing Its Position on the LCD
//  Source: Day 3 (Kitara-James), Slide 29
// ============================================================
#include <Servo.h>
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

#define PIN_servo 3

Servo myservo;
hd44780_I2Cexp lcd;
int pos = 0;

void setup() {
  myservo.attach(PIN_servo);
  lcd.begin(16, 2);
  lcd.backlight();
}

void loop() {
  pos = pos + 10;
  if (pos > 180) {
    pos = 0;
  }
  myservo.write(pos);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Servo at:");
  lcd.print(pos);
  delay(500);
}
