/********** Task Functions **********/
void check_gsm_started() {
  // If there is input data from SIM800
  if (gsm_started) {
    //Read if there are messages on SIM card and print them.
    if (gsm.readSMS(smsbuffer, sizeof(smsbuffer), num, sizeof(num))) {
      //convert char to string for searching inside
      string_smsbuffer = smsbuffer;
      string_num = num;

      if (string_num.indexOf(replyNumber) >= 0) { //check the sender number here
        Relay_controller();
      }
    }
    // ==================================================================>>

    Send_warning_status_sms();
  }
}

void Relay_controller() {
  // ================================================================>> Function of Relay Controller
  //Relay 1 Controller
  if (string_smsbuffer.indexOf("Relay 1 ON") >= 0) {
    StatRelay[0] = RELAY_ACTIVATED;
    Serial.print("Reply====>>>> ");
    Serial.println("Relay 1 Status Active");
    sms.SendSMS(replyNumber, "Relay 1 Status ON");
    Serial.println("\nSMS sent OK");
    EEPROM.write(Relay[0], StatRelay[0]);
    Serial.println("Saved RELAY Status to EEPROM");
  }
  else if (string_smsbuffer.indexOf("Relay 1 OFF") >= 0) {
    StatRelay[0] = RELAY_DEACTIVETED;
    Serial.print("Reply====>>>> ");
    Serial.println("Relay 1 Status Off");
    sms.SendSMS(replyNumber, "Relay 1 Status Off");
    Serial.println("\nSMS sent OK");
    EEPROM.write(Relay[0], StatRelay[0]);
    Serial.println("Saved RELAY Status to EEPROM");
  }
  //Relay 2 Controller
  if (string_smsbuffer.indexOf("Relay 2 ON") >= 0) {
    StatRelay[1] = RELAY_ACTIVATED;
    Serial.print("Reply====>>>> ");
    Serial.println("Relay 2 Status Active");
    sms.SendSMS(replyNumber, "Relay 2 Status ON");
    Serial.println("\nSMS sent OK");
    EEPROM.write(Relay[1], StatRelay[1]);
    Serial.println("Saved RELAY Status to EEPROM");
  }
  else if (string_smsbuffer.indexOf("Relay 2 OFF") >= 0) {
    StatRelay[1] = RELAY_DEACTIVETED;
    Serial.print("Reply====>>>> ");
    Serial.println("Relay 2 Status Off");
    sms.SendSMS(replyNumber, "Relay 2 Status Off");
    Serial.println("\nSMS sent OK");
    EEPROM.write(Relay[1], StatRelay[1]);
    Serial.println("Saved RELAY Status to EEPROM");
  }
  //Relay 3 Controller
  if (string_smsbuffer.indexOf("Relay 3 ON") >= 0) {
    StatRelay[2] = RELAY_ACTIVATED;
    Serial.print("Reply====>>>> ");
    Serial.println("Relay 3 Status Active");
    sms.SendSMS(replyNumber, "Relay 3 Status Active");
    Serial.println("\nSMS sent OK");
    EEPROM.write(Relay[2], StatRelay[2]);
    Serial.println("Saved RELAY Status to EEPROM");
  }
  else if (string_smsbuffer.indexOf("Relay 3 OFF") >= 0) {
    StatRelay[2] = RELAY_DEACTIVETED;
    Serial.print("Reply====>>>> ");
    Serial.println("Relay 3 Status Off");
    sms.SendSMS(replyNumber, "Relay 3 Status Off");
    Serial.println("\nSMS sent OK");
    EEPROM.write(Relay[2], StatRelay[2]);
    Serial.println("Saved RELAY Status to EEPROM");
  }
  //Relay 4 Controller
  if (string_smsbuffer.indexOf("Relay 4 ON") >= 0) {
    StatRelay[3] = RELAY_ACTIVATED;
    Serial.print("Reply====>>>> ");
    Serial.println("Relay 4 Status Active");
    sms.SendSMS(replyNumber, "Relay 1 Status Active");
    Serial.println("\nSMS sent OK");
    EEPROM.write(Relay[3], StatRelay[3]);
    Serial.println("Saved RELAY Status to EEPROM");
  }
  else if (string_smsbuffer.indexOf("Relay 4 OFF") >= 0) {
    StatRelay[3] = RELAY_DEACTIVETED;
    Serial.print("Reply====>>>> ");
    Serial.println("Relay 4 Status Off");
    sms.SendSMS(replyNumber, "Relay 4 Status Off");
    Serial.println("\nSMS sent OK");
    EEPROM.write(Relay[3], StatRelay[3]);
    Serial.println("Saved RELAY Status to EEPROM");
  }

  // Change status Relay ON / OFF
  for (int i = 0; i < Num_Relay; i++) {
    digitalWrite(Relay[i], StatRelay[i]);
  }
  Serial.println("RELAY Status UPDATED");
}

void Check_SMS_CMD() {
  if (string_smsbuffer.indexOf("Status") >= 0) {
    Serial.println("Status CMD RECIVED");
    Serial.print("\nSending ALL DATA to ");
    Serial.print(replyNumber);
    Serial.print("AS SMS Response");
    char sms_data[160];
    sprintf(sms_data, "Status"
            "\nRelay 1 %D\nRelay 2 %D\nRelay 3 %D\nRelay 4 %D"
            "\nTEMP %D degC\nHUMIDITY %D", StatRelay[0], StatRelay[1], StatRelay[2], StatRelay[3], temp_c, humidity);
    Serial.print("SENDING THE FOLLOWIG SMS");
    Serial.print(sms_data);
    sms.SendSMS(replyNumber, sms_data);
    Serial.println("\nSMS sent OK");

  }
}


void Send_warning_status_sms() {
  // ================================================================>> Function of sendings sms when abnormal occures
  if (warning_code > 0 && !warning_sms_sent) {
    switch (warning_code) {
      case HIGH_TEMP:
        sms.SendSMS(replyNumber, "WARINING HIGH TEMP");
        //if any action would be taken, Just write it here
        break;
      case LOW_TEMP:
        sms.SendSMS(replyNumber, "WARINING LOW TEMP");
        //if any action would be taken, Just write it here
        break;
      case FIRE_DETECTED:
        sms.SendSMS(replyNumber, "WARINING FIRE DETECTED");
        //if any action would be taken, Just write it here
        break;
      default:
        break;
    }
    warning_sms_sent = true;
    warning_code = 0;
  }
}