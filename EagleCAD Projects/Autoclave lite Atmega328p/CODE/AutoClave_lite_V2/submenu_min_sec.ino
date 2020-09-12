void submenu_settings_min_sec() {
  //Third page of the menu settings (setting 1 ,.....)
  if (submenu == menu_min_sec_index)
  {
    if (counter == 0)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("Edit minutes");
      lcd.setCursor(0, 1);
      lcd.print("  Edit seconds");
      page = 1;
      pushed = 0;
    }

    if (counter == 1)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Edit minutes");
      lcd.setCursor(0, 1);
      lcd.print("=>");
      lcd.print("Edit seconds");
      page = 2;
      pushed = 0;
    }

    if (counter == 2)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("Back");
      lcd.setCursor(0, 1);
      lcd.print("  ");
      page = 3;
      pushed = 0;
    }
  }//submenu = 2;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void buttons_action_min_sec() {
  if (submenu == menu_min_sec_index)
  {
    if (page == 1 || page == 2)
    {
      submenu = menu_prog_set_val_index;
      counter = 0;
      pushed = 1;
      Ready = 0;
      if (page == 1) min_prog_set = true;
      if (page == 2) min_prog_set = false;
      page = 0;
    }

    if (page == 3) //back selected
    {
      submenu = menu_prog_settings_index;
      counter = setting_no - 1;
      pushed = 1;
      Ready = 0;
      page = 0;
    }
  }//end of submenu 1
}
