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
#define DEAD_ZONE 10
#define MIN_POS 20
#define MAX_POS 180

// CENTERING CORRECTION
#define CENTER_OFFSET 128

Servo myServo;
int servoPos = 90;
int x;
bool btn_state;

void setup() {
  pinMode(JOY_BUTTON_PIN, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Ready...");

  // ############################################################
  //  CHALLENGE: ATTACH THE SERVO TO SERVO_PIN, THEN WRITE IT TO
  //  ITS STARTING POSITION servoPos
  // ############################################################
  myServo.attach(__);
  myServo.write(__);
}

void loop() {

  // ############################################################
  //  CHALLENGE: CONVERT THE 0-1023 JOYSTICK RANGE INTO 0-255
  // ############################################################
  x = map(analogRead(JOY_X_PIN), __, __, __, __) - CENTER_OFFSET;
  btn_state = digitalRead(JOY_BUTTON_PIN);

  if (abs(x) > DEAD_ZONE) {
    servoPos = servoPos + x;
    if (servoPos > MAX_POS) {
      servoPos = __;
    }
    if (servoPos < MIN_POS) {
      servoPos = __;
    }
    myServo.write(servoPos);
    Serial.print("Joystick: ");
    Serial.print(__);
    Serial.print("  Servo: ");
    Serial.println(__);
  }

  // When the button is pressed, print a message
  if (btn_state == 0) {
    // ############################################################
    //  CHALLENGE: RESET servoPos BACK TO THE CENTER AND WRITE IT
    // ############################################################
    servoPos = __;
    myServo.write(servoPos);
    Serial.println(">> Button pressed! Reset to 90 degrees.");

    // ############################################################
    //  CHALLENGE: WAIT UNTIL THE BUTTON IS RELEASED SO WE DON'T
    //  KEEP RESETTING
    // ############################################################
    while (btn_state == __) {
      delay(__);
      btn_state = digitalRead(__);
    }
  }

  delay(100);
}
