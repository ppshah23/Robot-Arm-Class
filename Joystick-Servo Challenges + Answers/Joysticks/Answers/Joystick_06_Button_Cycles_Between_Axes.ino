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

  // Toggle which axis controls the servo each time the button is clicked
  if (btn_state == 0) {
    useYAxis = !useYAxis;
    Serial.println(useYAxis ? ">> Now using Y axis" : ">> Now using X axis");

    while (btn_state == 0) {
      delay(50);
      btn_state = digitalRead(JOY_BUTTON_PIN);
    }
  }

  if (useYAxis) {
    joyVal = analogRead(JOY_Y_PIN) - CENTER_OFFSET;
  } else {
    joyVal = analogRead(JOY_X_PIN) - CENTER_OFFSET;
  }

  if (abs(joyVal) > DEAD_ZONE) {
    servoPos = servoPos + joyVal / 100;
    myServo.write(servoPos);
  }
  delay(100);
}
