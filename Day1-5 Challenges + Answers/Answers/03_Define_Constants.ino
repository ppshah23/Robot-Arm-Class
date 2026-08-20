// ============================================================
//  #define -- Naming Your Pins
//  Source: Day 1, Slide 48 ("NAME  PIN #") & Slide 51
// ============================================================
// #define gives a number a friendly name, so your code reads
// like English instead of a list of confusing numbers.

#define LED_PIN 7

void setup()
{
  pinMode(LED_PIN, OUTPUT);   // "LED_PIN" is much clearer than "7"
}

void loop()
{

}
