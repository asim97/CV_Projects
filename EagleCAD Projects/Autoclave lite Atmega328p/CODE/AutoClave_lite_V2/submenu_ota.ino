void submenu_ota() {
  //Fifth page of the menu about => (about auther in 4 pages)
  if (submenu == menu_ota_index)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("OTA (WIFI)");

    pushed = 0;
    if (counter == 0) //when Line 1 selected
    {
      lcd.setCursor(0, 1);
      lcd.print("=>OFF   ON");
      page = 1;
      pushed = 0;

    }
    if (counter == 1) //when Line 1 selected
    {
      lcd.setCursor(0, 1);
      lcd.print("  OFF =>ON");
      page = 2;
      pushed = 0;
    }
    if (on_flag == true)
      writeBigString("ON ", 11, 0);
    if (on_flag == false)
      writeBigString("OFF", 11, 0);
  }
}

void buttons_action_ota() {
  if (submenu == menu_ota_index)
  {
    if (page == 1) {
      on_flag = false;
      lcd.setCursor(11, 0);
      writeBigString("OFF", 11, 0);
      //stop OTA



      counter = page - 1;
      pushed = 1;
      Ready = 0;

    }
    if (page == 2) {
      writeBigString("ON ", 11, 0);
      on_flag = true;

      //run OTA
      EEPROM.update(10 + 4, 1);
      sys_sittings[4] = 1;


      counter = page - 1;
      pushed = 1;
      Ready = 0;
    }


    if (up.isPressed() && down.isPressed())
    {
     
      submenu = menu_sys_settings_index;
      on_flag = false;

      page = 1;
      counter = setting_no - 1;
    }
  }
}
