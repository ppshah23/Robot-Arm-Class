// ============================================================
//  LIBRARIES - DO NOT CHANGE
// ============================================================
#include <Wire.h>
#include <hd44780.h> // Include the hd44780 library
#include <hd44780ioClass/hd44780_I2Cexp.h> // Include the I2Cexp i/o class
#include <Servo.h>
#include <EEPROM.h>

// Add servo and hd44780 from library manager
// the way the jostick is mounted, left/right is "Y", up/down is "X"

// ============================================================
//  PIN DEFINITIONS - DO NOT CHANGE
// ============================================================
#define JOY1_X_PIN A6
#define JOY1_Y_PIN A7 
#define JOY1_BUTTON_PIN 7
#define JOY2_X_PIN A1 
#define JOY2_BUTTON_PIN 8 
#define JOY3_X_PIN A2 
#define JOY3_BUTTON_PIN 9 
#define JOY4_X_PIN A0 
#define JOY4_BUTTON_PIN 10
#define ECHO_PIN 12
#define TRIG_PIN 13

// ============================================================
//  EEPROM & CALIBRATION SETTINGS - DO NOT CHANGE
// ============================================================
#define EE_SIZE_ADDRESS 0  // This is the location where we will save the number of entries.
   
// When joystick is at rest, it reads ~512.   
// We will subtract this value to get ~0 when at rest.
#define ANALOG_X_CORRECTION 512 
#define ANALOG_Y_CORRECTION 512 

// If the joystick analog value is less than this, we ignore it.
#define DEAD_ZONE 30

// ============================================================
//  GLOBAL VARIABLES - DO NOT CHANGE
// ============================================================
Servo arm_servos[5];
                    // Grip, Wrist, Elbow, Shoulder, Rotate
int pos[5] =        {  90,    90,    90,       90,     90};
int min_pos[5] =    {  90,     0,     0,       90,      0};
int max_pos[5] =    { 130,   180,   180,      180,    160};
int servo_pins[5] = {   2,     3,     4,        5,      6};

//Variables for EEPROM Programming
int current_servo = 0;
int ee_address = 2;  // First two bytes saved for number of entries.
int ee_size = 1;

//Variables for distance sensor
long duration;
int distance = 0;
int box_start = 0;
int box_end = 180;
int box_center = 0;

int speed_divider = 100 ;   //larger number makes movements slower

// All Joystick variables
int  joy1_x;
int  joy1_y;
bool joy1_btn;

int  joy2_x;
bool joy2_btn;

int  joy3_x;
bool joy3_btn;

int  joy4_x;
bool joy4_btn;
   

// ============================================================
//  DISTANCE FUNCTION
// ============================================================
int getDistance() {

  // Set trigger pin on distance sensor HIGH for 10 microSeconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo Pin, returns sound wave travel time in microseconds
  duration = pulseIn(ECHO_PIN, HIGH, 20000);


  // Calculate distance in cm
  // Duration * speed of sound / 2 (there and back)
  // ############################################################
  //  CHALLENGE 7: WRITE THE DISTANCE FUNCTION
  // ############################################################
  int dist = ...
  return dist;
}

// ============================================================
//  LCD OBJECT - DO NOT CHANGE
// ============================================================
hd44780_I2Cexp lcd;



