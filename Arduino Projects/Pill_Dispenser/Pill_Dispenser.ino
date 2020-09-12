//*****************************************************************************************//
//                                      Libraries included
//*****************************************************************************************//

#include "OMMenuMgr.h"                    // for LCD Menus
#include <avr/pgmspace.h>                 // for memory storage in program space (bigFont)
#include "CONFIG.h"                       // for calling configuration
#include <VarSpeedServo.h>                // for controlling servo motor of every bank
#include <EasyBuzzer.h>                   // for controlling buzzer
#include <EEPROM.h>                       // for saving virables to eeprom

#ifdef NODEMCU_USED
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>                 // https://github.com/tzapu/WiFiManager
WiFiServer server(80);                   // Set web server port number to 80
String header;                           // Variable to store the HTTP request
#endif

#ifdef LCD_NORMAL
#include <LiquidCrystal.h>                // for LCD 
#endif
#ifdef LCD_I2C
#include <LiquidCrystal_I2C.h>            // for I2C LCD
#endif

#include <Wire.h>                         // for using I2C LCD library & RTC 
#include "RTClib.h"
#include <time.h>
#include <TimeAlarms.h>;

RTC_DS1307 RTC;

//*****************************************************************************************//
//                                   I2C LCD Definition
//*****************************************************************************************//

#ifdef LCD_I2C
// Set the LCD address to 0x27 (Could be 0x20 if solder jumpers are bridged!)
//
// Set the pins on the I2C chip used for LCD connections:
//                              addr,en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(LCD_I2C_ADDR, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
#endif
#ifdef LCD_NORMAL
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
#endif

//*****************************************************************************************//
//                                   Buttons Definition
//*****************************************************************************************//

// mapping of digital button values for menu
#ifdef BUTTON_MODE_DIGITAL
int  myButtons[5][2] = {
  {BUTTON_FORWARD_PIN, BUTTON_FORWARD},
  {BUTTON_INCREASE_PIN, BUTTON_INCREASE},
  {BUTTON_DECREASE_PIN, BUTTON_DECREASE},
  {BUTTON_BACK_PIN, BUTTON_BACK},
  {BUTTON_SELECT_PIN, BUTTON_SELECT}
};
#endif
#ifdef BUTTON_MODE_ENCODER
int  myEncoder[3][2] = {
  {ENCODER_SW_PIN, BUTTON_FORWARD},
  {ENCODER_CLK_PIN, BUTTON_INCREASE},
  {ENCODER_DT_PIN, BUTTON_DECREASE},
};
#endif

//*****************************************************************************************//
//                                Variables to be Controlled
//*****************************************************************************************//

VarSpeedServo servo_bank1;  // create servo object to control a servo for bank 1
VarSpeedServo servo_bank2;  // create servo object to control a servo for bank 2

byte selected_bank1_timer = _1H;                    //to save current selected bank 1 timer
byte selected_bank2_timer = _1H;                    //to save current selected bank 2 timer
byte selected_time_scaler = _1X;                    //to save timer scalers (1x, 2x ,4x ,.....)
bool wifi_enabled_flag    = false;

//*****************************************************************************************//
//                                LCD MENUS configuration
//*****************************************************************************************//


/*-------------------------------MENU TREE-------------------------------------------------
  --Root
   |___>Bank 1 Timer
         |___>1H
         |___>1.5H
         |___>2H
         |___>2.5H
         |___>3H
         |___>3.5H
         |___>4H
         |___>4.5H
         |___>5H
         |___>5.5H
         |___>6H
         |___>6.5H
         |___>7H
         |___>7.5H
         |___>8H
         |___>8.5H
         |___>9H
         |___>9.5H
         |___>10H
         |___>10.5H
         |___>11H
         |___>11.5H
         |___>12H
    |___>Bank 2 Timer
         |___>1H
         |___>1.5H
         |___>2H
         |___>2.5H
         |___>3H
         |___>3.5H
         |___>4H
         |___>4.5H
         |___>5H
         |___>5.5H
         |___>6H
         |___>6.5H
         |___>7H
         |___>7.5H
         |___>8H
         |___>8.5H
         |___>9H
         |___>9.5H
         |___>10H
         |___>10.5H
         |___>11H
         |___>11.5H
         |___>12H
    |___>Settings
         |___>Update EEPROM
         |___>Enable Wifi
         |___>TEST System
              |___>TEST Bank 1
              |___>TEST Bank 2
              |___>TEST Buzzer
         |___>Timer Scaler
              |___>1X
              |___>2X
              |___>4X
              |___>8X
              |___>10X
              |___>15X
              |___>20X
              |___>30X
              |___>60X
*/

