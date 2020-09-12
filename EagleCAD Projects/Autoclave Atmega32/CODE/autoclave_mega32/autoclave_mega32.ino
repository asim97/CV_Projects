
//*****************************************************************************************//
//                      ATMEGA 32 with BUBUINO Pinout (MightyCore)
//*****************************************************************************************//

#include <Button.h>
#include <avr/pgmspace.h>            // for memory storage in program space
#include <ShiftLCD.h>                // for using shift register as LCD interface driver
#include <EEPROM.h>
#include "max6675.h"
//autoclave libraries for heater
#include <Fuzzy.h>
#include "EasyBuzzer.h"
#include "defines_consts.h"

const unsigned int frequency = 1000;    //in hz
const byte button_buzzer_duration = 20; // in ms

const byte thermoDO = 7;
const byte thermoCS = 5;
const byte thermoCLK = 6;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

//arduino pins for heater
#define zero_cross  2 //sync pin
#define heater_triac  18 // traic pin
#define triac_fire_us 1000   //in uS

volatile byte angle_counter , angle_fired;

// Instantiating a Fuzzy object
Fuzzy *fuzzy = new Fuzzy();
float fuzzy_def_output;
float temp_error = 0;
float temp_read = 0;
float temp_desired = 0;
int temp_offset = 0;
bool temp_offset_sign;
const byte temp_delta = 5;

//LCD config

/*  The circuit:

  ---Shift Register 74HC595---
   SR Pin 14 to Arduino pin 2
   SR Pin 12 to Arduino pin 3
   SR Pin 11 to Arduino pin 4
   SR Pin  8 to Ground
   SR Pin 16 to +5v
   SR Pin 13 to Ground
   SR Pin 10 to +5v
  -----Shift Reg to LCD--------
   SR Pin 15 to D7
   SR Pin 1  to D6
   SR Pin 2  to D5
   SR Pin 3  to D4
   SR Pin 6  to Enable
   SR Pin 7  to RS
  -----LCD HD44780-------------
   Vss to Ground
   Vdd to +5V
   Vo  to Arduino pin 6 wth 1k res and 100uf//100nf caps as LP filter
   R/W to Ground
   5v  to +5v
   K+  to Arduino pin 5 with 330 res
   K-  to Gnd


  For a more detailed schematic, please see my blog:

  http://cjparish.blogspot.com/2010/01/controlling-lcd-display-with-shift.html

  Library modified from the original LiquidCrystal Library
  This example originaly by Tom Igoe, Jul 2009
  Example modified for use with ShiftLCD
  Chris Parish, January 12th 2010

*/

#define clock_pin         25    //shift register clock pin // SHCP
#define data_pin          9    //shift register data pin  // DS
#define latch_pin         3    //shift register latch pin // STCP

#define backlight_lcd_pwm 30    //OC1B PWM
#define backlight_lcd_max 255
#define backlight_lcd_min 0

#define contrast_lcd_pwm  8      //OC1A PWM
#define contrast_lcd_max  250
#define contrast_lcd_min  0

ShiftLCD lcd(data_pin, clock_pin, latch_pin);

//input output defined here (master)
const byte buzzer         =   4;

const byte ok_button      =   20;
const byte down_button    =   21;
const byte  up_button     =   19;

Button up = Button(up_button, BUTTON_PULLUP_INTERNAL);
Button down = Button(down_button, BUTTON_PULLUP_INTERNAL);
Button ok = Button(ok_button, BUTTON_PULLUP_INTERNAL);

//input output defined here
const byte sol_1_exchage_gas    =   14;
const byte sol_2_water          =   26;
const byte sol_3_exchage_vapour =   28;
const byte sol_4_dry            =   22;
const byte pump                 =   24;
//inputs sensors
const byte door_sensor_pin      =   12;
const byte water_sensor_pin     =   15;
const byte pressure_switch_pin  =   11;

const byte sol_1_exchage_gas_fed    =   16;
const byte sol_2_water_fed          =   27;
const byte sol_3_exchage_vapour_fed =   29;
const byte sol_4_dry_fed            =   31;
const byte pump_fed                 =   23;
#define heater_fed                      A3

