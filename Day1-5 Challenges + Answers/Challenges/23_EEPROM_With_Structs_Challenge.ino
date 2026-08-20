// ============================================================
//  EEPROM + Structs -- Save & Replay Servo Positions
//  Source: Day 5, Slides 31-32 ("Save Positions (Button Press)" /
//  "Replay Saved Movements"); struct types from Day 3, Slide 24.
// ============================================================
#include <Servo.h>
#include <EEPROM.h>

#define EE_SIZE_ADDRESS 0

struct button {
  byte pressed = 0;
};

struct analog {
  int x, y;
  button btn;
};

analog joy1, joy4;

Servo arm_servos[5];
int pos[5]     = {90, 90, 90, 90, 90};
int new_pos[5];

int ee_size = 0;
int ee_address = 2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Step 1: Save Positions (Button Press)
  if (joy1.btn.pressed) {
    EEPROM.put(0, __);
    EEPROM.put(ee_address, __);
    ee_size += 1;
    ee_address += 10;   // 5 ints x 2 bytes
  }

  // Step 2: Replay Saved Movements -- follow the same shape as Step 1
  if (joy4.btn.pressed) {
    EEPROM.get(EE_SIZE_ADDRESS, ee_size);
    ee_address = 2;
    for (int i = 0; i < ee_size; i++) {
      EEPROM.get(ee_address, new_pos);
      // ############################################################
      //  CHALLENGE: HOW MANY SERVOS DO WE HAVE?
      // ############################################################
      for (int j = 0; j < __; j++) {
        // ############################################################
        //  CHALLENGE: WHICH COMPARISON WALKS pos DOWN TOWARD new_pos?
        // ############################################################
        while (pos[j] __ new_pos[j]) {
          pos[j]--; arm_servos[j].write(pos[j]);
          delay(50);
        }
        // ############################################################
        //  CHALLENGE: WHICH COMPARISON WALKS pos UP TOWARD new_pos?
        // ############################################################
        while (pos[j] __ new_pos[j]) {
          pos[j]++; arm_servos[j].write(pos[j]);
          delay(50);
        }
      }
      // ############################################################
      //  CHALLENGE: SAME JUMP AS THE SAVE BLOCK ABOVE
      // ############################################################
      ee_address += __;
    }
  }
}
