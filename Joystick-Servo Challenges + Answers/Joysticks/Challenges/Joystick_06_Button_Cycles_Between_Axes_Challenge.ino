// ============================================================
//  Joystick -- Button Cycles Between X and Y Axis Control
//  Source: Week2_Day2.pptx, Slide 53 (challenge, solved)
// ============================================================
#include <Servo.h>

#define JOY_X_PIN A0
#define JOY_Y_PIN A1
#define JOY_BUTTON_PIN 2
#define SERVO_PIN 7
#define CENTER_OFFSET 512
#define DEAD_ZONE 30

Servo myServo;
int servoPos = 90;
int joyVal;
bool btn_state;
bool useYAxis = false;

void setup() {
  pinMode(JOY_BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);
  myServo.attach(SERVO_PIN);
  myServo.write(servoPos);
}

void loop() {
  btn_state = digitalRead(JOY_BUTTON_PIN);

  // ############################################################
  //  CHALLENGE: WHEN THE BUTTON IS PRESSED, FLIP useYAxis, PRINT
  //  WHICH AXIS IS NOW ACTIVE, THEN while-WAIT FOR RELEASE
  // ############################################################
  if (btn_state == __) {
    useYAxis = __;
    Serial.println(useYAxis ? ">> Now using Y axis" : ">> Now using X axis");

    while (btn_state == __) {
      delay(__);
      btn_state = digitalRead(__);
    }
  }

  // ############################################################
  //  CHALLENGE: IF useYAxis IS TRUE, READ FROM JOY_Y_PIN --
  //  OTHERWISE READ FROM JOY_X_PIN (BOTH MINUS CENTER_OFFSET)
  // ############################################################
  if (useYAxis) {
    joyVal = analogRead(__) - CENTER_OFFSET;
  } else {
    joyVal = analogRead(__) - CENTER_OFFSET;
  }

  if (abs(joyVal) > DEAD_ZONE) {
    servoPos = servoPos + joyVal / 100;
    myServo.write(servoPos);
  }
  delay(100);
}
