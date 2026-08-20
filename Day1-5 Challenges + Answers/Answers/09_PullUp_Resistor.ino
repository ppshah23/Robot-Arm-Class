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
     digitalWrite(LED_RED, LOW);
  } else {
     digitalWrite(LED_RED, HIGH);
  }

  if (button_state_blue == HIGH) {
     digitalWrite(LED_BLUE, LOW);
  } else {
     digitalWrite(LED_BLUE, HIGH);
  }

  delay(1000); // Wait for 1000 millisecond(s)
}
