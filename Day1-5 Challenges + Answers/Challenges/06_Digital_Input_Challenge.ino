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
  if (digitalRead(__) == __) {
    // ############################################################
    //  CHALLENGE: LED ON OR OFF WHEN THE BUTTON IS PRESSED?
    // ############################################################
    digitalWrite(PIN_LED_output, __);
  }
  else {
    // ############################################################
    //  CHALLENGE: LED ON OR OFF WHEN THE BUTTON IS NOT PRESSED?
    // ############################################################
    digitalWrite(PIN_LED_output, __);
  }

  delay(10);
}
