void submenu_settings_elements() {
  //Third page of the menu settings (setting 1 ,.....)
  if (submenu == menu_settings_index)
  {
    if (counter == 0)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("Programs");
      lcd.setCursor(0, 1);
      lcd.print("  System");
      page = 1;
      pushed = 0;
      setting_no = page;
    }

    if (counter == 1)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Programs");
      lcd.setCursor(0, 1);
      lcd.print("=>");
      lcd.print("System");
      page = 2;
      pushed = 0;
      setting_no = page;
    }

    if (counter == 2)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("Temp offset");
      lcd.setCursor(0, 1);
      lcd.print("  Heater Power");
      page = 3;
      pushed = 0;
      setting_no = page;
    }

    if (counter == 3)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Temp offset");
      lcd.setCursor(0, 1);
      lcd.print("=>");
      lcd.print("Heater Power");
      page = 4;
      pushed = 0;
      setting_no = page;
    }

    if (counter == 4)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("Back");
      page = 5;
      pushed = 0;
      setting_no = page;
    }
  }//submenu = 2;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void buttons_action_settings() {
  if (submenu == menu_settings_index)
  {
    if (page == 1)
    {
      submenu = menu_prog_settings_index;
      counter = 0;
      pushed = 1;
      Ready = 0;
      page = 0;
    }

    if (page == 2)
    {
      submenu = menu_sys_settings_index;
      counter = 0;
      pushed = 1;
      Ready = 0;
      page = 0;
    }

    if (page == 3)  //temp offset selected
    {
      submenu = menu_temp_offset_index;
      counter = 0;
      pushed = 1;
      Ready = 0;
      page = 0;
    }
   if (page == 4) //heater power selected
    {
      submenu = menu_heater_power_set_val_index;
      counter = 0;
      pushed = 1;
      Ready = 0;
      page = 0;
    }
    
    if (page == 5) //back selected
    {
      submenu = menu_main_index;
      counter = menu_settings_index - 1;
      pushed = 1;
      Ready = 0;
      page = 0;
    }
  }//end of submenu 1
}
