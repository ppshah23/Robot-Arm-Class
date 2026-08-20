// ============================================================
//  Joystick -- Filtering Out Small Wiggles (Dead Zone)
//  Source: Day 2 (Kitara-James) & Week2_Day2.pptx, Slide 47
// ============================================================
#define JOY_X_PIN A0
#define CENTER_OFFSET 512
#define DEAD_ZONE 30

int joyVal;

void setup() {
  Serial.begin(9600);
}

void loop() {
  joyVal = analogRead(JOY_X_PIN) - CENTER_OFFSET;

  // ############################################################
  //  CHALLENGE: IF abs(joyVal) IS GREATER THAN DEAD_ZONE, PRINT
  //  "Moving: " + joyVal. OTHERWISE PRINT "Centered (ignored)"
  // ############################################################
  if (abs(joyVal) __ DEAD_ZONE) {
    Serial.print("Moving: ");
    Serial.println(__);
  } else {
    Serial.println("Centered (ignored)");
  }
  delay(200);
}
