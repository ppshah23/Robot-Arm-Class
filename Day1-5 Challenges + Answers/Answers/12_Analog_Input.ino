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

  Serial.begin(9600);   // Lets us send messages to the Serial Monitor
  Serial.println("Ready...");
}

void loop() {
  x = analogRead(JOY_X_PIN);   // read voltage & convert to # from 0 to 1023
  y = analogRead(JOY_Y_PIN);
  btn_state = digitalRead(JOY_BUTTON_PIN);

  // Log output
  Serial.print("X: ");
  Serial.print(x);
  Serial.print(" Y: ");
  Serial.print(y);
  Serial.print(" Button: ");
  Serial.println(btn_state);

  delay(100);   // Wait 100 milliseconds before reading again.
}