// ============================================================
//  VOID SETUP
// ============================================================
void setup()
{

  pinMode(JOY1_BUTTON_PIN, INPUT_PULLUP); 
  pinMode(JOY2_BUTTON_PIN, INPUT_PULLUP); 
  pinMode(JOY3_BUTTON_PIN, INPUT_PULLUP); 
  pinMode(JOY4_BUTTON_PIN, INPUT_PULLUP); 
  pinMode(TRIG_PIN, OUTPUT); // Sets the trigger pin as an Output
  pinMode(ECHO_PIN, INPUT);  // Sets the echo pin as an Input

  Serial.begin(9600); 
   
  lcd.begin(16, 2); 
  // Turn on the backlight
  lcd.backlight();
  //lcd.noBacklight();
  // Set the cursor to column 0, line 0 (first position)
  
  // ############################################################
  //  CHALLENGE 3: Fix the For Loop
  // ############################################################
  for (int i=__; i<__; i__) {
     arm_servos__.attach(servo__pins__);           // attach servo objects to pins
  }

  lcd.clear(); 
  lcd.setCursor(0, 0);
  lcd.print("Initializing"); 

  // ############################################################
  //  CHALLENGE 4: Fix the For Loop
  // ############################################################
  for (int i=_; i<_; i_) {
     arm_servos__.write(pos__);              // tell servo to go to position in variable 'pos'
     delay(500);
  }

  // ============================================================
  //  JOYSTICK CALIBRATION CHECK
  // ============================================================
  // This section makes sure that we have a valid reading from each used
  // axis on each joystick.  A bad reading will send the servos flying 
  // in the main loop.  The "while" loop here means that the code is 
  // effectively stuck at this point until the joysticks are attached 
  // correctly and the arm is re-booted.
  
  joy1_x = analogRead(JOY1_X_PIN) - ANALOG_X_CORRECTION; 
  while (abs(joy1_x) > DEAD_ZONE) {
      lcd.clear(); 
      lcd.setCursor(0, 0);
      lcd.print("JOYSTICK 1 X Error:"); 
      lcd.setCursor(0, 1);  
      lcd.print(joy1_x);
      delay (1000); 
  }
  joy1_y = analogRead(JOY1_Y_PIN) - ANALOG_Y_CORRECTION; 
  while (abs(joy1_y) > DEAD_ZONE) {
      lcd.clear(); 
      lcd.setCursor(0, 0);
      lcd.print("JOYSTICK 1 Y Error:"); 
      lcd.setCursor(0, 1);  
      lcd.print(joy1_y); 
      delay (1000); 
  }
  joy2_x = analogRead(JOY2_X_PIN) - ANALOG_X_CORRECTION; 
  while (abs(joy2_x) > DEAD_ZONE) {
      lcd.clear(); 
      lcd.setCursor(0, 0);
      lcd.print("JOYSTICK 2 X Error:"); 
      lcd.setCursor(0, 1);  
      lcd.print(joy2_x); 
      delay (1000); 
  }
  joy3_x = analogRead(JOY3_X_PIN) - ANALOG_X_CORRECTION; 
  while (abs(joy3_x) > DEAD_ZONE) {
      lcd.clear(); 
      lcd.setCursor(0, 0);
      lcd.print("JOYSTICK 3 X Error:"); 
      lcd.setCursor(0, 1);  
      lcd.print(joy3_x); 
      delay (1000); 
  }
  joy4_x = analogRead(JOY4_X_PIN) - ANALOG_X_CORRECTION;
  while (abs(joy4_x) > DEAD_ZONE) {
      // ############################################################
      //  CHALLENGE 6: SHOW AN LCD ERROR MESSAGE FOR JOYSTICK 4, THE
      //  SAME SHAPE AS THE while LOOP JUST ABOVE
      // ############################################################
  }

  lcd.clear(); 
  lcd.setCursor(0, 0);
  lcd.print("Manual Mode"); 

   // Clear trigPin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
}

