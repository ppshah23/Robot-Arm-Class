// ============================================================
//  While Loop
//  Source: Day 2, Slides 54-57 ("Step 3: Adding Constraints")
// ============================================================
#include <Servo.h>

#define JOY_X_PIN A0
#define JOY_Y_PIN A1
#define JOY_BUTTON_PIN 2
#define SERVO_PIN 7

// CONTROL SETTINGS
#define DEAD_ZONE 10   // Ignore joystick values smaller than this
#define MIN_POS 20     // Servo won't go below this angle
#define MAX_POS 180    // Servo won't go above this angle

// CENTERING CORRECTION
#define CENTER_OFFSET 128   // We map the joystick to 0-255 and
                             // subtract 128 so that center = 0, full
                             // back = -128, full forward = +127.

Servo myServo;       // "Naming" your servo
int servoPos = 90;   // variable to hold the servo position
int x;
bool btn_state;

void setup() {
  pinMode(JOY_BUTTON_PIN, INPUT_PULLUP);

  Serial.begin(9600);   // To send messages to Serial Monitor
  Serial.println("Ready...");

  myServo.attach(SERVO_PIN);   // Connect our servo object to pin 7
  myServo.write(servoPos);      // Move the servo to its starting position
}

void loop() {

  x = map(analogRead(JOY_X_PIN), 0, 1023, 0, 255) - CENTER_OFFSET;
  btn_state = digitalRead(JOY_BUTTON_PIN);

  if (abs(x) > DEAD_ZONE) {
    servoPos = servoPos + x;
    if (servoPos > MAX_POS) {
      servoPos = MAX_POS;
    }
    if (servoPos < MIN_POS) {
      servoPos = MIN_POS;
    }
    myServo.write(servoPos);   // moves servo
    Serial.print("Joystick: ");
    Serial.print(x);
    Serial.print("  Servo: ");
    Serial.println(servoPos);
  }

  // When the button is pressed, print a message
  if (btn_state == 0) {
    servoPos = 90;
    myServo.write(servoPos);
    Serial.println(">> Button pressed! Reset to 90 degrees.");

    // This command will wait until the button is released so
    // we don't keep resetting.
    while (btn_state == 0) {
      delay(50);
      btn_state = digitalRead(JOY_BUTTON_PIN);
    }
  }

  delay(100);   // Wait 100 milliseconds before reading again.
}
