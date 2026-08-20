// ============================================================
//  EEPROM + Structs -- Save & Replay Servo Positions
//  Source: Day 5, Slides 31-32 ("Save Positions (Button Press)" /
//  "Replay Saved Movements"); struct types from Day 3, Slide 24.
//  NOTE: declarations for arm_servos, pos, new_pos, ee_size and
//  ee_address are referenced across both slides but not declared
//  together on either -- gathered here so this compiles.
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

analog joy1, joy4;   // joy1 saves a frame, joy4 replays them

Servo arm_servos[5];
int pos[5]     = {90, 90, 90, 90, 90};
int new_pos[5];

int ee_size = 0;
int ee_address = 2;   // address 0-1 is reserved for ee_size

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Step 1: Save Positions (Button Press)
  // Each button press saves all 5 servo positions as one "frame".
  if (joy1.btn.pressed) {
    // Save count to address 0
    EEPROM.put(0, ee_size);

    // Save pos[] array
    EEPROM.put(ee_address, pos);

    ee_size += 1;
    ee_address += 10;   // 5 ints x 2 bytes
  }

  // Step 2: Replay Saved Movements
  if (joy4.btn.pressed) {
    EEPROM.get(EE_SIZE_ADDRESS, ee_size);
    ee_address = 2;
    for (int i = 0; i < ee_size; i++) {
      EEPROM.get(ee_address, new_pos);
      for (int j = 0; j < 5; j++) {
        while (pos[j] > new_pos[j]) {
          pos[j]--; arm_servos[j].write(pos[j]);
          delay(50);
        }
        while (pos[j] < new_pos[j]) {
          pos[j]++; arm_servos[j].write(pos[j]);
          delay(50);
        }
      }
      ee_address += 10;
    }
  }
}