//Esp8266 OTA pins defined here
#define RX_PIN      0
#define TX_PIN      1
#define CH_PD      13


byte sys_sittings[menu_sys_settings_elements];
const byte sys_defults[menu_sys_settings_elements] =   {0  ,
                                                        50 ,   //lcd backlight defult
                                                        50 ,   //lcd contarst  defult
                                                        0  ,
                                                        0
                                                       };  //index 0 not used

//Variables for the application
#define run_screen_refresh           100   //in ms

#define prog_stages_times_array      10

byte prog_times_min_sittings[menu_prog_settings_elements];

int stage_time_min[prog_stages_times_array];
int stage_time_sec[prog_stages_times_array];

const byte prog_defults_min[prog_stages_times_array] = {0, //Ster 134    10 min
                                                        0, //vacum   9 min
                                                        0, //fill_1  1 min
                                                        0, //fill_2  4 min
                                                        0,//Heat    75 min
                                                        0,//Ster 121    25 min
                                                        0, //Vent_1  2 min
                                                        0, //Vent_2  6 min
                                                        0,//Dry_1   15 min
                                                        0, //Dry_2   1 min
                                                       };
const byte prog_defults_sec[prog_stages_times_array] = {10, //Ster 134  10 min
                                                        10, //vacum   9 min
                                                        10, //fill_1  1 min
                                                        10, //fill_2  4 min
                                                        10,//Heat    75 min
                                                        10,//Ster  121  25 min
                                                        10, //Vent_1  2 min
                                                        10, //Vent_2  6 min
                                                        10,//Dry_1   15 min
                                                        10, //Dry_2   1 min
                                                       };

int temp_sitting_val;
byte temp = 0;

bool water_sensor = false;
byte error_code = 0;
int time_sec = 0;
int time_min = 0;

int heater_power_saved_settings, heater_power_now;
const byte heater_power_delta_error = 200;
const byte heater_power_delta_warning = 100;
int heater_power_calculated_from_saved;
unsigned int heater_set_val_temp;
bool heater_setting_flag;

bool update_outputs = true;

//Variables for the menu sys
char counter = 0;
byte page = 1;
byte Ready = 1;
byte submenu = 0;
char last_counter = 0;
byte pushed = 0;
byte setting_no = 0;
byte prog_no = 0;
byte test_no = 0;                         
bool on_flag = false;
bool run_prog = false;
bool heater_on_flag=false;
unsigned long time_now = 0;

unsigned long period_check = 350;      //in ms                                          //////////////////////////////////////set to 3500
unsigned long time_now_check = 0;

//unsigned long start_time = 0;
bool sys_error = false;
bool dev_mode = true;                                         //////////////////////////////////////////////////////////set false
byte prog_stage = 0;
bool min_prog_set;
byte warning_code;
bool error_in_test_submenu;
byte col, row, nb = 0, bc = 0;                            // general
byte bb[8];                                               // byte buffer for reading from PROGMEM

//*****************************************************************************************//
//                                      Initial Setup
//*****************************************************************************************//
void setup() {
  // put your setup code here, to run once:
  io_init();

  //for LCD
  lcd.begin(16, 2);
  init_sys();
  bigFont_init();

  splash_screan();           //Create Splash screan
  lcd_first_screen();         //Print the first page menu.

  fuzzy_mf_init();            //init all fuzzy sets and rules

  EasyBuzzer.beep(
    frequency,  // Frequency in Hertz(HZ).
    2   // The number of beeps.
  );
  
  timer2_init();
  attachInterrupt(zero_cross, zero_cross_isr, RISING);  // Choose the zero cross interrupt 
  sei();                                             //Enable intrupts
}
//*****************************************************************************************//
//                                      MAIN LOOP
//*****************************************************************************************//
void loop() {
  program_runinng();   //defined in autoclave_program
  screen_timer();      //defined in submenu_prog_run
  refresh_lcd();       //defined in lcd_menus
  buttons_action();    //Now we detect when we push the button
  check_error_code();    //defined in error screen

  /* Always call this function in the loop for EasyBuzzer to work. */
  EasyBuzzer.update();
}
