// ============================================================
//  Arrays
//  Source: Day 3, Slide 10 ("Software Concept: Arrays")
// ============================================================
int leds[3] = {2, 3, 4};

void setup()
{
  // ############################################################
  //  CHALLENGE: WHAT INDEX IS EACH LED?
  // ############################################################
  pinMode(leds[__], OUTPUT);
  pinMode(leds[__], OUTPUT);
  pinMode(leds[__], OUTPUT);
}

void loop()
{
  digitalWrite(leds[0], HIGH);   // i = 0 -> leds[0] -> pin 2
  digitalWrite(leds[1], HIGH);   // i = 1 -> leds[1] -> pin 3
  digitalWrite(leds[2], HIGH);   // i = 2 -> leds[2] -> pin 4
  delay(500);
  // ############################################################
  //  CHALLENGE: TURN THEM BACK OFF
  // ############################################################
  digitalWrite(leds[0], __);
  digitalWrite(leds[1], __);
  digitalWrite(leds[2], __);
  delay(500);
}
