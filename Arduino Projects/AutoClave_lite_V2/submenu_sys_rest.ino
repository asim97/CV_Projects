void submenu_sys_rest() {
  //Fifth page of the menu about => (about auther in 4 pages)
  if (submenu == menu_sys_rest_index)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" Factory REST ?");
    lcd.setCursor(0, 1);
    if (counter == 0) //when Line 1 selected
    {
      lcd.print("=>NO       YES");
      page = 1;
    }
    if (counter == 1) //when Line 2 selected
    {
      lcd.print("  NO     =>YES");
      page = 2;
    }
    pushed = 0;
  }
}

void buttons_action_sys_rest() {

  if (submenu == menu_sys_rest_index)
  {

    if (page == 1) {
      submenu = menu_sys_settings_index;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("   Cancelled!");
      delay(1000);
    }
    if (page == 2) {
      submenu = menu_sys_settings_index;
      //save defulat setting in eeprom
      if (up.isPressed() && down.isPressed())
      {

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(" Factory REST ");
        lcd.setCursor(0, 1);
        lcd.print(" DONT TURN OFF ");
        delay(2000);
        //run rest function
        restting();
        lcd.clear();
        writeBigString("DONE", 2, 0);
//        EasyBuzzer.beep(
//          frequency,  // Frequency in Hertz(HZ).
//          2   // The number of beeps.
//        );
        delay(1000);
      }
      else
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("  Please press");
        lcd.setCursor(0, 1);
        lcd.print(" UP + DOWN + OK");
        delay(2000);
      }
    }
    counter = setting_no - 1;
    pushed = 1;
    Ready = 0;
  }
}//end of submenu 4

void restting() {

  for (byte i = 0; i < prog_stages_times_array; i++)
  {
    EEPROM.update(i + 0, prog_defults_min[i]);
    stage_time_min[i] = prog_defults_min[i];
    delay(5);
  }
  for (byte i = 0; i < prog_stages_times_array; i++)
  {
    EEPROM.update(i + 10, prog_defults_sec[i]);
    stage_time_sec[i] = prog_defults_sec[i];
    delay(5);
  }
  for (byte i = 0; i < menu_sys_settings_elements ; i++)
  {
    EEPROM.update(i + 20, sys_defults[i]);
    sys_sittings[i] = sys_defults[i];
    delay(5);
  }
  EEPROM.update(30, 0);   //rest temp offset to zero

  delay(5);
  EEPROM.update(31, 0);
}
