// ============================================================
//  Joystick -- Centering the Reading
//  Source: Week2_Day2.pptx, Slide 47
// ============================================================
#define JOY_X_PIN A0
#define CENTER_OFFSET 512   // joystick reads 0-1023; subtract 512 so
                             // center = 0, full back = -512, full forward = +512

int joyVal;

void setup() {
  Serial.begin(9600);
}

void loop() {
  joyVal = analogRead(JOY_X_PIN) - CENTER_OFFSET;

  Serial.print("Centered value: ");
  Serial.println(joyVal);
  delay(200);
}
