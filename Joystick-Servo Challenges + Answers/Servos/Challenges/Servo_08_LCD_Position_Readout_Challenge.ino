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
  lcd.begin(__, __);
  lcd.backlight();
}

void loop() {
  pos = pos + 10;
  if (pos > 180) {
    pos = __;
  }
  myservo.write(pos);

  // ############################################################
  //  CHALLENGE: CLEAR THE LCD, SET THE CURSOR TO (0,0), THEN
  //  PRINT "Servo at:" FOLLOWED BY pos
  // ############################################################
  lcd.clear();
  lcd.setCursor(__, __);
  lcd.print("Servo at:");
  lcd.print(__);
  delay(500);
}
