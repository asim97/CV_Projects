/*

*/

//=================================================================//=================================================================//
//                  PID Tempreture Control                         //                           Tasks LIST                            //
//=================================================================//=================================================================//
//                                                                 //                                                                 //
//   Sensor   ==>  LM35                   || pin{A0}               //   TASK 1 ==>  Temprature reading                 (OK)           //
//                                                                 //                                                                 //
//   Process  ==>  PID control            || pin{  }               //   TASK 2 ==>  Control Type                       (OK)           //
//                                                                 //                                                                 //
//   Output_1 ==>  Hetar                  || pin{D5}               //   TASK 3 ==>  Controling"PID Auto Tuned"         (--)           //
//                                                                 //                                                                 //
//   Output_2 ==>  Fan                    || pin{D6}               //   TASK 4 ==>  Controling"PID Manual Tuned"       (OK)           //
//                                                                 //                                                                 //
//   Display  ==> LCD using I2C           || pin{A4,A5}            //   TASK 5 ==>  Safty and Alarms                   (OK)           //
//                                                                 //                                                                 //
//   Control  ==> Custom 2x2 keypad       || pin{  }               //   TASK 6 ==>  Display & LCD                      (OK)           //
//                                                                 //                                                                 //
//   Password ==> 4x3 Keypad module       || pin{  }               //   TASK 7 ==>  Controlling Menue                  (OK)           //
//                                                                 //                                                                 //
//=================================================================//=================================================================//

#include <PID_v1.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Define PINs we'll be connecting to
#define Started_LED              0
#define Stoped_LED               1
#define PIN_INPUT_heater_top     A0
#define PIN_INPUT_heater_bottom  A1
#define PIN_OUTPUT_heater_top    5
#define PIN_OUTPUT_heater_bottom 6
#define PIN_OUTPUT_fan_top       7
#define PIN_OUTPUT_fan_bottom    3
#define PIN_OUTPUT_buzzer        4
#define buzzer_duration          5      //in ms
#define run_screen_refresh       1000   //in ms
#define buzzer_freq              1000   //in hz
#define max_set                  100    //degC
#define error_pin                2      //pin Digit 2 (enabled if read LOW)

//Input & Button Logic
const byte numOfInputs = 6;
const byte inputPins[numOfInputs] = {8, 9, 10, 11, 12, 13};
byte inputState[numOfInputs];
bool lastInputState[numOfInputs] = {LOW, LOW, LOW, LOW, LOW, LOW};
bool inputFlags[numOfInputs] = {LOW, LOW, LOW, LOW, LOW, LOW};
long lastDebounceTime[numOfInputs] = {0, 0, 0, 0, 0, 0};
long debounceDelay = 5;
bool run_pid = false;
unsigned long time_now = 0;
bool sys_error = false;
bool first_err_scr = true;

//Define LCD pins
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  /// define lcd I2C

//Functions declerd here
void setInputFlags();
void resolveInputFlags();
void parameterChange(byte key );
void inputAction(byte input);
void printScreen();
void run_screen();
void run_fan();
void read_temps();
void pid_start();
void check_start(byte i);
void error_detect (byte i);


//Define Variables we'll be connecting to
double Setpoint, Input_heater_top, Input_heater_bottom, Output_heater_top, Output_heater_bottom;

