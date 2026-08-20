// ============================================================
//  Multiple Outputs -- 3 LEDs
//  Source: Day 1, Slide 53 ("Build your Own 3-LED Circuit")
// ============================================================
#define LED_PIN_1 11
#define LED_PIN_2 10
#define LED_PIN_3 9

void setup()
{
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
}

void loop()
{
  // All 3 LEDs On, Then Off
  digitalWrite(LED_PIN_1, HIGH);
  digitalWrite(LED_PIN_2, LOW);
  digitalWrite(LED_PIN_3, HIGH);
  delay(500);
  digitalWrite(LED_PIN_1, LOW);
  digitalWrite(LED_PIN_2, HIGH);
  digitalWrite(LED_PIN_3, LOW);
  delay(500);
}
