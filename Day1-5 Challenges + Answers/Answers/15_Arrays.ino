// ============================================================
//  Arrays
//  Source: Day 3, Slide 10 ("Software Concept: Arrays")
//  NOTE: the slide shows these fragments loose; pinMode() calls
//  and the off/delay half of the blink were added to setup() and
//  loop() so this compiles and runs.
// ============================================================
// An array stores a list of related values in a single variable.
// Each position in the array is called an index -- arrays always
// start counting at 0.

int leds[3] = {2, 3, 4};

void setup()
{
  pinMode(leds[0], OUTPUT);
  pinMode(leds[1], OUTPUT);
  pinMode(leds[2], OUTPUT);
}

void loop()
{
  digitalWrite(leds[0], HIGH);   // i = 0 -> leds[0] -> pin 2
  digitalWrite(leds[1], HIGH);   // i = 1 -> leds[1] -> pin 3
  digitalWrite(leds[2], HIGH);   // i = 2 -> leds[2] -> pin 4
  delay(500);
  digitalWrite(leds[0], LOW);
  digitalWrite(leds[1], LOW);
  digitalWrite(leds[2], LOW);
  delay(500);
}
