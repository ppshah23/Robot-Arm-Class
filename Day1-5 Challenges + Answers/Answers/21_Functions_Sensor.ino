// ============================================================
//  Functions -- Reading a Distance Sensor
//  Source: Day 4, Slide 11 ("Adding Sensors to Your Prototype")
//  NOTE: the slide's code has "int dist (duration * 0.034 / 2);"
//  (missing "=") and uses "duration" without declaring it --
//  both fixed here. The "clear trigPin" fragment (shown after
//  the function on the slide) was moved to the front of the
//  pulse sequence, which is the standard HC-SR04 pattern.
// ============================================================
#define ECHO_PIN 12
#define TRIG_PIN 13

long duration;

int getDistance() {
  // Clear trigPin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Set trigger pin on distance sensor HIGH for 10 microSeconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo Pin, returns sound wave travel time in microseconds
  duration = pulseIn(ECHO_PIN, HIGH, 20000);

  // Calculate distance in cm
  // Duration * speed of sound / 2 (there and back)
  int dist = duration * 0.034 / 2;
  return dist;
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(getDistance());
  delay(200);
}
