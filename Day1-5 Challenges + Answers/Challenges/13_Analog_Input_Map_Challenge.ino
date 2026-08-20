// ============================================================
//  Analog Input & map() -- Controlling a Servo with a Joystick
//  Source: Day 2, Slides 52-53 ("Step 2: Control a Servo")
// ============================================================
#include <Servo.h>

#define JOY_X_PIN A0
#define JOY_Y_PIN A1
#define JOY_BUTTON_PIN 2
#define SERVO_PIN 7

Servo myServo;
int servoPos = 90;
int x;
int y;
bool btn_state;

void setup() {
  pinMode(JOY_BUTTON_PIN, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Ready...");

  myServo.attach(SERVO_PIN);
  myServo.write(servoPos);
}

void loop() {
  x = analogRead(JOY_X_PIN);
  y = analogRead(JOY_Y_PIN);
  btn_state = digitalRead(JOY_BUTTON_PIN);

  // ############################################################
  //  CHALLENGE: CONVERT THE 0-1023 JOYSTICK RANGE INTO THE
  //  0-180 SERVO RANGE
  // ############################################################
  servoPos = map(x, __, __, __, __);
  myServo.write(servoPos);

  // Log output
  Serial.print("X: ");
  Serial.print(__);
  Serial.print(" Servo Position: ");
  Serial.println(__);

  // When the button is pressed, print a message
  if (btn_state == 0) {
     Serial.println("** BUTTON PRESSED **");
  }
  delay(100);
}
