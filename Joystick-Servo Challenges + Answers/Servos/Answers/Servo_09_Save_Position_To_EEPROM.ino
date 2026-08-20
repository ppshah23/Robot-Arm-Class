// ============================================================
//  Servo -- Saving Its Position to EEPROM
//  Source: Day 5 (Kitara-James), Slide 30, simplified to one
//  servo (the real project saves an array of 5 the same way).
// ============================================================
#include <Servo.h>
#include <EEPROM.h>

#define PIN_servo    3
#define BUTTON_PIN   2
#define SAVE_ADDRESS 0

Servo myservo;
int pos = 90;

void setup() {
  myservo.attach(PIN_servo);

  EEPROM.get(SAVE_ADDRESS, pos);   // load whatever was saved last time
  myservo.write(pos);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    EEPROM.put(SAVE_ADDRESS, pos);   // remember this position
    delay(500);                        // simple debounce
  }
}
