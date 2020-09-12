void submenu_sys_settings() {
  //Third page of the menu settings (setting 1 ,.....)
  if (submenu == menu_sys_settings_index)
  {
    if (counter == 0)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("LCD Backlight");
      lcd.setCursor(0, 1);
      lcd.print("  LCD Contrast");
      page = 1;
      pushed = 0;
      setting_no = page;
    }

    if (counter == 1)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  LCD Backlight");
      lcd.setCursor(0, 1);
      lcd.print("=>");
      lcd.print("LCD Contrast");
      page = 2;
      pushed = 0;
      setting_no = page;
    }

    if (counter == 2)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("Factory REST");
      lcd.setCursor(0, 1);
      lcd.print("  OTA Enable (WIFI)");
      page = 3;
      pushed = 0;
      setting_no = page;
    }

    if (counter == 3)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Factory REST");
      lcd.setCursor(0, 1);
      lcd.print("=>");
      lcd.print("OTA Enable (WIFI)");
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
      lcd.setCursor(0, 1);
      lcd.print("  ");
      page = 5;
      pushed = 0;
      setting_no = page;
    }
  }//submenu = 2;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void buttons_action_sys_settings() {
  if (submenu == menu_sys_settings_index)
  {
    if (page == 1) {
      submenu = menu_sys_set_val_index;
      temp_sitting_val = sys_sittings[setting_no];
      counter = 0;
      pushed = 1;
    }
    if (page == 2) {
      submenu = menu_sys_set_val_index;
      temp_sitting_val = sys_sittings[setting_no];
      counter = 0;
      pushed = 1;
    }
    if (page == 3) {
      submenu = menu_sys_rest_index;
      counter = 0;
      pushed = 1;
      Ready = 0;
    }
    if (page == 4) {
      submenu = menu_ota_index;

      if ( EEPROM.read(4 + 20) == 1)
        on_flag = true;
      else
        on_flag = false;
      counter = 0;
      pushed = 1;
      page = 0;

    }

    if (page == 5) //back selected
    {
      submenu = menu_settings_index;
      counter = 1 ;
      pushed = 1;
      Ready = 0;
    }
  }//end of submenu 1
}
