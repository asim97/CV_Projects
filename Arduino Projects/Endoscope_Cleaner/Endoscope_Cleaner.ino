/*
  lcd menus

*/


/*

  //                            //============================//
  //                            //    Choose Program  {1}     //
  //                            //============================//
  //                            //                            //
  //                            //  Program 1 ==>  {4}        //
  //                            //                            //
  //                            //  Program 1 ==>  {5}        //
  //                            //                            //
  //                            //  Program 1 ==>  {6}        //
  //                            //                            //
  //                            //  Program 1 ==>  {7}        //
  //                            //                            //
  //                            //  Program 1 ==>  {8}        //
  //                            //                            //
  //============================//============================//
  //         main {0}           //         Settings {2}       //
  //============================//============================//
  //                            //                            //
  //  Choose Program  ==>  {1}  //  Setting 1 ==>  {9}        //
  //                            //                            //
  //  Settings        ==>  {2}  //  Setting 1 ==>  {10}       //
  //                            //                            //
  //  About           ==>  {3}  //  Setting 1 ==>  {11}       //
  //                            //                            //
  //============================//  Setting 1 ==>  {12}       //
  //                            //                            //
  //                            //  Setting 1 ==>  {13}       //
  //                            //                            //
  //                            //============================//
  //                            //         About {3}          //
  //                            //============================//
  //                            //                            //
  //                            //  Page 1    ==>  {14}       //
  //                            //                            //
  //                            //  Page 2    ==>  {15}       //
  //                            //                            //
  //                            //  Page 3    ==>  {16}       //
  //                            //                            //
  //                            //============================//

*/

#include <LiquidCrystal.h>


#define buzzer_duration          5      //in ms
#define run_screen_refresh       1000   //in ms
#define enter                    1
#define back                     0

#define up_button                0
#define down_button              1
#define right_button             2
#define left_button              3 
#define start_button             4
#define stop_button              5

#define main                     0
#define programs                 1
#define settings                 2
#define about                    3


//Input & Button Logic

const byte numOfInputs = 6;
const byte inputPins[numOfInputs] = {2, 21, 21,2, 2, 2};
byte inputState[numOfInputs];
bool lastInputState[numOfInputs] = {LOW, LOW, LOW, LOW, LOW, LOW};
bool inputFlags[numOfInputs] = {LOW, LOW, LOW, LOW, LOW, LOW};
long lastDebounceTime[numOfInputs] = {0, 0, 0, 0, 0, 0};
long debounceDelay = 5;

unsigned long time_now;
bool sys_error = false;
bool first_err_scr = true;
bool run_sys = false;

LiquidCrystal lcd(PA3, PD6, PB0, PB1 , PB2, PB3);

//Functions declerd here
void setInputFlags();
void resolveInputFlags();
void parameterChange(byte key );
void inputAction(byte input);

//LCD Menu Logic
byte currentScreen = 0;


///////////////////////////////////////////////// Main Screen {0} ////////////////////////////////////////////
const byte numOfScreens_main = 3;
byte currentScreen_main = 0;
const String screens_main[numOfScreens_main][2] = {
  {"=>Choose Program", "  Settings"},
  {"=>Settings", "  About"},
  {"=>About", "  Choose Program"}
};
const byte parameters_main[numOfScreens_main] = {1, 2, 3};
//////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////// Choose Program Screen {1} ///////////////////////////////////   ////modify when data avilable
const byte numOfScreens_pro = 5;
byte currentScreen_pro = 0;
const String screens_pro[numOfScreens_pro][2] = {
  {"=>Program 1", "  Program 2"},
  {"=>Program 2", "  Program 3"},
  {"=>Program 3", "  Program 4"},
  {"=>Program 4", "  Program 5"},
  {"=>Program 5", "  Program 1"},
};
const byte parameters_pro[numOfScreens_pro] = {4, 5, 6, 7, 8}; ////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////// Settings Screen {2} /////////////////////////////////////
const byte numOfScreens_set = 3;
byte currentScreen_set = 0;
const String screens_set[numOfScreens_set][2] = {{"=>PIDs TopHeater", "  PIDs BotHeater"}, {"=>PIDs BotHeater", "  PIDs TopHeater"}};
const byte parameters_set[numOfScreens_set] = {3, 4};
//////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////// About Screen {3} ////////////////////////////////////////////
const byte numOfScreens_about = 3;
byte currentScreen_about = 0;
const String screens_about[numOfScreens_about][2] = {{" Welcome to PID", " Controller SYS"}, {" Sofware  V1.1", " Hardware V1"},
  {" S/W and H/W by ", "  Mohamed Asim"}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < numOfInputs; i++) {
    pinMode(inputPins[i], INPUT);
    digitalWrite(inputPins[i], HIGH); // pull-up 20k
  }
}
void loop() {
  // put your main code here, to run repeatedly:

  if (run_sys && sys_error == false) {
    sys_start();
    if (currentScreen == 12)
      run_screen();
  }
  else {

  }
  printScreen();
 // setInputFlags();
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
  }
}

