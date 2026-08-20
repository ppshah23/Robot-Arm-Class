// ============================================================
//  Joystick -- Reading X, Y, and the Button
//  Source: Day 2 (Kitara-James), Slides 50-51
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
}

void loop() {
  x = analogRead(JOY_X_PIN);
  y = analogRead(JOY_Y_PIN);
  btn_state = digitalRead(JOY_BUTTON_PIN);

  Serial.print("X: ");
  Serial.print(x);
  Serial.print(" Y: ");
  Serial.print(y);
  Serial.print(" Button: ");
  Serial.println(btn_state);

  delay(100);
}
