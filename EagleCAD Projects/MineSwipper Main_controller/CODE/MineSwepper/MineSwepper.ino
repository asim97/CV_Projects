//*****************************************************************************************//
//                                 Mine Sweeper (MAIN COTROLLER)                           //
//*****************************************************************************************//
#include <Servo.h>                                                  //including the servo library to be used in our two servos
#include <PS3BT.h>                                                  //Include the necessary libraries.
#include <SPI.h>

USB Usb;
BTD Btd(&Usb);
PS3BT PS3(&Btd);

const char Magnet = A1;                                             //defining magnet pin
const char Motor_Left_PWM_PIN = 3;                                  //defining Motor_Left_PWM_PIN pin
const char Motor_Left_DIR = A5;                                     //defining Motor_Left_DIR pin
const char Motor_Right_PWM_PIN = 3;                                 //defining Motor_Right_PWM_PIN pin
const char Motor_Right_DIR = 2;                                     //defining Motor_Right_DIR pin
const char Coil_Signal = A3;                                        //defining Coil_Signal pin
const char Buzzer = A2;                                             //defining Buzzer pin
const char Servo_ARM1_signal = A4;                                  //defining Servo_ARM1_signal signal pin
const char Servo_ARM2_signal = A0;                                  //defining Servo_ARM2_signal signal pin

Servo Servo_ARM1;                                                   // create servo object to control Arm servo
Servo Servo_ARM2;                                                   // create servo object to control Magnet servo

int Motor_Left_PWM = 0;                                             //set speed of left motor to 0
int Motor_Right_PWM = 0;                                            //set speed of left motor to 0
int Servo_ARM_postion = 0;                                          //a variable to store the postion for arm servo and init it to 0 Deg
int Servo_ARM_postion_max = 120;                                    //define the max up degree for arm servo
int Servo_ARM_postion_min = 0;                                      //define the max up degree for arm servo
//define the max up degree for magnet servo

// Variables will change:
int BuzzerState = HIGH;                                             // the current state of the output pin
int SensorState;                                                    // the current reading from the input pin
int lastSensorState = LOW;                                          // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;                                 // the last time the output pin was toggled
unsigned long debounceDelay = 50;                                   // the debounce time; increase if the output flickers

//*****************************************************************************************//
//                                      Initial Setup                                      //
//*****************************************************************************************//
void setup() {
  Serial.begin(115200);
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));

  //define inputs and output pins mode
  pinMode(Magnet, OUTPUT);                                          //set magnet pin as output
  pinMode(Motor_Left_PWM_PIN, OUTPUT);                              //set Motor_Left_PWM_PIN pin as output
  pinMode(Motor_Left_DIR, OUTPUT);                                  //set Motor_Left_DIR pin as output
  pinMode(Motor_Right_PWM_PIN, OUTPUT);                             //set Motor_Right_PWM_PIN pin as output
  pinMode(Motor_Right_DIR, OUTPUT);                                 //set Motor_Right_DIR pin as output
  pinMode(Buzzer, OUTPUT);                                          //set Buzzer pin as output
  pinMode(Coil_Signal, INPUT);                                      //set Coil_Signal pin as input

  //define our servos
  Servo_ARM1.attach(Servo_ARM1_signal);                             //attaches the Arm servo on Servo_ARM1_signal pin to the servo object
  Servo_ARM2.attach(Servo_ARM2_signal);                             //attaches the Magnet servo on Servo_ARM2_signal pin to the servo object
  Servo_ARM1.write(Servo_ARM_postion);                              //sets the arm servo position according to the current value
  Servo_ARM2.write(180 - Servo_ARM_postion);                        //sets the magnet servo position according to the current value

  //turn everything off
  digitalWrite(Magnet, LOW);                                        //init Magnet pin to low
  digitalWrite(Motor_Left_PWM_PIN, LOW);                            //init Motor_Left_PWM_PIN pin to low
  digitalWrite(Motor_Left_DIR, LOW);                                //init Motor_Left_DIR pin to low
  digitalWrite(Motor_Right_PWM_PIN, LOW);                           //init Motor_Right_PWM_PIN pin to low
  digitalWrite(Motor_Right_DIR, LOW);                               //init Motor_Right_DIR pin to low
  digitalWrite(Buzzer, LOW);                                        //init Buzzer pin to low

  delay(500);                                                       //wait for everything to get ready
}

