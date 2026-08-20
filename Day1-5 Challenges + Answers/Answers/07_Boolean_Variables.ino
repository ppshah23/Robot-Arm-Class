// ============================================================
//  Boolean Variables
//  Source: Day 1, Slide 69 ("Step 7: Use button_state Variable")
// ============================================================
// Our first variable! "bool" type variables can be 0 or 1.

#define PIN_button_input 2
#define PIN_LED_output   8
bool button_state;

void setup()
{
  pinMode(PIN_button_input, INPUT);
  pinMode(PIN_LED_output, OUTPUT);
}

void loop()
{
  button_state = digitalRead(PIN_button_input);

  if (button_state == HIGH) {
    digitalWrite(PIN_LED_output, HIGH);
  }
  else {
    digitalWrite(PIN_LED_output, LOW);
  }

  delay(10);
}
