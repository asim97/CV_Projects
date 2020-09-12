//*****************************************************************************************//
//                                   Pinout Definition
//*****************************************************************************************//

//uncomment to active
//#define BUTTON_MODE_ENCODER
#define BUTTON_MODE_DIGITAL
#define LCD_NORMAL
//#define LCD_I2C
//#define FIRST_UPLOAD
//#define NODEMCU_USED

#ifdef BUTTON_MODE_DIGITAL
#define BUTTON_FORWARD_PIN        8
#define BUTTON_INCREASE_PIN       9
#define BUTTON_DECREASE_PIN       10
#define BUTTON_BACK_PIN           11
#define BUTTON_SELECT_PIN         12

#endif
#ifdef BUTTON_MODE_ENCODER
#define ENCODER_SW_PIN            8
#define ENCODER_CLK_PIN           10
#define ENCODER_DT_PIN            9
#endif

#define SERVO_BANK_1_PIN          10
#define SERVO_BANK_2_PIN          10
#define BUZZER_PIN                10
//*****************************************************************************************//
//                                   I2C LCD Definition
//*****************************************************************************************//

#define LCD_I2C_ADDR              0x27
#define LCD_ROWS                  2
#define LCD_COLS                  16

#ifdef LCD_NORMAL
#define LCD_RS                    7
#define LCD_EN                    6
#define LCD_D4                    5
#define LCD_D5                    4
#define LCD_D6                    3
#define LCD_D7                    2
#endif

//*****************************************************************************************//
//                                   ENUMs for timers,...etc
//*****************************************************************************************//

#define OPEN_BANK_ANGLE           3
#define CLOSE_BANK_ANGLE          2
#define OPEN_BANK_DELAY_MS        500

enum Pre_Defined_T {
  _1H,
  _1_5H,
  _2H,
  _2_5H,
  _3H,
  _3_5H,
  _4H,
  _4_5H,
  _5H,
  _5_5H,
  _6H,
  _6_5H,
  _7H,
  _7_5H,
  _8H,
  _8_5H,
  _9H,
  _9_5H,
  _10H,
  _10_5H,
  _11H,
  _11_5H,
  _12H
};

enum Scallers {
  _1X,
  _2X,
  _4X,
  _8X,
  _10X,
  _15X,
  _20X,
  _30X,
  _60X
};

enum Buzzer_Modes  {
  _single_beep,
  _two_beep,
  _continous_beep,
  _stop_beep
};
