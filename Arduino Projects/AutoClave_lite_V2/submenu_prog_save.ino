void submenu_prog_save() {
  //Fifth page of the menu about => (about auther in 4 pages)
  if (submenu == menu_prog_save_index)
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

void buttons_action_prog_save() {

  if (submenu == menu_prog_save_index)
  {

    if (page == 1) {
      submenu = menu_prog_settings_index;
      temp_sitting_val = 0;
    }
    if (page == 2) {
      submenu = menu_prog_settings_index;
      //save setting in eeprom
      temp = (byte) temp_sitting_val;
      if (min_prog_set)
      {
        EEPROM.update(0 + setting_no, temp);
        stage_time_min[setting_no] = temp_sitting_val;
      }
      else
      {
        EEPROM.update(10 + setting_no, temp);
        stage_time_sec[setting_no] = temp_sitting_val;
      }
      temp_sitting_val = 0;
      temp = 0;
    }
    if (setting_no)
      counter = setting_no - 1;
    else
      counter = 5;
    pushed = 1;
    Ready = 0;
  }
}//end of submenu 4