//Specify the links and initial tuning parameters
double kp_heater_top = 2, ki_heater_top = 5, kd_heater_top = 1, kp_heater_bottom = 1, ki_heater_bottom = 2, kd_heater_bottom = 1;
PID heater_topPID(&Input_heater_top, &Output_heater_top, &Setpoint, kp_heater_top, ki_heater_top, kd_heater_top, DIRECT);
PID heater_bottomPID(&Input_heater_bottom, &Output_heater_bottom, &Setpoint, kp_heater_bottom, ki_heater_bottom, kd_heater_bottom, DIRECT);
//LCD Menu Logic
byte currentScreen = 0;
///////////////////////////////////////////////// Main Screen {0} ////////////////////////////////////////////
const byte numOfScreens_main = 3;
byte currentScreen_main = 0;
const String screens_main[numOfScreens_main][2] = {{"=>Set Tempreture", "  Adjest PIDs"}, {"=>Adjest PID", "  About"},
  {"=>About", "  Set Tempreture"}
};
const byte parameters_main[numOfScreens_main] = {1, 2, 11};
//////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////// Set Tempretur Screen {1} ///////////////////////////////////
String screens_set[1][2] = {{"=>Set Tempreture", "  DegC"}};
//////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////// Adjest PIDs Screen {2} /////////////////////////////////////
const byte numOfScreens_adj = 2;
byte currentScreen_adj = 0;
const String screens_adj[numOfScreens_adj][2] = {{"=>PIDs TopHeater", "  PIDs BotHeater"}, {"=>PIDs BotHeater", "  PIDs TopHeater"}};
const byte parameters_adj[numOfScreens_adj] = {3, 4};
//////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////// PIDs TopHeater Screen {3} /////////////////////////////////////
const byte numOfScreens_top = 3;
byte currentScreen_top = 0;
const String screens_top[numOfScreens_top][2] = {{"=>TopHeater Kp", "  TopHeater Ki"}, {"=>TopHeater Ki", "  TopHeater Kd"}, {"=>TopHeater Kd", "  TopHeater Kp"}};
const byte parameters_top[numOfScreens_top] = {5, 6, 7};
//////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////// PIDs BotHeater Screen {4} /////////////////////////////////////
const byte numOfScreens_bot = 3;
byte currentScreen_bot = 0;
const String screens_bot[numOfScreens_bot][2] = {{"=>BotHeater Kp", "  BotHeater Ki"}, {"=>BotHeater Ki", "  BotHeater Kd"}, {"=>BotHeater Kd", "  BotHeater Kp"}};
const byte parameters_bot[numOfScreens_bot] = {8, 9, 10};
//////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////// Set TopHeater Kp Screen {5} ///////////////////////////////////
const String screens_topkp = "Set TopHeater Kp";
//////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////// Set TopHeater Ki Screen {6} ///////////////////////////////////
const String screens_topki = "Set TopHeater Ki";
//////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////// Set TopHeater Kd Screen {7} ///////////////////////////////////
const String screens_topkd = "Set TopHeater Kd";
//////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////// Set BotHeater Kp Screen {8} ///////////////////////////////////
const String screens_botkp  = "Set BotHeater Kp";
//////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////// Set BotHeater Ki Screen {9} ///////////////////////////////////
const String screens_botki = "Set BotHeater Ki";
//////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////// Set BotHeater Kd Screen {10} ///////////////////////////////////
const String screens_botkd  = "Set BotHeater Kd";
//////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////// About Screen {11} ////////////////////////////////////////////
const byte numOfScreens_about = 3;
byte currentScreen_about = 0;
const String screens_about[numOfScreens_about][2] = {{" Welcome to PID", " Controller SYS"}, {" Sofware  V1.1", " Hardware V1"},
  {" S/W and H/W by ", "  Mohamed Asim"}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////// Running Screen {12} ////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////// Error Screen {13} ////////////////////////////////////////////
void err_scr() {
  if (first_err_scr == true) {
    lcd.clear();
    lcd.print(" Warning Alarm! ");
    lcd.setCursor(0, 1);
    lcd.print(" System Stopped ");
    digitalWrite(PIN_OUTPUT_buzzer, HIGH);
  } else {
    lcd.clear();
    lcd.print(" Warning Alarm! ");
    lcd.setCursor(0, 1);
    lcd.print("  ERR_Code xxx ");
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

//=================================================================//
//                             SETUP                               //
//=================================================================//
void setup()
{ //define input and output pins mode
  for (int i = 0; i < numOfInputs; i++) {
    pinMode(inputPins[i], INPUT);
    digitalWrite(inputPins[i], HIGH); // pull-up 20k
  }
  pinMode(PIN_OUTPUT_buzzer, OUTPUT);
  pinMode(PIN_OUTPUT_fan_top, OUTPUT);
  pinMode(PIN_OUTPUT_fan_bottom, OUTPUT);
  pinMode(Started_LED , OUTPUT);
  pinMode(Stoped_LED , OUTPUT);

  pinMode(error_pin, INPUT);
  digitalWrite(error_pin, HIGH);

  //intalize lcd comunication
  lcd.begin(16, 2);
  //initialize the variables we're linked to
  read_temps();

  Setpoint = 35;

  //turn the PID on
  heater_topPID.SetMode(AUTOMATIC);
  heater_bottomPID.SetMode(AUTOMATIC);
}

//=================================================================//
//                        LOOP Function                            //
//=================================================================//
void loop()
{
  error_detect();                          //check error
  read_temps();
  if (run_pid && sys_error == false) {
    run_fan();
    pid_start();
    if (currentScreen == 12)
      run_screen();
  }
  else {
    analogWrite(PIN_OUTPUT_heater_top, 0);
    analogWrite(PIN_OUTPUT_heater_bottom, 0);
    digitalWrite(PIN_OUTPUT_fan_top, LOW);
    digitalWrite(PIN_OUTPUT_fan_bottom, LOW);
  }
  error_detect();                          //check error
  setInputFlags();
  resolveInputFlags();
}

//=================================================================//
//                           Functions                             //
//=================================================================//
void run_screen() {
  if (millis() > time_now + run_screen_refresh) {
    time_now = millis();
    lcd.clear();
    lcd.print(" System Running");
    lcd.setCursor(0, 1);
    lcd.print(Input_heater_top);
    lcd.print(" C ");
    lcd.setCursor(8, 1);
    lcd.print(Input_heater_bottom);
    lcd.print(" C");
  }
}
void run_fan() {
  if ( Input_heater_top > (Setpoint + 2))
    digitalWrite(PIN_OUTPUT_fan_top, HIGH);
  else
    digitalWrite(PIN_OUTPUT_fan_top, LOW);
  if ( Input_heater_bottom > (Setpoint + 2))
    digitalWrite(PIN_OUTPUT_fan_bottom, HIGH);
  else
    digitalWrite(PIN_OUTPUT_fan_bottom, LOW);
}

void read_temps() {
  Input_heater_top = (5.0 * analogRead(PIN_INPUT_heater_top) * 100.0) / 1024;
  Input_heater_bottom = (5.0 * analogRead(PIN_INPUT_heater_bottom) * 100.0) / 1024;
}
void pid_start() {
  heater_topPID.Compute();
  heater_bottomPID.Compute();
  analogWrite(PIN_OUTPUT_heater_top, Output_heater_top);
  analogWrite(PIN_OUTPUT_heater_bottom, Output_heater_bottom);
}

void check_start(byte i) {
  if (i == 4 ) {
    run_pid = true;
    if (sys_error == false) {
      currentScreen = 12;
      digitalWrite(Started_LED, HIGH);
      digitalWrite(Stoped_LED, LOW);
    }
  }
  if (i == 5 ) {
    run_pid = false;
    if (sys_error == false) {
      currentScreen = 0;
      digitalWrite(Started_LED, LOW);
      digitalWrite(Stoped_LED, HIGH);
    }
  }
}
void error_detect () {
  if (digitalRead(error_pin) == 0) {
    sys_error = true;
    run_pid = false;
    digitalWrite(Started_LED, LOW);
    digitalWrite(Stoped_LED, HIGH);
    err_scr();
    currentScreen = 13;
  }
}

//=================================================================//
//                   LCD and Buttons Function                      //
//=================================================================//
void setInputFlags() {
  for (int i = 0; i < numOfInputs; i++) {
    int reading = digitalRead(inputPins[i]);
    if (reading != lastInputState[i]) {
      lastDebounceTime[i] = millis();
    }
    if ((millis() - lastDebounceTime[i]) > debounceDelay) {
      if (reading != inputState[i]) {
        inputState[i] = reading;
        if (inputState[i] == HIGH) {
          inputFlags[i] = HIGH;
        }
      }
    }
    lastInputState[i] = reading;
  }
}

void resolveInputFlags() {
  for (int i = 0; i < numOfInputs; i++) {
    if (inputFlags[i] == HIGH) {
      inputAction(i);
      check_start(i);                           //run pid and leds
      inputFlags[i] = LOW;
      printScreen();                            //display on LCD
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////// menu system Screens ////////////////////////////////////

void inputAction(byte input) {
  switch (currentScreen) {
    case 0:
      if (input == 0) {
        if (currentScreen_main == 0) {
          currentScreen_main = numOfScreens_main - 1;
        } else {
          currentScreen_main--;
        }
      } else if (input == 1) {
        if (currentScreen_main == numOfScreens_main - 1) {
          currentScreen_main = 0;
        } else {
          currentScreen_main++;
        }
      } else if (input == 2) {
        parameterChange(0);
      } else if (input == 3) {
        parameterChange(1);
      }
      break;
    case 1:
      if (input == 0) {
        parameterChange(0);
      } else if (input == 1) {
        parameterChange(1);
      }
      if (input == 3) {
        currentScreen = 0;
      }
      break;
    case 2:
      if (input == 0) {
        if (currentScreen_adj == 0) {
          currentScreen_adj = numOfScreens_adj - 1;
        } else {
          currentScreen_adj--;
        }
      } else if (input == 1) {
        if (currentScreen_adj == numOfScreens_adj - 1) {
          currentScreen_adj = 0;
        } else {
          currentScreen_adj++;
        }
      } else if (input == 2) {
        parameterChange(0);
      } else if (input == 3) {
        parameterChange(1);
      }
      break;
    case 3:
      if (input == 0) {
        if (currentScreen_top == 0) {
          currentScreen_top = numOfScreens_top - 1;
        } else {
          currentScreen_top--;
        }
      } else if (input == 1) {
        if (currentScreen_top == numOfScreens_top - 1) {
          currentScreen_top = 0;
        } else {
          currentScreen_top++;
        }
      } else if (input == 2) {
        parameterChange(0);
      } else if (input == 3) {
        parameterChange(1);
      }
      break;
    case 4:
      if (input == 0) {
        if (currentScreen_bot == 0) {
          currentScreen_bot = numOfScreens_bot - 1;
        } else {
          currentScreen_bot--;
        }
      } else if (input == 1) {
        if (currentScreen_bot == numOfScreens_bot - 1) {
          currentScreen_bot = 0;
        } else {
          currentScreen_bot++;
        }
      } else if (input == 2) {
        parameterChange(0);
      } else if (input == 3) {
        parameterChange(1);
      }
      break;
    case 5:
      if (input == 0) {
        parameterChange(0);
      } else if (input == 1) {
        parameterChange(1);
      }
      if (input == 3) {
        currentScreen = 3;
      }
      break;
    case 6:
      if (input == 0) {
        parameterChange(0);
      } else if (input == 1) {
        parameterChange(1);
      }
      if (input == 3) {
        currentScreen = 3;
      }
      break;
    case 7:
      if (input == 0) {
        parameterChange(0);
      } else if (input == 1) {
        parameterChange(1);
      }
      if (input == 3) {
        currentScreen = 3;
      }
      break;
    case 8:
      if (input == 0) {
        parameterChange(0);
      } else if (input == 1) {
        parameterChange(1);
      }
      if (input == 3) {
        currentScreen = 4;
      }
      break;
    case 9:
      if (input == 0) {
        parameterChange(0);
      } else if (input == 1) {
        parameterChange(1);
      }
      if (input == 3) {
        currentScreen = 4;
      }
      break;
    case 10:
      if (input == 0) {
        parameterChange(0);
      } else if (input == 1) {
        parameterChange(1);
      }
      if (input == 3) {
        currentScreen = 4;
      }
      break;
    case 11:
      if (input == 0) {
        if (currentScreen_about == 0) {
          currentScreen_about = numOfScreens_about - 1;
        } else {
          currentScreen_about--;
        }
      } else if (input == 1) {
        if (currentScreen_about == numOfScreens_about - 1) {
          currentScreen_about = 0;
        } else {
          currentScreen_about++;
        }
      } else if (input == 3) {
        parameterChange(1);
      }
      break;
    case 13:
      if (input == 0)                         parameterChange(1);
      else if (input == 1)                    parameterChange(1);
      else if (input == 2)                    parameterChange(1);
      else if (input == 3)                    parameterChange(1);
      else if (input == 4)                    parameterChange(1);
      else if (input == 5)                    parameterChange(1);
      else if (input == 6)                    parameterChange(1);
      break;
    default:
      break;
  }

}

void parameterChange(byte key ) {
  switch (currentScreen) {
    case 0:
      if (key == 0) {
        currentScreen = parameters_main[currentScreen_main];
      } else if (key == 1) {
        currentScreen = 0;
      }
      break;
    case 1:
      if (key == 0) {
        if (Setpoint == max_set) {
          Setpoint = max_set;
        } else {
          Setpoint = Setpoint + 0.5;
        }
      } else if (key == 1) {
        if (Setpoint == 0 ) {
          Setpoint = 0;
        } else {
          Setpoint = Setpoint - 0.5;
        }
      }
      break;
    case 2:
      if (key == 0) {
        currentScreen = parameters_adj[currentScreen_adj];
      } else if (key == 1) {
        currentScreen = 0;
      }
      break;
    case 3:
      if (key == 0) {
        currentScreen = parameters_top[currentScreen_top];
      } else if (key == 1) {
        currentScreen = 2;
      }
      break;
    case 4:
      if (key == 0) {
        currentScreen = parameters_bot[currentScreen_bot];
      } else if (key == 1) {
        currentScreen = 2;
      }
      break;
    case 5:
      if (key == 0) {
        kp_heater_top = kp_heater_top + 0.1;
      } else if (key == 1) {
        if (kp_heater_top <= 0.1 ) {
          kp_heater_top = 0.1;
        } else {
          kp_heater_top = kp_heater_top - 0.1;
        }
      }
      break;
    case 6:
      if (key == 0) {
        ki_heater_top = ki_heater_top + 0.1;
      } else if (key == 1) {
        if (ki_heater_top <= 0.1 ) {
          ki_heater_top = 0.1;
        } else {
          ki_heater_top = ki_heater_top - 0.1;
        }
      }
      break;
    case 7:
      if (key == 0) {
        kd_heater_top = kd_heater_top + 0.1;
      } else if (key == 1) {
        if (kd_heater_top <= 0.1 ) {
          kd_heater_top = 0.1;
        } else {
          kd_heater_top = kd_heater_top - 0.1;
        }
      }
      break;
    case 8:
      if (key == 0) {
        kp_heater_bottom = kp_heater_bottom + 0.1;
      } else if (key == 1) {
        if (kp_heater_bottom <= 0.1 ) {
          kp_heater_bottom = 0.1;
        } else {
          kp_heater_bottom = kp_heater_bottom - 0.1;
        }
      }
      break;
    case 9:
      if (key == 0) {
        ki_heater_bottom = ki_heater_bottom + 0.1;
      } else if (key == 1) {
        if (ki_heater_bottom <= 0.1 ) {
          ki_heater_bottom = 0.1;
        } else {
          ki_heater_bottom = ki_heater_bottom - 0.1;
        }
      }
      break;
    case 10:
      if (key == 0) {
        kd_heater_bottom = kd_heater_bottom + 0.1;
      } else if (key == 1) {
        if (kd_heater_bottom <= 0.1 ) {
          kd_heater_bottom = 0.1;
        } else {
          kd_heater_bottom = kd_heater_bottom - 0.1;
        }
      }
      break;
    case 11:
      if (key == 1) {
        currentScreen = 0;
      }
      break;
    case 13:
      if (key == 1)
        first_err_scr = false;
      break;
    default:
      break;
  }

}

void printScreen() {
  switch (currentScreen) {
    case 0:
      lcd.clear();
      lcd.print(screens_main[currentScreen_main][0]);
      lcd.setCursor(0, 1);
      lcd.print(screens_main[currentScreen_main][1]);
      break;
    case 1:
      lcd.clear();
      lcd.print(screens_set[0][0]);
      lcd.setCursor(0, 1);
      lcd.print(Setpoint);
      lcd.print(screens_set[0][1]);
      break;
    case 2:
      lcd.clear();
      lcd.print(screens_adj[currentScreen_adj][0]);
      lcd.setCursor(0, 1);
      lcd.print(screens_adj[currentScreen_adj][1]);
      break;
    case 3:
      lcd.clear();
      lcd.print(screens_top[currentScreen_top][0]);
      lcd.setCursor(0, 1);
      lcd.print(screens_top[currentScreen_top][1]);
      break;
    case 4:
      lcd.clear();
      lcd.print(screens_bot[currentScreen_bot][0]);
      lcd.setCursor(0, 1);
      lcd.print(screens_bot[currentScreen_bot][1]);
      break;
    case 5:
      lcd.clear();
      lcd.print(screens_topkp);
      lcd.setCursor(0, 1);
      lcd.print(kp_heater_top);
      break;
    case 6:
      lcd.clear();
      lcd.print(screens_topki);
      lcd.setCursor(0, 1);
      lcd.print(ki_heater_top);
      break;
    case 7:
      lcd.clear();
      lcd.print(screens_topkd);
      lcd.setCursor(0, 1);
      lcd.print(kd_heater_top);
      break;
    case 8:
      lcd.clear();
      lcd.print(screens_botkp);
      lcd.setCursor(0, 1);
      lcd.print(kp_heater_bottom);
      break;
    case 9:
      lcd.clear();
      lcd.print(screens_botki);
      lcd.setCursor(0, 1);
      lcd.print(ki_heater_bottom);
      break;
    case 10:
      lcd.clear();
      lcd.print(screens_botkd);
      lcd.setCursor(0, 1);
      lcd.print(kd_heater_bottom);
      break;

    case 11:
      lcd.clear();
      lcd.print(screens_about[currentScreen_about][0]);
      lcd.setCursor(0, 1);
      lcd.print(screens_about[currentScreen_about][1]);
      break;
    case 13:
      err_scr();
      break;

    default:
      break;
  }
}
