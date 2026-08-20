// ============================================================
//  EEPROM -- Remembering Data After Power Off
//  Source: Day 5, Slide 30 ("What Is EEPROM?")
// ============================================================
#include <EEPROM.h>

#define SAVE_ADDRESS 0

void setup() {
  Serial.begin(9600);

  int savedValue;
  // ############################################################
  //  CHALLENGE: WHICH ADDRESS DID WE SAVE TO?
  // ############################################################
  EEPROM.get(__, savedValue);
  Serial.print("Last saved value: ");
  Serial.println(__);
}

void loop() {
  int newValue = millis();
  // ############################################################
  //  CHALLENGE: SAME ADDRESS AS ABOVE
  // ############################################################
  EEPROM.put(__, __);
  Serial.println("Saved.");
  delay(5000);
}