//*****************************************************************************************//
//                                      MAIN LOOP                                          //
//*****************************************************************************************//
void loop()
{
  Usb.Task();

  if (PS3.PS3Connected || PS3.PS3NavigationConnected) {

    if (PS3.getButtonClick(RIGHT)) {                                //comand to turn Right
      analogWrite(Motor_Left_PWM_PIN, Motor_Left_PWM);              //Motor_Left_EN pin to low
      digitalWrite(Motor_Left_DIR, LOW);                            //Motor_Left_DIR pin to low
      analogWrite(Motor_Right_PWM_PIN, Motor_Right_PWM);            //Motor_Right_EN pin to low
      digitalWrite(Motor_Right_DIR, HIGH);                          //Motor_Right_DIR pin to low
    }
    if (PS3.getButtonClick(LEFT)) {                                 //comand to turn Left
      analogWrite(Motor_Left_PWM_PIN, Motor_Left_PWM);              //Motor_Left_EN pin to low
      digitalWrite(Motor_Left_DIR, HIGH);                           //Motor_Left_DIR pin to low
      analogWrite(Motor_Right_PWM_PIN, Motor_Right_PWM);            //Motor_Right_EN pin to low
      digitalWrite(Motor_Right_DIR, LOW);                           //Motor_Right_DIR pin to low
    }
    if (PS3.getButtonClick(UP)) {                                   //comand to move Forword
      analogWrite(Motor_Left_PWM_PIN, Motor_Left_PWM);              //Motor_Left_EN pin to low
      digitalWrite(Motor_Left_DIR, HIGH);                           //Motor_Left_DIR pin to low
      analogWrite(Motor_Right_PWM_PIN, Motor_Right_PWM);            //Motor_Right_EN pin to low
      digitalWrite(Motor_Right_DIR, HIGH);                          //Motor_Right_DIR pin to low
    }
    if (PS3.getButtonClick(DOWN)) {                                 //comand to move Backword
      analogWrite(Motor_Left_PWM_PIN, Motor_Left_PWM);              //Motor_Left_EN pin to low
      digitalWrite(Motor_Left_DIR, LOW);                            //Motor_Left_DIR pin to low
      analogWrite(Motor_Right_PWM_PIN, Motor_Right_PWM);            //Motor_Right_EN pin to low
      digitalWrite(Motor_Right_DIR, LOW);                           //Motor_Right_DIR pin to low
    }
    if (!PS3.getButtonPress(DOWN) && !PS3.getButtonPress(UP) && !PS3.getButtonPress(LEFT) && !PS3.getButtonPress(RIGHT)) {
      analogWrite(Motor_Left_PWM_PIN, 0);                           //Motor_Left_EN pin to low
      digitalWrite(Motor_Left_DIR, LOW);                            //Motor_Left_DIR pin to low
      analogWrite(Motor_Right_PWM_PIN, 0);                          //Motor_Right_EN pin to low
      digitalWrite(Motor_Right_DIR, LOW);                           //Motor_Right_DIR pin to low
    
    if (PS3.getButtonPress(CROSS)) {                                //comand to set speed to 1/4
      Motor_Left_PWM = 63;
      Motor_Right_PWM = 63;
    }
    if (PS3.getButtonPress(CIRCLE)) {                               //comand to set speed to 2/4
      Motor_Left_PWM = 127;
      Motor_Right_PWM = 127;
    }
    if (PS3.getButtonPress(TRIANGLE)) {                             //comand to set speed to 3/4
      Motor_Left_PWM = 191;
      Motor_Right_PWM = 191;
    }
    if (PS3.getButtonPress(SQUARE)) {                               //comand to set speed to 4/4
      Motor_Left_PWM = 255;
      Motor_Right_PWM = 255;
    }
    if (PS3.getButtonPress(L1)) {                                   //comand to moe servo up
      Servo_ARM_postion ++;                                         //a variable to store the postion for arm servo and init it to 0 Deg
      if (Servo_ARM_postion > Servo_ARM_postion_max )Servo_ARM_postion = Servo_ARM_postion_max;                                 //define the max up degree for arm servo
      Servo_ARM1.write(Servo_ARM_postion);                          //sets the arm servo position according to the current value
      Servo_ARM2.write(180 - Servo_ARM_postion);                    //sets the magnet servo position according to the current value
      delay(2);
    }
    if (PS3.getButtonPress(R1)) {                                   //comand to moe servo up
      Servo_ARM_postion --;                                         //a variable to store the postion for arm servo and init it to 0 Deg
      if (Servo_ARM_postion > Servo_ARM_postion_min)Servo_ARM_postion = Servo_ARM_postion_min;                                 //define the max up degree for arm servo
      Servo_ARM1.write(Servo_ARM_postion);                          //sets the arm servo position according to the current value
      Servo_ARM2.write(180 - Servo_ARM_postion);                    //sets the magnet servo position according to the current value
      delay(2);
    }
      if (PS3.getButtonClick(START)) {                              //comand to open magnet
      digitalWrite(Magnet, HIGH); 
    }
      if (PS3.getButtonClick(SELECT)) {                             //comand to open magnet
      digitalWrite(Magnet, LOW); 
    }
  }

  //detect mine alarm
  if (digitalRead(Coil_Signal) == HIGH)                             //if a mine detected
    digitalWrite(Buzzer, HIGH);                                     //turn on Buzzer
  else                                                              //if a mine not detected
    digitalWrite(Buzzer, LOW);                                      //turn off Buzzer
}

