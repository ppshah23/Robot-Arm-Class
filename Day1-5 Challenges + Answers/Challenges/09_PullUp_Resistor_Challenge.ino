// ============================================================
//  Floating Inputs & INPUT_PULLUP
//  Source: Day 2, Slide 17 ("Using 'INPUT_PULLUP'")
// ============================================================
#define BUTTON_RED 2
#define BUTTON_BLUE 3

#define LED_RED 8
#define LED_BLUE 9

bool button_state_red;
bool button_state_blue;

void setup()
{
  pinMode(BUTTON_RED, INPUT_PULLUP);
  pinMode(BUTTON_BLUE, INPUT_PULLUP);

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
}

void loop()
{
  button_state_red = digitalRead(BUTTON_RED);
  button_state_blue = digitalRead(BUTTON_BLUE);

  if (button_state_red == HIGH) {
     digitalWrite(__, __);
  } else {
     digitalWrite(__, __);
  }

  // ############################################################
  //  CHALLENGE: SAME PATTERN AS LED_RED ABOVE
  // ############################################################
  if (button_state_blue == HIGH) {
     digitalWrite(__, __);
  } else {
     digitalWrite(__, __);
  }

  delay(1000); // Wait for 1000 millisecond(s)
}
