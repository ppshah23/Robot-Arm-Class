// ============================================================
//  Functions -- Write It Once
//  Source: Day 3, Slide 23 ("Helper Functions: Write It Once")
//  NOTE: JOY1_X_PIN's value (A6) is from Day 5, Slide 23; a
//  setup()/loop() wrapper with a Serial print was added so this
//  compiles and runs.
// ============================================================
#define JOY1_X_PIN A6

// Define the function ONCE:
int readAxisLevel(int pin) {
  return map(analogRead(pin), 0, 1023, 0, 255);
}

int joy1_x;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Then just call it:
  joy1_x = readAxisLevel(JOY1_X_PIN);

  Serial.println(joy1_x);
  delay(100);
}
