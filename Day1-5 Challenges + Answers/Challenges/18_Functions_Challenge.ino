// ============================================================
//  Functions -- Write It Once
//  Source: Day 3, Slide 23 ("Helper Functions: Write It Once")
// ============================================================
#define JOY1_X_PIN A6

// Define the function ONCE:
int readAxisLevel(int pin) {
  // ############################################################
  //  CHALLENGE: 0-1023 INTO 0-255
  // ############################################################
  return map(analogRead(pin), __, __, __, __);
}

int joy1_x;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // ############################################################
  //  CHALLENGE: WHICH PIN DO WE WANT TO READ?
  // ############################################################
  joy1_x = readAxisLevel(__);

  Serial.println(__);
  delay(100);
}
