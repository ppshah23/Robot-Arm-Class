// ============================================================
//  Digital Output -- Blinking One LED
//  Source: Day 1, Slide 51 ("How to build a Software Program")
// ============================================================
#define LED_PIN 7

void setup()
{
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
