// ============================================================
//  Functions -- Reading a Distance Sensor
//  Source: Day 4, Slide 11 ("Adding Sensors to Your Prototype")
// ============================================================
#define ECHO_PIN 12
#define TRIG_PIN 13

long duration;

int getDistance() {
  // Clear trigPin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(__);

  // Set trigger pin on distance sensor HIGH for 10 microSeconds
  digitalWrite(TRIG_PIN, HIGH);
  // ############################################################
  //  CHALLENGE: HOW MANY MICROSECONDS DOES THE SLIDE SAY?
  // ############################################################
  delayMicroseconds(__);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo Pin, returns sound wave travel time in microseconds
  duration = pulseIn(__, __, __);

  // Calculate distance in cm
  // Duration * speed of sound / 2 (there and back)
  // ############################################################
  //  CHALLENGE: SPEED OF SOUND, DIVIDED BY 2
  // ############################################################
  int dist = duration * __ / __;
  return dist;
}

void setup() {
  pinMode(__, __);
  pinMode(__, __);
  Serial.begin(9600);
}

void loop() {
  Serial.println(getDistance());
  delay(200);
}
