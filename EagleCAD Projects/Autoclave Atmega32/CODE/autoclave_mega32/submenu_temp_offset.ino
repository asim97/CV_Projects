void submenu_temp_offset_set_val() {
  //Third page of the menu settings (setting 1 ,.....)
  if (submenu == menu_temp_offset_index)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("    Set New value");
    pushed = 0;
    lcd.setCursor(0, 1);
    lcd.print("DF:");
    lcd.print(0, DEC);
    lcd.setCursor(7, 1);
    lcd.print("CR:");
    lcd.print(temp_offset, DEC);
    lcd.setCursor(14, 1);
    lcd.print("NW:");
    lcd.print(temp_sitting_val, DEC);
    page = 1;
  }
}

void buttons_action_temp_offset_set_val() {

  if (submenu == menu_temp_offset_index)
  {
    if (page == 1)
    {
      submenu = menu_temp_offset_save_index;
      counter = 0;
      pushed = 1;
      Ready = 0;
      page = 0;
    }//end of submenu 4
  }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void submenu_temp_offset_save() {
  //Fifth page of the menu about => (about auther in 4 pages)
  if (submenu == menu_temp_offset_save_index)
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

void buttons_action_temp_offset_save() {

  if (submenu == menu_temp_offset_save_index)
  {

    if (page == 1) {
      submenu = menu_settings_index;
      temp_sitting_val = 0;
    }
    if (page == 2) {
      submenu = menu_settings_index;
      //save setting in eeprom
      if (temp_sitting_val < 0)
      {
        temp = -1 * temp_sitting_val;
        temp_offset_sign = 1;
      }
      else
      {
        temp_offset_sign = 0;
        temp = temp_sitting_val;
      }
      EEPROM.update(30, temp_offset_sign);
      delay(5);
      EEPROM.update(31, temp);
      temp_offset = temp_sitting_val;
      temp_sitting_val = 0;
    }
    counter = 2;
    pushed = 1;
    Ready = 0;
    page = 0;
  }//end of submenu 4
}
