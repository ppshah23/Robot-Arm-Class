// ============================================================
//  Digital Input -- Reading a Button
//  Source: Day 1, Slide 67 ("Step 5: Add Conditional Statement")
// ============================================================
#define PIN_button_input 2
#define PIN_LED_output   8

void setup()
{
  pinMode(PIN_button_input, INPUT);
  pinMode(PIN_LED_output, OUTPUT);
}

void loop()
{
  if (digitalRead(PIN_button_input) == HIGH) {
    digitalWrite(PIN_LED_output, HIGH);
  }
  else {
    digitalWrite(PIN_LED_output, LOW);
  }

  delay(10);
}