// Create a list of states and values for a select input Alarm Timers
MENU_SELECT_ITEM  sel_time_1h = { _1H, {"1 HOUR"} };
MENU_SELECT_ITEM  sel_time_15h = { _1_5H, {"1.5 HOUR"} };
MENU_SELECT_ITEM  sel_time_2h = {_2H, {"2 HOURs"} };
MENU_SELECT_ITEM  sel_time_25h = {_2_5H, {"2.5 HOURs"} };
MENU_SELECT_ITEM  sel_time_3h = { _3H, {"3 HOURs"} };
MENU_SELECT_ITEM  sel_time_35h = { _3_5H, {"3.5 HOURs"} };
MENU_SELECT_ITEM  sel_time_4h = { _4H, {"4 HOURs"} };
MENU_SELECT_ITEM  sel_time_45h = { _4_5H, {"4.5 HOURs"} };
MENU_SELECT_ITEM  sel_time_5h = { _5H, {"5 HOURs"} };
MENU_SELECT_ITEM  sel_time_55h = { _5_5H, {"5.5 HOURs"} };
MENU_SELECT_ITEM  sel_time_6h = { _6H, {"6 HOURs"} };
MENU_SELECT_ITEM  sel_time_65h = { _6_5H, {"6.5 HOURs"} };
MENU_SELECT_ITEM  sel_time_7h = { _7H, {"7 HOURs"} };
MENU_SELECT_ITEM  sel_time_75h = { _7_5H, {"7.5 HOURs"} };
MENU_SELECT_ITEM  sel_time_8h = { _8H, {"8 HOURs"} };
MENU_SELECT_ITEM  sel_time_85h = { _8_5H, {"8.5 HOURs"} };
MENU_SELECT_ITEM  sel_time_9h = { _9H, {"9 HOURs"} };
MENU_SELECT_ITEM  sel_time_95h = { _9_5H, {"9.5 HOURs"} };
MENU_SELECT_ITEM  sel_time_10h = { _10H, {"10 HOURs"} };
MENU_SELECT_ITEM  sel_time_105h = { _10_5H, {"10.5 HOURs"} };
MENU_SELECT_ITEM  sel_time_11h = { _11H, {"11 HOURs"} };
MENU_SELECT_ITEM  sel_time_115h = { _11_5H, {"11.5 HOURs"} };
MENU_SELECT_ITEM  sel_time_12h = { _12H, {"12 HOURs"} };

// Create a list of states and values for a select input Alarm Timers Scalers
MENU_SELECT_ITEM  sel_time_1x  = { _1X,  {"1X"} };
MENU_SELECT_ITEM  sel_time_2x  = { _2X,  {"2X"} };
MENU_SELECT_ITEM  sel_time_4x  = { _4X,  {"4X"} };
MENU_SELECT_ITEM  sel_time_8x  = { _8X,  {"8X"} };
MENU_SELECT_ITEM  sel_time_10x = { _10X, {"10X"} };
MENU_SELECT_ITEM  sel_time_15x = { _15X, {"15X"} };
MENU_SELECT_ITEM  sel_time_20x = { _20X, {"20X"} };
MENU_SELECT_ITEM  sel_time_30x = { _30X, {"30X"} };
MENU_SELECT_ITEM  sel_time_60x = { _60X, {"60X"} };

