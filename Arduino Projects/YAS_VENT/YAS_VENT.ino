#include "OMMenuMgr.h"
#include <avr/pgmspace.h>            // for memory storage in program space
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 (Could be 0x20 if solder jumpers are bridged!)
// Set the pins on the I2C chip used for LCD connections:
//                    addr,en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
byte col, row, nb = 0, bc = 0;                            // general(BigFont)
byte bb[8];                                               // byte buffer for reading from PROGMEM(BigFont)
const byte LCD_ROWS = 2;
const byte LCD_COLS = 16;

// mapping of analog button values for menu
int  myButtons[5][2] = { {4, BUTTON_FORWARD},
  {5, BUTTON_INCREASE},
  {6, BUTTON_DECREASE},
  {7, BUTTON_BACK},
  {8, BUTTON_SELECT}
};

byte selected_mode = 0;                           //to save current selected mode
byte selected_breath_rate = 0;                    //10-15 breaths/min
int  selected_tidal_volume = 0;                   //8-15 ml/kg
byte selected_minulte_ventilation = 0;            //8-10 L/min
byte selected_peep_pressure = 0;                  //0-4 cmH2O
byte selected_inspiratory_pressure = 0;           //8-12 cmH2O
byte selected_inspiratory_flow = 0;               //>=100 L/min
float selected_inspiratory_expiratory_rate = 2;   //1:2
float selected_inspiratory_time = 0;              //~1 sec
float selected_inspiratory_pressure_triger = 0;   //-1 to -5 cmH2O
float selected_inspiratory_flow_triger = 0;       //0.5 to 2.0 L/minL/min

// Create a list of states and values for a select input MODE
MENU_SELECT_ITEM  sel_mode_VC = { 1, {"VC"} };
MENU_SELECT_ITEM  sel_mode_PC  = { 2, {"PC"} };
MENU_SELECT_ITEM  sel_mode_SIMV_VC_PS = {3, {"SIMV (VC/PS)"} };
MENU_SELECT_ITEM  sel_mode_SIMV_PC_PS = { 4, {"SIMV (PC/PS)"} };
MENU_SELECT_ITEM  sel_mode_PS_bilevel = { 5, {"PS/(bilevel)"} };
MENU_SELECT_ITEM  sel_mode_CPAP = { 6, {"CPAP"} };
MENU_SELECT_ITEM  sel_mode_T_tube = { 7, {"T-tube"} };
MENU_SELECT_LIST  state_mode_list[] = { &sel_mode_VC, &sel_mode_PC, &sel_mode_SIMV_VC_PS, &sel_mode_SIMV_PC_PS, &sel_mode_PS_bilevel, &sel_mode_CPAP, &sel_mode_T_tube};
// the special target for our state input
MENU_SELECT state_mode_select = { &selected_mode, MENU_SELECT_SIZE(state_mode_list), MENU_TARGET(&state_mode_list) };
// values to use

///////////////////////////////////////////////////    TYPE            MAX    MIN    TARGET
MENU_VALUE breath_rate_value                      = { TYPE_BYTE,       30,    4,     MENU_TARGET(&selected_breath_rate) };
MENU_VALUE tidal_volume_value                     = { TYPE_UINT,       2000,  100,   MENU_TARGET(&selected_tidal_volume) };
MENU_VALUE peep_pressure_value                    = { TYPE_BYTE,       4,     0,     MENU_TARGET(&selected_peep_pressure) };
MENU_VALUE inspiratory_pressure_value             = { TYPE_BYTE,       30,    4,     MENU_TARGET(&selected_inspiratory_pressure) };
MENU_VALUE inspiratory_flow_value                 = { TYPE_BYTE,       100,   0,     MENU_TARGET(&selected_inspiratory_flow) };
MENU_VALUE minulte_ventilation_value              = { TYPE_BYTE,       20,    5,     MENU_TARGET(&selected_minulte_ventilation) };
MENU_VALUE inspiratory_expiratory_rate_value      = { TYPE_FLOAT_10,   100,   0,     MENU_TARGET(&selected_inspiratory_expiratory_rate) };
MENU_VALUE inspiratory_time_value                 = { TYPE_FLOAT_10,   1,     0,     MENU_TARGET(&selected_inspiratory_flow) };
MENU_VALUE inspiratory_pressure_triger_value      = { TYPE_FLOAT_10,   0,     -5,    MENU_TARGET(&selected_inspiratory_pressure_triger) };
MENU_VALUE inspiratory_flow_triger_value          = { TYPE_FLOAT_10,   5,     0.5,   MENU_TARGET(&selected_inspiratory_flow_triger) };
MENU_VALUE sel_mode_value                         = { TYPE_SELECT,     0,     0,     MENU_TARGET(&state_mode_select) };

