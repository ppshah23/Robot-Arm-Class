// ============================================================
//  Analog Input & map() -- Controlling a Servo with a Joystick
//  Source: Day 2, Slides 52-53 ("Step 2: Control a Servo")
// ============================================================
#include <Servo.h>

#define JOY_X_PIN A0
#define JOY_Y_PIN A1
#define JOY_BUTTON_PIN 2
#define SERVO_PIN 7

Servo myServo;      // "Naming" your servo
int servoPos = 90;  // variable to hold the servo position
int x;
int y;
bool btn_state;

void setup() {
  pinMode(JOY_BUTTON_PIN, INPUT_PULLUP);

  Serial.begin(9600);       // Lets us send messages to Serial Monitor
  Serial.println("Ready...");

  myServo.attach(SERVO_PIN);   // Connect our servo object to pin 7
  myServo.write(servoPos);      // Move servo to its starting position
}

void loop() {
  x = analogRead(JOY_X_PIN);   // reads voltage and converts to # from 0 to 1023
  y = analogRead(JOY_Y_PIN);
  btn_state = digitalRead(JOY_BUTTON_PIN);

  servoPos = map(x, 0, 1023, 0, 180);   // Convert joystick range (0-1023)
                                          // to a servo range (0-180)
  myServo.write(servoPos);

  // Log output
  Serial.print("X: ");
  Serial.print(x);
  Serial.print(" Servo Position: ");
  Serial.println(servoPos);

  // When the button is pressed, print a message
  if (btn_state == 0) {
     Serial.println("** BUTTON PRESSED **");
  }
  delay(100);   // Wait 100 milliseconds before reading again.
}