void sys_start() {
  

}

void check_start(byte i) {
  if (i == start_button )
    run_sys = true;

  if (i == stop_button ) {
    run_sys = false;
    currentScreen = 0;
  }
}


void setInputFlags() {
  for (byte i = 0; i < numOfInputs; i++) {
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
  for (byte i = 0; i < numOfInputs; i++) {
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
    case main:
      if (input == up_button) {
        if (currentScreen_main == 0) {
          currentScreen_main = numOfScreens_main - 1;
        } else {
          currentScreen_main--;
        }
      } else if (input == down_button) {
        if (currentScreen_main == numOfScreens_main - 1) {
          currentScreen_main = 0;
        } else {
          currentScreen_main++;
        }
      } else if (input == right_button) {
        parameterChange(enter);
      } else if (input == left_button) {
        parameterChange(back);
      }
      break;
    case programs:
      if (input == up_button) {
        if (currentScreen_pro == 0) {
          currentScreen_pro = numOfScreens_pro - 1;
        } else {
          currentScreen_pro--;
        }
      } else if (input == down_button) {
        if (currentScreen_pro == numOfScreens_pro - 1) {
          currentScreen_pro = 0;
        } else {
          currentScreen_pro++;
        }
      } else if (input == right_button) {
        parameterChange(enter);
      } else if (input == left_button) {
        parameterChange(back);
      }
      break;
    case settings:
      if (up_button) {
        if (currentScreen_set == 0) {
          currentScreen_set = numOfScreens_set - 1;
        } else {
          currentScreen_set--;
        }
      } else if (input == 1) {
        if (currentScreen_set == numOfScreens_set - 1) {
          currentScreen_set = 0;
        } else {
          currentScreen_set++;
        }
      } else if (input == 2) {
        parameterChange(enter);
      } else if (input == 3) {
        parameterChange(back);
      }
      break;
    case about:
      if (input == up_button) {
        if (currentScreen_about == 0) {
          currentScreen_about = numOfScreens_about - 1;
        } else {
          currentScreen_about--;
        }
      } else if (input == down_button) {
        if (currentScreen_about == numOfScreens_about - 1) {
          currentScreen_about = 0;
        } else {
          currentScreen_about++;
        }
      } else if (input == left_button) {
        parameterChange(back);
      }
      break;

    default:
      break;
  }
}

void parameterChange(byte key ) {
  switch (currentScreen) {
    case main:
      if (key == enter) {
        currentScreen = parameters_main[currentScreen_main];
      } else if (key == back ) {
        currentScreen = main;
      }
      break;
    case programs:
      if (key == enter) {
        currentScreen = parameters_pro[currentScreen_pro];
      } else if (key == back) {
        currentScreen = main;
      }
      break;
    case settings:
      if (key == enter) {
        currentScreen = parameters_set[currentScreen_set];
      } else if (key == back) {
        currentScreen = main;
      }
      break;
    case about:
      if (key == back ) {
        currentScreen = main;
      }
      break;

    default:
      break;
  }
}

void printScreen() {
  switch (currentScreen) {
    case main:
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print(screens_main[currentScreen_main][0]);
      lcd.setCursor(1, 1);
      lcd.print(screens_main[currentScreen_main][1]);
      break;
    case programs:
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print(screens_pro[0][0]);
      lcd.setCursor(1, 1);
      lcd.print(screens_pro[0][1]);
      break;
    case settings:
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print(screens_set[currentScreen_set][0]);
      lcd.setCursor(1, 1);
      lcd.print(screens_set[currentScreen_set][1]);
      break;
    case about:
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print(screens_about[currentScreen_about][0]);
      lcd.setCursor(1, 1);
      lcd.print(screens_about[currentScreen_about][1]);
      break;

    default:
      break;
  }
}

