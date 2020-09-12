
void submenu_heater_power_set_val() {
  //Third page of the menu settings (setting 1 ,.....)
  if (submenu == menu_heater_power_set_val_index)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("    Set New value");
    pushed = 0;
    lcd.setCursor(0, 1);
    lcd.print("CR:");

    lcd.print(heater_power_saved_settings, DEC);

    lcd.setCursor(9, 1);
    lcd.print("NW:");
    lcd.print(heater_set_val_temp, DEC);

    page = 10;
  }
}

void buttons_action_heater_power_set_val() {

  if (submenu == menu_heater_power_set_val_index)
  {
    if (page == 10)
    {
      counter = 0;
      submenu = menu_heater_power_save_index;
      page=0;
      pushed = 1;
      Ready = 0;
    }//end of submenu 4
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void submenu_heater_power_save() {
  //Fifth page of the menu about => (about auther in 4 pages)
  if (submenu == menu_heater_power_save_index)
  {
    if (counter == 0) //when Line 1 selected
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Save new value ?");
      lcd.setCursor(0, 1);
      lcd.print("=>NO       YES");
      page = 1;
      pushed = 0;
    }

    if (counter == 1) //when Line 2 selected
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Save new value ?");
      lcd.setCursor(0, 1);
      lcd.print("  NO     =>YES");
      page = 2;
      pushed = 0;
    }
  }
}

void buttons_action_heater_power_save() {

  if (submenu == menu_heater_power_save_index)
  {
    if (page == 1) {
      submenu = menu_settings_index;
      temp_sitting_val = 0;
    }
    if (page == 2) {
      submenu = menu_settings_index;
      //save setting in eeprom
      EEPROMWriteInt(28, heater_set_val_temp);
      heater_power_saved_settings = heater_set_val_temp;
      heater_set_val_temp = 0;
    }
    counter = 3;
    pushed = 1;
    Ready = 0;
  }
}//end of submenu 4
