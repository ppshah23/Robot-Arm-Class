// ============================================================
//  Analog Input -- Reading the Joystick
//  Source: Day 2, Slides 50-51 ("Step 1: Read the Joystick Values")
// ============================================================
#define JOY_X_PIN A0
#define JOY_Y_PIN A1
#define JOY_BUTTON_PIN 2
int x;
int y;
bool btn_state;

void setup() {
  pinMode(JOY_BUTTON_PIN, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Ready...");
}

void loop() {
  x = analogRead(JOY_X_PIN);   // read voltage & convert to # from 0 to 1023
  // ############################################################
  //  CHALLENGE: READ y FROM JOY_Y_PIN AND btn_state FROM
  //  JOY_BUTTON_PIN, THE SAME WAY x WAS READ ABOVE
  // ############################################################
  y = analogRead(__);
  btn_state = digitalRead(__);

  // Log output
  Serial.print("X: ");
  Serial.print(x);
  // ############################################################
  //  CHALLENGE: PRINT " Y: " FOLLOWED BY y, AND " Button: "
  //  FOLLOWED BY btn_state, THE SAME WAY X WAS PRINTED ABOVE
  // ############################################################
  Serial.print(" Y: ");
  Serial.print(__);
  Serial.print(" Button: ");
  Serial.println(__);

  delay(100);   // Wait 100 milliseconds before reading again.
}
