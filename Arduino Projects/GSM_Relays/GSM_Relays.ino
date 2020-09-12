
/*
  Sketch: gsm Send and recive gsm to control relays

************************************************************************************
  note: the following pins has been used for gsm module and should not be used for other purposes.
  pin 8   // tx pin
  pin 7   // rx pin
  pin 9   // power key pin
  pin 12  // power status pin
************************************************************************************
*/
#include <sms.h>
#include <SoftwareSerial.h>
#include "SIM900.h"
#include <EEPROM.h>
#include "DHT.h"
#include <Tasks.h>

// ================================================================>> "CHANGE YOUR SITTINGS BELOW"
#define SERIAL_BUADRATE     9600
#define RELAY_ACTIVATED     LOW
#define RELAY_DEACTIVETED   HIGH
#define Num_Relay           4
#define DHTTYPE             DHT11
#define MIN_TEMP_TH         15              //dec C
#define MAX_TEMP_TH         40              //dec C
#define replyNumber         "01211582168"   //admin phonenumber edit here
#define DHTPIN              2
#define FIRE_SEN_D_PIN      3
#define FIRE_SEN_active     HIGH
enum Relays_pins {
  Relay_1 = 23,
  Relay_2 = 25,
  Relay_3 = 27,
  Relay_4 = 29
};
// ================================================================>>"NO CHANGE AFTER THIS LINE"

enum warning_codes {
  HIGH_TEMP=1,
  LOW_TEMP,
  FIRE_DETECTED
};
byte Relay[Num_Relay] = {Relay_1, Relay_2, Relay_3, Relay_4};// define relay pins
byte StatRelay[Num_Relay]; // all relays status are low(0)
char smsbuffer[160];
String string_smsbuffer;
char num[20];
String string_num;
bool gsm_started = false;
bool warning_sms_sent = false;
char warning_code = 0;

SMSGSM sms;
DHT dht(DHTPIN, DHTTYPE);

float temp_c, temp_f, humidity, heat_index_c, heat_index_f;


void setup() {
  //defining each pins for relays as output pins and deactivate them
  for (int i = 0; i < Num_Relay; i++) {
    pinMode (Relay[i], OUTPUT);
    digitalWrite (Relay[i], RELAY_DEACTIVETED);
    StatRelay[i] = RELAY_DEACTIVETED;
  }

  //defining pins for fire sensor as output pins
  pinMode (FIRE_SEN_D_PIN, OUTPUT);

  //Serial connection.
  Serial.begin(SERIAL_BUADRATE);
  Serial.println("Serial connected OK -- Strating GSM Comuninication");
  //Start configuration of the gsm shield with baudrate.
  //For http uses is raccomanded to use 4800 or slower.
  if (gsm.begin(2400)) {     ///while and not here <<<<<
    Serial.println("\nGSM READY");
    delay(1000);
    gsm_started = true;
  }
  else Serial.println("\nGSM NOT OKAY");

  if (gsm_started) {
    if (sms.SendSMS(replyNumber, "System is UP and READY!")) {
      Serial.println("\n Welcome SMS sent OK to ");
      Serial.println(replyNumber);
      restore_relays_status_from_eeprom();
      Serial.println("\n Relay Status restored from eeprom");
    }
  }
  Serial.print("Admin number = > ");
  Serial.println(replyNumber);
  DHT dht(DHTPIN, DHTTYPE);
  delay(2000);
  DHT_INIT();
  Serial.println("Initialization Done");
  Serial.println("=============================================================");
}
void loop() {
  /* It's best not to do anything in loop() except runTasks() - doing anything else here will affect timing */
  Schedule.runTasks();
}
