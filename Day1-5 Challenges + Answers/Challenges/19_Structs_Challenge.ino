// ============================================================
//  Structs -- Bundle Related Data
//  Source: Day 3, Slide 24 ("Structs: Bundle Related Data")
// ============================================================
struct button {
  byte pressed = 0;
};

struct analog {
  // ############################################################
  //  CHALLENGE: TWO ints AND ONE button FIELD -- LOOK AT loop()
  //  BELOW FOR THEIR NAMES
  // ############################################################
  int __, __;
  button __;
};

analog joy1, joy2, joy3, joy4;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("x: ");
  Serial.print(joy1.x);
  Serial.print("  pressed: ");
  Serial.println(joy1.btn.pressed);
  delay(200);
}