MENU_SELECT_LIST  state_time_alarm_list[]   = { &sel_time_1h, &sel_time_15h, &sel_time_2h, &sel_time_25h,
                                                &sel_time_3h, &sel_time_35h, &sel_time_4h, &sel_time_45h,
                                                &sel_time_5h, &sel_time_55h, &sel_time_6h, &sel_time_65h,
                                                &sel_time_7h, &sel_time_75h, &sel_time_8h, &sel_time_85h,
                                                &sel_time_9h, &sel_time_95h, &sel_time_10h, &sel_time_105h,
                                                &sel_time_11h, &sel_time_115h, &sel_time_12h
                                              };

MENU_SELECT_LIST  state_time_scaller_list[] = { &sel_time_1x, &sel_time_2x, &sel_time_4x, &sel_time_8x,
                                                &sel_time_10x, &sel_time_15x, &sel_time_20x, &sel_time_30x,
                                                &sel_time_60x
                                              };

// the special target for our state input
MENU_SELECT state_bank1_timer   = { &selected_bank1_timer, MENU_SELECT_SIZE(state_time_alarm_list), MENU_TARGET(&state_time_alarm_list) };
MENU_SELECT state_bank2_timer   = { &selected_bank2_timer, MENU_SELECT_SIZE(state_time_alarm_list), MENU_TARGET(&state_time_alarm_list) };
MENU_SELECT state_timer_scaler  = { &selected_time_scaler, MENU_SELECT_SIZE(state_time_scaller_list), MENU_TARGET(&state_time_scaller_list) };

////////////////////////////////     TYPE            MAX    MIN    TARGET
MENU_VALUE sel_bank1_timer      = { TYPE_SELECT,     0,     0,     MENU_TARGET(&state_bank1_timer) };
MENU_VALUE sel_bank2_timer      = { TYPE_SELECT,     0,     0,     MENU_TARGET(&state_bank2_timer) };
MENU_VALUE sel_timer_scaler     = { TYPE_SELECT,     0,     0,     MENU_TARGET(&state_timer_scaler) };

MENU_ITEM item_bank1_timer      = { {"BANK 1 Timer"}, ITEM_VALUE,  0,        MENU_TARGET(&sel_bank1_timer) };
MENU_ITEM item_bank2_timer      = { {"BANK 2 Timer"}, ITEM_VALUE,  0,        MENU_TARGET(&sel_bank2_timer) };
MENU_ITEM item_timer_scaler     = { {"Timer Scaler"}, ITEM_VALUE,  0,        MENU_TARGET(&sel_timer_scaler) };

// Testing sys menu
MENU_ITEM item_test_bank1       = { {"TEST BANK 1"},  ITEM_ACTION, 0,        MENU_TARGET(test_bank1_servo)};
MENU_ITEM item_test_bank2       = { {"TEST BANK 2"},  ITEM_ACTION, 0,        MENU_TARGET(test_bank2_servo)};
MENU_ITEM item_test_buzzer      = { {"TEST BUZZER"},  ITEM_ACTION, 0,        MENU_TARGET(test_buzzer) };
MENU_LIST menu_test_sys_list[]  = {&item_test_bank1, &item_test_bank2, &item_test_buzzer};
MENU_ITEM menu_test_sys         = { {"TEST SYSTEM"}, ITEM_MENU, MENU_SIZE(menu_test_sys_list),   MENU_TARGET(&menu_test_sys_list) };

// Settings menu
MENU_ITEM item_update_eeprom    = { {"Update EEPROM"},  ITEM_ACTION, 0,      MENU_TARGET(update_eeprom) };
MENU_LIST menu_settings_list[]  = {&item_update_eeprom, &item_timer_scaler};
MENU_ITEM menu_settings         = { {"Settings"}, ITEM_MENU, MENU_SIZE(menu_settings_list),   MENU_TARGET(&menu_settings_list) };

// Root menu
MENU_LIST root_list[]           = { &item_bank1_timer, &item_bank2_timer, &menu_settings};
MENU_ITEM menu_root             = { {"Root"},          ITEM_MENU,   MENU_SIZE(root_list)         ,    MENU_TARGET(&root_list) };


