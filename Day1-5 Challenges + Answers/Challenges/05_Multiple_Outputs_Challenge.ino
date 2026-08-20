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
  digitalWrite(__, HIGH);
  digitalWrite(__, LOW);
  digitalWrite(__, HIGH);
  delay(500);
  // ############################################################
  //  CHALLENGE: SET EACH LED TO THE OPPOSITE STATE YOU GAVE IT ABOVE
  // ############################################################
  digitalWrite(LED_PIN_1, __);
  digitalWrite(LED_PIN_2, __);
  digitalWrite(LED_PIN_3, __);
  delay(500);
}
