// ============================================================
//  EEPROM -- Remembering Data After Power Off
//  Source: Day 5, Slide 30 ("What Is EEPROM?")
// ============================================================
#include <EEPROM.h>   // built-in, no install

#define SAVE_ADDRESS 0

void setup() {
  Serial.begin(9600);

  int savedValue;
  EEPROM.get(SAVE_ADDRESS, savedValue);   // read data from address
  Serial.print("Last saved value: ");
  Serial.println(savedValue);
}

void loop() {
  int newValue = millis();
  EEPROM.put(SAVE_ADDRESS, newValue);     // save data at address
  Serial.println("Saved.");
  delay(5000);
}