#ifdef BUTTON_MODE_DIGITAL
OMMenuMgr Menu(&menu_root, MENU_DIGITAL );
#endif
#ifdef BUTTON_MODE_ENCODER
OMMenuMgr Menu(&menu_root, MENU_ENCODER );
#endif


//*****************************************************************************************//
//                                      Initial Setup
//*****************************************************************************************//

void setup() {
  // put your setup code here, to run once:
  lcd.begin(LCD_COLS, LCD_ROWS);
  EasyBuzzer.setPin(BUZZER_PIN);

#ifdef FIRST_UPLOAD
  save_default_eeprom();
#endif

#ifdef LCD_I2C
  lcd.backlight();
#endif

#ifdef NODEMCU_USED
  // WiFiManager
  // Local intialization. Once its business is done, there is no need to keep it around
  WiFiManager wifiManager;

  // Uncomment and run it once, if you want to erase all the stored information
  //wifiManager.resetSettings();

  // set custom ip for portal
  //wifiManager.setAPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));

  // fetches ssid and pass from eeprom and tries to connect
  // if it does not connect it starts an access point with the specified name
  // here  "AutoConnectAP"
  // and goes into a blocking loop awaiting configuration
  wifiManager.autoConnect("Pill Dispenser");
  // or use this for auto generated name ESP + ChipID
  //wifiManager.autoConnect();
  server.begin();
#endif

  bigFont_init();
  splash_screan();           //Create Splash screan
  servo_bank1.attach(SERVO_BANK_1_PIN);
  servo_bank2.attach(SERVO_BANK_2_PIN);
  Menu.setDrawHandler(uiDraw);
  Menu.setExitHandler(uiClear);
  Menu.setDigitalButtonPins(myButtons);

#ifdef BUTTON_MODE_DIGITAL
  Menu.setDigitalButtonPins(myButtons);
#endif

#ifdef BUTTON_MODE_ENCODER
  Menu.setDigitalButtonPins(myEncoder);
#endif

  Menu.enable(true);
}

//*****************************************************************************************//
//                                        MAIN LOOP
//*****************************************************************************************//

void loop() {
  // put your main code here, to run repeatedly:
  Menu.checkInput();
  EasyBuzzer.update();
}

//*****************************************************************************************//
//                                     HAL Functions
//*****************************************************************************************//

void Extract_Pill(VarSpeedServo myservo) {
  myservo.write(OPEN_BANK_ANGLE);
  delay(OPEN_BANK_DELAY_MS);
  myservo.write(CLOSE_BANK_ANGLE);
}

void Buzzer(char mode) {
  int frequency = 500;
  switch (mode)
  {
    case _single_beep:
      /*
        Beep at a given frequency an specific number of times.
        The default onDuration and offDuration is set in Config.h file.
      */
      EasyBuzzer.beep(
        frequency,  // Frequency in Hertz(HZ).
        1   // The number of beeps.
      );
      break;
    case _two_beep:
      /*
        Beep at a given frequency an specific number of times.
        The default onDuration and offDuration is set in Config.h file.
      */
      EasyBuzzer.beep(
        frequency,  // Frequency in Hertz(HZ).
        2   // The number of beeps.
      );
      break;
    case _continous_beep:
      /* Beep continuously at a given frequency. */
      EasyBuzzer.beep(
        frequency // Frequency in Hertz(HZ).
      );
      break;
    case _stop_beep:
      EasyBuzzer.stopBeep();
      break;
    default:
      EasyBuzzer.stopBeep();
      break;
  }
}

//*****************************************************************************************//
//                                     EEPROM Functions
//*****************************************************************************************//

void update_eeprom() {
  lcd.clear();
  Menu.enable(false);
  EEPROM.update(1, selected_bank1_timer);
  EEPROM.update(2, selected_bank2_timer);
  EEPROM.update(3, selected_time_scaler);
  EEPROM.update(4, wifi_enabled_flag);
  lcd.print("EEPROM UPDATED!");
  lcd.setCursor(0, 1);
  lcd.print("Enter to return");
  while ( Menu.checkInput() != BUTTON_SELECT ) {
    ; // wait!
  }
  Menu.enable(true);
  lcd.clear();
}