/////////////////////////////////////////////////        LABEL              TYPE         LENGTH    TARGET
MENU_ITEM item_breath_rate                     = { {"Breath Rate"},         ITEM_VALUE,  0,        MENU_TARGET(&breath_rate_value) };
MENU_ITEM item_tidal_volume                    = { {"Tidal Volume"},        ITEM_VALUE,  0,        MENU_TARGET(&tidal_volume_value) };
MENU_ITEM item_peep_pressure                   = { {"PEEP"},                ITEM_VALUE,  0,        MENU_TARGET(&peep_pressure_value) };
MENU_ITEM item_inspiratory_pressure            = { {"Pressure"},            ITEM_VALUE,  0,        MENU_TARGET(&inspiratory_pressure_value) };
MENU_ITEM item_inspiratory_flow                = { {"In Flow"},             ITEM_VALUE,  0,        MENU_TARGET(&inspiratory_flow_value) };
MENU_ITEM item_minulte_ventilation             = { {"MV"},                  ITEM_VALUE,  0,        MENU_TARGET(&minulte_ventilation_value) };
MENU_ITEM item_inspiratory_expiratory_rate     = { {"IE Rate"},             ITEM_VALUE,  0,        MENU_TARGET(&inspiratory_expiratory_rate_value) };
MENU_ITEM item_inspiratory_time                = { {"In Time"},             ITEM_VALUE,  0,        MENU_TARGET(&inspiratory_time_value) };
MENU_ITEM item_inspiratory_pressure_triger     = { {"In Pressure TRIG"},    ITEM_VALUE,  0,        MENU_TARGET(&inspiratory_pressure_triger_value) };
MENU_ITEM item_inspiratory_flow_triger         = { {"In Flow TRIG"},        ITEM_VALUE,  0,        MENU_TARGET(&inspiratory_flow_triger_value  ) };

MENU_LIST param_list[]  = {&item_breath_rate, &item_tidal_volume, &item_peep_pressure, &item_inspiratory_pressure, &item_inspiratory_flow,
                           &item_minulte_ventilation, &item_inspiratory_expiratory_rate, &item_inspiratory_time, &item_inspiratory_pressure_triger,
                           &item_inspiratory_flow_triger
                          };
MENU_ITEM menu_param    = { {"Parameters"},   ITEM_MENU,   MENU_SIZE(param_list),   MENU_TARGET(&param_list) };

MENU_ITEM item_mode_state                      = { {"Select Mode"}, ITEM_VALUE,  0,        MENU_TARGET(&sel_mode_value) };
//MENU_ITEM menu_mode     = { {"Select Mode"},   ITEM_MENU,   MENU_SIZE(state_mode_select),   MENU_TARGET(&state_mode_select)};

// Root menu
MENU_LIST root_list[]   = { &item_mode_state, &menu_param };
MENU_ITEM menu_root     = { {"Root"},         ITEM_MENU,   MENU_SIZE(root_list),    MENU_TARGET(&root_list) };

OMMenuMgr Menu(&menu_root, MENU_DIGITAL );

void setup() {
  // put your setup code here, to run once:
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.backlight();
  bigFont_init();
  splash_screan();           //Create Splash screan
  Menu.setDrawHandler(uiDraw);
  Menu.setExitHandler(uiClear);
  Menu.setDigitalButtonPins(myButtons);
  Menu.enable(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  Menu.checkInput();

}