// ============================================================
//  MAIN LOOP
// ============================================================
void loop()
{
  distance = getDistance();
  
  // read joysticks
  joy1_x = analogRead(JOY1_X_PIN) - ANALOG_X_CORRECTION; 
  joy1_y = analogRead(JOY1_Y_PIN) - ANALOG_Y_CORRECTION; 
  joy1_btn = digitalRead(JOY1_BUTTON_PIN); 
   
  joy2_x = analogRead(JOY2_X_PIN) - ANALOG_X_CORRECTION; 
  joy2_btn = digitalRead(JOY2_BUTTON_PIN); 
   
  joy3_x = analogRead(JOY3_X_PIN) - ANALOG_X_CORRECTION; 
  joy3_btn = digitalRead(JOY3_BUTTON_PIN); 

  joy4_x = analogRead(JOY4_X_PIN) - ANALOG_X_CORRECTION; 
  joy4_btn = digitalRead(JOY4_BUTTON_PIN); 

 
   // ============================================================
   //  JOYSTICK MOVEMENT CONTROLS
   // ============================================================
   // Joystick 1 X (up/down) controls gripper
   if (abs(joy1_x) > DEAD_ZONE) {
      pos[0] = pos[0] + (joy1_x/speed_divider) ;
      if (pos[0] > max_pos[0]) {
          pos[0] = max_pos[0];
      }
      if (pos[0] < min_pos[0]) {
          pos[0] = min_pos[0];
      }
      arm_servos[0].write(pos[0]);              // tell servo to go to position in variable 'pos'
      lcd.clear(); 
      lcd.setCursor(0, 0);
      lcd.print("Manual Mode"); 
      lcd.setCursor(0, 1);  
      lcd.print("Grp:"); 
      lcd.print(pos[0]); 
      lcd.print(" Dist:"); 
      lcd.print(distance); 
   }

   // Joystick 1 Y (left/right) controls rotation
   if (abs(joy1_y) > DEAD_ZONE) {
      pos[4] = pos[4] + (joy1_y/speed_divider) ;
      if (pos[4] > max_pos[4]) {
          pos[4] = max_pos[4];
      }
      if (pos[4] < min_pos[4]) {
          pos[4] = min_pos[4];
      }
      arm_servos[4].write(pos[4]);              // tell servo to go to position in variable 'pos'
      lcd.clear(); 
      lcd.setCursor(0, 0);
      lcd.print("Manual Mode"); 
      lcd.setCursor(0, 1);  
      lcd.print("Rot:"); 
      lcd.print(pos[4]); 
      lcd.print(" Dist:"); 
      lcd.print(distance); 

   }

   // Joystick 2 X (up/down) controls shoulder
   if (abs(joy2_x) > DEAD_ZONE) {
      pos[3] = pos[3] - (joy2_x/speed_divider) ;
      if (pos[3] > max_pos[3]) {
          pos[3] = max_pos[3];
      }
      if (pos[3] < min_pos[3]) {
          pos[3] = min_pos[3];
      }
      arm_servos[3].write(pos[3]);              // tell servo to go to position in variable 'pos'
      lcd.clear(); 
      lcd.setCursor(0, 0);
      lcd.print("Manual Mode"); 
      lcd.setCursor(0, 1);  
      lcd.print("Shl:"); 
      lcd.print(pos[3]); 
      lcd.print(" Dist:"); 
      lcd.print(distance); 
   }

   // Joystick 3 X (up/down) controls elbow
   if (abs(joy3_x) > DEAD_ZONE) {
      pos[2] = pos[2] - (joy3_x/speed_divider) ;
      if (pos[2] > max_pos[2]) {
          pos[2] = max_pos[2];
      }
      if (pos[2] < min_pos[2]) {
          pos[2] = min_pos[2];
      }
      arm_servos[2].write(pos[2]);              // tell servo to go to position in variable 'pos'
      lcd.clear(); 
      lcd.setCursor(0, 0);
      lcd.print("Manual Mode"); 
      lcd.setCursor(0, 1);  
      lcd.print("Elb:"); 
      lcd.print(pos[2]); 
      lcd.print(" Dist:"); 
      lcd.print(distance); 
   }

   // Joystick 4 X (up/down) controls wrist
   if (abs(joy4_x) > DEAD_ZONE) {
      // ############################################################
      //  CHALLENGE 5: SAME PATTERN AS SHOULDER/ELBOW ABOVE (BOTH
      //  USE "-") -- UPDATE pos[1], CLAMP IT BETWEEN
      //  min_pos[1]/max_pos[1], THEN WRITE arm_servos[1]
      // ############################################################
      pos[1] = pos[1] _ (joy4_x/speed_divider) ;
      if (pos[1] > max_pos[1]) {
          pos[1] = _;
      }
      if (pos[1] < min_pos[1]) {
          pos[1] = _;
      }
      arm_servos[1].write(_);              // tell servo to go to position in variable 'pos'
      lcd.clear(); 
      lcd.setCursor(0, 0);
      lcd.print("Manual Mode"); 
      lcd.setCursor(0, 1);  
      lcd.print("Wrs:"); 
      lcd.print(pos[1]); 
      lcd.print(" Dist:"); 
      lcd.print(distance); 
   }

   // ----- Save Position (Button 1) -----
   // ############################################################
   //  CHALLENGE 1: WITH INPUT_PULLUP, "PRESSED" READS AS WHICH
   //  VALUE?
   // ############################################################
   if (joy1_btn == __) {
       // Save coordinate for replay mode
       char buff[50];
       lcd.clear(); 
       lcd.setCursor(0, 0);
       sprintf(buff, "Saving #%i: ", ee_size);
       lcd.print(buff);
       lcd.setCursor(0, 1);
       sprintf(buff, "%i %i %i %i %i",  pos[0], pos[1], pos[2], pos[3], pos[4]);
       lcd.print(buff);
          
       EEPROM.put(EE_SIZE_ADDRESS, ee_size);
       EEPROM.put(ee_address, pos);
       ee_size+= 1; 
       ee_address+= 10;  // array will always be 5*2 bytes.
       while (joy1_btn == 0) { 
           //Don't do anything until they let go }
           delay(50);
           joy1_btn = digitalRead(JOY1_BUTTON_PIN);
       }
   }
   // ----- Scan for Box (Button 2) -----
   if (joy2_btn == 0) {
       // Scan for box
       char buff[50];
       // Raise shoulder to allow scan
       pos[3] = 90;
       // Rotate all the way to the left
       pos[4] = min_pos[4];

       //reset box coordinates
       box_start = 0;
       box_center = 0;
       box_end = 0;
       
       arm_servos[3].write(pos[3]);
       arm_servos[4].write(pos[4]);
       while (pos[4] < max_pos[4]) {
          pos[4]++;
          arm_servos[4].write(pos[4]);              // tell servo to go to position in variable 'pos'
          distance = getDistance();
          if (distance > 0 && distance <10 && box_start == 0) {
             box_start = pos[4];
          }
          if ((distance >10 || distance == 0) && box_start > 0 && box_center == 0) {
             if ((pos[4] - box_start) > 10) {
                box_end = pos[4];
                box_center = (box_end - box_start)/2 + box_start;
             } else {
                box_start = 0;
             }
          }
          delay(100);
          lcd.clear(); 
          lcd.setCursor(0, 0);
          lcd.print("Manual Mode"); 
          lcd.setCursor(0, 1);  
          lcd.print("Rot:"); 
          lcd.print(pos[4]); 
          lcd.print(" Dist:"); 
          lcd.print(distance); 
       }
       if (box_center == 0) {
          lcd.clear(); 
          lcd.setCursor(0, 0);
          lcd.print("Did not find box"); 
       } else {
          lcd.clear(); 
          lcd.setCursor(0, 0);
          lcd.print("Found box at:");
          lcd.setCursor(0, 1);
          lcd.print(box_start);
          lcd.print(" ");
          lcd.print(box_center);
          lcd.print(" ");
          lcd.print(box_end);
          while (pos[4] > box_center) {
             pos[4]--;
             arm_servos[4].write(pos[4]);              // tell servo to go to position in variable 'pos'
             delay(10);
          }
          while (pos[2] < 164) {
             pos[2]++;
             arm_servos[2].write(pos[2]);              // tell servo to go to position in variable 'pos'
             delay(10);
          }
          while (pos[1] < 107) {
             pos[1]++;
             arm_servos[1].write(pos[1]);              // tell servo to go to position in variable 'pos'
             delay(10);
          }

          pos[0] = max_pos[0];
          arm_servos[0].write(max_pos[0]);
          
           
       }
   }
   // ----- Toggle Speed (Button 3) -----
   if (joy3_btn == 0) {
      if (speed_divider == 100) {
         speed_divider = 400;
      } else {
         speed_divider = 100;
      }
      while (joy3_btn == 0) { 
           //Don't do anything until they let go }
           delay(50);
           joy3_btn = digitalRead(JOY3_BUTTON_PIN);
      }
   }
   // ----- Replay Saved Positions (Button 4) -----
   if (joy4_btn == 0) {
       // replay saved coordinates
       int new_pos[5];
       EEPROM.get(EE_SIZE_ADDRESS, ee_size);
          
       ee_address = 2;
       for (int i=0; i<ee_size; i++) {
          char buff[50];
          lcd.clear(); 
          lcd.setCursor(0, 0);
          sprintf(buff, "Reading %i of %i: ", i+1, ee_size);
          lcd.print(buff);
          EEPROM.get(ee_address, new_pos);
          lcd.setCursor(0, 1);
          sprintf(buff, "%i %i %i %i %i",  new_pos[0], new_pos[1], new_pos[2], new_pos[3], new_pos[4]);
          lcd.print(buff);
          for (int i=0; i<5; i++) {
             while (pos[i] > new_pos[i]) {
               pos[i]--;
               arm_servos[i].write(pos[i]);              // tell servo to go to position in variable 'pos'
               delay(50);
             }
             while (pos[i] < new_pos[i]) {
               pos[i]++;
               arm_servos[i].write(pos[i]);              // tell servo to go to position in variable 'pos'
               delay(50);
             }
             arm_servos[i].write(pos[i]);              // tell servo to go to position in variable 'pos'
             delay(500);
          }
          ee_address += 10;
       }
       // ############################################################
       //  CHALLENGE 2: SAME "WAIT FOR RELEASE" SHAPE AS BUTTON 1'S
       //  SAVE BLOCK ABOVE, RENUMBERED FOR JOYSTICK 4
       // ############################################################
       while (joy4_btn == __) {
           //Don't do anything until they let go }
           delay(50);
           joy4_btn = digitalRead(JOY4_BUTTON_PIN);
       }
       ee_size=0;   // reset this so new program can be written or program can be re-run.
   }
   delay(50);
}