void read_eeprom() {
  selected_bank1_timer = EEPROM.read(1);
  selected_bank2_timer = EEPROM.read(2);
  selected_time_scaler = EEPROM.read(3);
  wifi_enabled_flag    = EEPROM.read(3);
}

#ifdef FIRST_UPLOAD
void save_default_eeprom() {
  EEPROM.update(1, _1H);
  EEPROM.update(2, _1H);
  EEPROM.update(3, _1X);
  EEPROM.update(4, false);
}
#endif

//*****************************************************************************************//
//                                     TESTs Functions
//*****************************************************************************************//

void test_bank1_servo() {
  lcd.clear();
  Menu.enable(false);
  lcd.print("EXTRACT PILL B_1");
  Extract_Pill(servo_bank1);
  lcd.setCursor(0, 1);
  lcd.print("Enter to return");
  while ( Menu.checkInput() != BUTTON_SELECT ) {
    ; // wait!
  }
  Menu.enable(true);
  lcd.clear();
}

void test_bank2_servo() {
  lcd.clear();
  Menu.enable(false);
  lcd.print("EXTRACT PILL B_2");
  Extract_Pill(servo_bank2);
  lcd.setCursor(0, 1);
  lcd.print("Enter to return");
  while ( Menu.checkInput() != BUTTON_SELECT ) {
    ; // wait!
  }
  Menu.enable(true);
  lcd.clear();
}

void test_buzzer() {
  lcd.clear();
  Menu.enable(false);
  lcd.print("TESTING BUZZER");
  Buzzer(_continous_beep);
  lcd.setCursor(0, 1);
  lcd.print("Enter to return");
  while ( Menu.checkInput() != BUTTON_SELECT ) {
    ; // wait!
  }
  Menu.enable(true);
  lcd.clear();
  Buzzer(_stop_beep);
}

//*****************************************************************************************//
//                                     Animations Functions
//*****************************************************************************************//

void splash_screan() {
  //Create Splash screan
  lcd.clear();
  writeBigString("Y", 1, 0);
  delay(500);
  writeBigString("A", 4, 0);
  delay(500);
  writeBigString("S", 7, 0);
  delay(500);
  lcd.setCursor(10, 1);
  lcd.print(" ELEC");
  delay(1500);
}

//*****************************************************************************************//
//                                     OMManger Functions
//*****************************************************************************************//

void uiClear() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("YAS");
}

void uiDraw(char* p_text, int p_row, int p_col, int len) {
  lcd.setCursor(p_col, p_row);

  for ( int i = 0; i < len; i++ ) {
    if ( p_text[i] < '!' || p_text[i] > '~' )
      lcd.write(' ');
    else
      lcd.write(p_text[i]);
  }
}

//*****************************************************************************************//
//                                      BIG FONT Setup
//*****************************************************************************************//

byte col, row, nb = 0, bc = 0;                            // general(BigFont)
byte bb[8];                                               // byte buffer for reading from PROGMEM(BigFont)

//Variables for BIGFont
const char custom[][8] PROGMEM = {                        // Custom character definitions
  { 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00 }, // char 1
  { 0x18, 0x1C, 0x1E, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F }, // char 2
  { 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x0F, 0x07, 0x03 }, // char 3
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F }, // char 4
  { 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1E, 0x1C, 0x18 }, // char 5
  { 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x1F, 0x1F }, // char 6
  { 0x1F, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F }, // char 7
  { 0x03, 0x07, 0x0F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F }  // char 8
};

// BIG FONT Character Set
// - Each character coded as 1-4 byte sets {top_row(0), top_row(1)... bot_row(0), bot_row(0)..."}
// - number of bytes terminated with 0x00; Character is made from [number_of_bytes/2] wide, 2 high
// - codes are: 0x01-0x08 => custom characters, 0x20 => space, 0xFF => black square

