// ============================================================
//  Digital Output -- Blinking One LED
//  Source: Day 1, Slide 51 ("How to build a Software Program")
// ============================================================
#define LED_PIN 7

void setup()
{
  pinMode(__, __);
}

void loop()
{
  digitalWrite(__, HIGH);   // turn the LED on
  delay(500);
  // ############################################################
  //  CHALLENGE: NOW TURN THE LED OFF
  // ############################################################
  digitalWrite(LED_PIN, __);
  delay(500);
}
