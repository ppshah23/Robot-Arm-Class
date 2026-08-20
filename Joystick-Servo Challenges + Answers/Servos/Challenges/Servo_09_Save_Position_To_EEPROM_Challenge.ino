// ============================================================
//  Servo -- Saving Its Position to EEPROM
//  Source: Day 5 (Kitara-James), Slide 30
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

  // ############################################################
  //  CHALLENGE: LOAD THE LAST SAVED POSITION FROM SAVE_ADDRESS
  //  WITH EEPROM.get(), THEN WRITE IT TO THE SERVO
  // ############################################################
  EEPROM.get(__, __);
  myservo.write(pos);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    // ############################################################
    //  CHALLENGE: SAVE pos TO SAVE_ADDRESS WITH EEPROM.put()
    // ############################################################
    EEPROM.put(__, __);
    delay(500);
  }
}