const byte bigChars[][8] PROGMEM = {
  { 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Space
  { 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // !
  { 0x05, 0x05, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00 }, // "
  { 0x04, 0xFF, 0x04, 0xFF, 0x04, 0x01, 0xFF, 0x01 }, // #
  { 0x08, 0xFF, 0x06, 0x07, 0xFF, 0x05, 0x00, 0x00 }, // $
  { 0x01, 0x20, 0x04, 0x01, 0x04, 0x01, 0x20, 0x04 }, // %
  { 0x08, 0x06, 0x02, 0x20, 0x03, 0x07, 0x02, 0x04 }, // &
  { 0x05, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // '
  { 0x08, 0x01, 0x03, 0x04, 0x00, 0x00, 0x00, 0x00 }, // (
  { 0x01, 0x02, 0x04, 0x05, 0x00, 0x00, 0x00, 0x00 }, // )
  { 0x01, 0x04, 0x04, 0x01, 0x04, 0x01, 0x01, 0x04 }, // *
  { 0x04, 0xFF, 0x04, 0x01, 0xFF, 0x01, 0x00, 0x00 }, // +
  { 0x20, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, //
  { 0x04, 0x04, 0x04, 0x20, 0x20, 0x20, 0x00, 0x00 }, // -
  { 0x20, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // .
  { 0x20, 0x20, 0x04, 0x01, 0x04, 0x01, 0x20, 0x20 }, // /
  { 0x08, 0x01, 0x02, 0x03, 0x04, 0x05, 0x00, 0x00 }, // 0
  { 0x01, 0x02, 0x20, 0x04, 0xFF, 0x04, 0x00, 0x00 }, // 1
  { 0x06, 0x06, 0x02, 0xFF, 0x07, 0x07, 0x00, 0x00 }, // 2
  { 0x01, 0x06, 0x02, 0x04, 0x07, 0x05, 0x00, 0x00 }, // 3
  { 0x03, 0x04, 0xFF, 0x20, 0x20, 0xFF, 0x00, 0x00 }, // 4
  { 0xFF, 0x06, 0x06, 0x07, 0x07, 0x05, 0x00, 0x00 }, // 5
  { 0x08, 0x06, 0x06, 0x03, 0x07, 0x05, 0x00, 0x00 }, // 6
  { 0x01, 0x01, 0x02, 0x20, 0x08, 0x20, 0x00, 0x00 }, // 7
  { 0x08, 0x06, 0x02, 0x03, 0x07, 0x05, 0x00, 0x00 }, // 8
  { 0x08, 0x06, 0x02, 0x07, 0x07, 0x05, 0x00, 0x00 }, // 9
  { 0xA5, 0xA5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // :
  { 0x04, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // ;
  { 0x20, 0x04, 0x01, 0x01, 0x01, 0x04, 0x00, 0x00 }, // <
  { 0x04, 0x04, 0x04, 0x01, 0x01, 0x01, 0x00, 0x00 }, // =
  { 0x01, 0x04, 0x20, 0x04, 0x01, 0x01, 0x00, 0x00 }, // >
  { 0x01, 0x06, 0x02, 0x20, 0x07, 0x20, 0x00, 0x00 }, // ?
  { 0x08, 0x06, 0x02, 0x03, 0x04, 0x04, 0x00, 0x00 }, // @
  { 0x08, 0x06, 0x02, 0xFF, 0x20, 0xFF, 0x00, 0x00 }, // A
  { 0xFF, 0x06, 0x05, 0xFF, 0x07, 0x02, 0x00, 0x00 }, // B
  { 0x08, 0x01, 0x01, 0x03, 0x04, 0x04, 0x00, 0x00 }, // C
  { 0xFF, 0x01, 0x02, 0xFF, 0x04, 0x05, 0x00, 0x00 }, // D
  { 0xFF, 0x06, 0x06, 0xFF, 0x07, 0x07, 0x00, 0x00 }, // E
  { 0xFF, 0x06, 0x06, 0xFF, 0x20, 0x20, 0x00, 0x00 }, // F
  { 0x08, 0x01, 0x01, 0x03, 0x04, 0x02, 0x00, 0x00 }, // G
  { 0xFF, 0x04, 0xFF, 0xFF, 0x20, 0xFF, 0x00, 0x00 }, // H
  { 0x01, 0xFF, 0x01, 0x04, 0xFF, 0x04, 0x00, 0x00 }, // I
  { 0x20, 0x20, 0xFF, 0x04, 0x04, 0x05, 0x00, 0x00 }, // J
  { 0xFF, 0x04, 0x05, 0xFF, 0x20, 0x02, 0x00, 0x00 }, // K
  { 0xFF, 0x20, 0x20, 0xFF, 0x04, 0x04, 0x00, 0x00 }, // L
  { 0x08, 0x03, 0x05, 0x02, 0xFF, 0x20, 0x20, 0xFF }, // M
  { 0xFF, 0x02, 0x20, 0xFF, 0xFF, 0x20, 0x03, 0xFF }, // N
  { 0x08, 0x01, 0x02, 0x03, 0x04, 0x05, 0x00, 0x00 }, // 0
  { 0x08, 0x06, 0x02, 0xFF, 0x20, 0x20, 0x00, 0x00 }, // P
  { 0x08, 0x01, 0x02, 0x20, 0x03, 0x04, 0xFF, 0x04 }, // Q
  { 0xFF, 0x06, 0x02, 0xFF, 0x20, 0x02, 0x00, 0x00 }, // R
  { 0x08, 0x06, 0x06, 0x07, 0x07, 0x05, 0x00, 0x00 }, // S
  { 0x01, 0xFF, 0x01, 0x20, 0xFF, 0x20, 0x00, 0x00 }, // T
  { 0xFF, 0x20, 0xFF, 0x03, 0x04, 0x05, 0x00, 0x00 }, // U
  { 0x03, 0x20, 0x20, 0x05, 0x20, 0x02, 0x08, 0x20 }, // V
  { 0xFF, 0x20, 0x20, 0xFF, 0x03, 0x08, 0x02, 0x05 }, // W
  { 0x03, 0x04, 0x05, 0x08, 0x20, 0x02, 0x00, 0x00 }, // X
  { 0x03, 0x04, 0x05, 0x20, 0xFF, 0x20, 0x00, 0x00 }, // Y
  { 0x01, 0x06, 0x05, 0x08, 0x07, 0x04, 0x00, 0x00 }, // Z
  { 0xFF, 0x01, 0xFF, 0x04, 0x00, 0x00, 0x00, 0x00 }, // [
  { 0x01, 0x04, 0x20, 0x20, 0x20, 0x20, 0x01, 0x04 }, // Backslash
  { 0x01, 0xFF, 0x04, 0xFF, 0x00, 0x00, 0x00, 0x00 }, // ]
  { 0x08, 0x02, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00 }, // ^
  { 0x20, 0x20, 0x20, 0x04, 0x04, 0x04, 0x00, 0x00 }  // _
};
//(BigFont)
void bigFont_init() {
  for (nb = 0; nb < 8; nb++ ) {                 // create 8 custom characters
    for (bc = 0; bc < 8; bc++) bb[bc] = pgm_read_byte( &custom[nb][bc] );
    lcd.createChar ( nb + 1, bb );
  }
}

int writeBigChar(char ch, byte x, byte y) {
  if (ch < ' ' || ch > '_') return 0;               // If outside table range, do nothing
  nb = 0;                                           // character byte counter
  for (bc = 0; bc < 8; bc++) {
    bb[bc] = pgm_read_byte( &bigChars[ch - ' '][bc] ); // read 8 bytes from PROGMEM
    if (bb[bc] != 0) nb++;
  }

  bc = 0;
  for (row = y; row < y + 2; row++) {
    for (col = x; col < x + nb / 2; col++ ) {
      lcd.setCursor(col, row);                      // move to position
      lcd.write(bb[bc++]);                          // write byte and increment to next
    }
  }
  return nb / 2 - 1;                                  // returns number of columns used by char
}

// writeBigString: writes out each letter of string
void writeBigString(char *str, byte x, byte y) {
  char c;
  while ((c = *str++))
    x += writeBigChar(c, x, y) + 1;
}
