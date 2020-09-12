void submenu_prog_settings() {
  //Third page of the menu settings (setting 1 ,.....)
  if (submenu == menu_prog_settings_index)
  {
    if (counter == 0)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("Vacuuming");
      lcd.setCursor(0, 1);
      lcd.print("  Filling_1");
      page = 1;
      pushed = 0;
      setting_no = page;
    }

    if (counter == 1)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Vacuuming");
      lcd.setCursor(0, 1);
      lcd.print("=>");
      lcd.print("Filling_1");
      page = 2;
      pushed = 0;
      setting_no = page;
    }

    if (counter == 2)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("Filling_2");
      lcd.setCursor(0, 1);
      lcd.print("  Heating");
      page = 3;
      pushed = 0;
      setting_no = page;
    }

    if (counter == 3)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Filling_2");
      lcd.setCursor(0, 1);
      lcd.print("=>");
      lcd.print("Heating");
      page = 4;
      pushed = 0;
      setting_no = page;
    }
    if (counter == 4)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("Sterilize 121 C");
      lcd.setCursor(0, 1);
      lcd.print("  Sterilize 134 C");
      page = 5;
      pushed = 0;
      setting_no = page;
    }
    if (counter == 5)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Sterilize 121 C");
      lcd.setCursor(0, 1);
      lcd.print("=>");
      lcd.print("Sterilize 134 C");
      page = 5;
      pushed = 0;
      setting_no = 0;
    }
    if (counter == 6)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("Venting_1");
      lcd.setCursor(0, 1);
      lcd.print("  Venting_2");
      page = 6;
      pushed = 0;
      setting_no = page;
    }
    if (counter == 7)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Venting_1");
      lcd.setCursor(0, 1);
      lcd.print("=>");
      lcd.print("Venting_2");
      page = 7;
      pushed = 0;
      setting_no = page;
    }
    if (counter == 8)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("Drying_1");
      lcd.setCursor(0, 1);
      lcd.print("  Drying_2");
      page = 8;
      pushed = 0;
      setting_no = page;
    }
    if (counter == 9)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Drying_1");
      lcd.setCursor(0, 1);
      lcd.print("=>");
      lcd.print("Drying_2");
      page = 9;
      pushed = 0;
      setting_no = page;
    }
    if (counter == 10)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("Back");
      page = 10;
      pushed = 0;
    }
  }//submenu = 2;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void buttons_action_prog_settings() {
  if (submenu == menu_prog_settings_index)
  {
    if (page == 1 || page == 2 || page == 3 || page == 4 || page == 5 || page == 6 || page == 7 || page == 8 || page == 9 )
    {
      submenu = menu_min_sec_index;
      //temp_sitting_val = prog_sittings[page];
      pushed = 1;
      Ready = 0;
      counter = 0;
      page = 0;
    }
    if (page == 10) //back selected
    {
      page = 0;
      submenu = menu_settings_index;
      counter = 0 ;
      pushed = 1;
      Ready = 0;
    }
  }//end of submenu 1
}
