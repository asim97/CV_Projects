void submenu_main() {
  //First page of the menu (choose program ,settings ,tests, about)
  if (submenu == menu_main_index )
  {
    if (counter == 0)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("Choose Program");
      lcd.setCursor(0, 1);
      lcd.print("  Settings");
      page = 1;
      if (pushed) pushed = 0;
    }

    if (counter == 1)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Choose Program");
      lcd.setCursor(0, 1);
      lcd.print("=>");
      lcd.print("Settings");
      page = 2;
      if (pushed) pushed = 0;
    }

    if (counter == 2)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("Tests");
      lcd.setCursor(0, 1);
      lcd.print("  About");
      page = 3;
      if (pushed) pushed = 0;
    }

    if (counter == 3)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Tests");
      lcd.setCursor(0, 1);
      lcd.print("=>");
      lcd.print("About");
      page = 4;
      if (pushed) pushed = 0;
    }
  }//submenu = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void buttons_action_main() {
  if (submenu == menu_main_index && Ready == 1)
  {
    if (page == 1)
    {
      submenu = menu_choose_program_index;
      counter = 0;
      pushed = 1;
    }

    if (page == 2 && dev_mode)
    {
      submenu = menu_settings_index;
      counter = 0;
      pushed = 1;
    }

    if (page == 3 && dev_mode)
    {
      submenu = menu_tests_index;
      counter = 0 ;
      pushed = 1;
    }

    if (page == 4)
    {
      submenu = menu_about_index;
      counter = 0;
      pushed = 1;
    }
  }//end of submenu 0
}
