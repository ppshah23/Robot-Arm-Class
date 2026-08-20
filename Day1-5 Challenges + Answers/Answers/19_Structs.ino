// ============================================================
//  Structs -- Bundle Related Data
//  Source: Day 3, Slide 24 ("Structs: Bundle Related Data")
//  NOTE: a setup()/loop() wrapper was added around the slide's
//  struct + usage fragments so this compiles and runs.
// ============================================================
// A struct groups related variables under one name, like a
// folder for data.

struct button {
  byte pressed = 0;
};

struct analog {
  int x, y;
  button btn;
};

analog joy1, joy2, joy3, joy4;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Now you read joy1.x and joy1.btn.pressed -- everything for
  // one joystick is grouped together.
  Serial.print("x: ");
  Serial.print(joy1.x);
  Serial.print("  pressed: ");
  Serial.println(joy1.btn.pressed);
  delay(200);
}
