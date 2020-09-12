void submenu_tests() {

  //Forth page of the menu tests => (S1 GAS , S2 GAS , S3 VAP , S4 DRY , PUMP , HEATER)
  if (submenu == menu_tests_index)
  {
    if (counter == 0)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("S1 GAS");
      lcd.setCursor(0, 1);
      lcd.print("  S2 GAS");
      page = 1;
      pushed = 0;
      test_no = page;
    }

    if (counter == 1)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  S1 GAS");
      lcd.setCursor(0, 1);
      lcd.print("=>");
      lcd.print("S2 GAS");
      page = 2;
      pushed = 0;
      test_no = page;
    }

    if (counter == 2)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("S3 VAP");
      lcd.setCursor(0, 1);
      lcd.print("  S4 DRY");
      page = 3;
      pushed = 0;
      test_no = page;
    }

    if (counter == 3)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  S3 VAP");
      lcd.setCursor(0, 1);
      lcd.print("=>");
      lcd.print("S4 DRY");
      page = 4;
      pushed = 0;
      test_no = page;
    }

    if (counter == 4)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("PUMP");
      lcd.setCursor(0, 1);
      lcd.print("  HEATER");
      page = 5;
      pushed = 0;
      test_no = page;
    }

    if (counter == 5)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  PUMP");
      lcd.setCursor(0, 1);
      lcd.print("=>");
      lcd.print("HEATER");
      page = 6;
      pushed = 0;
      test_no = page;
    }

    if (counter == 6)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("TEMP Sensor");
      lcd.setCursor(0, 1);
      lcd.print("  Back");
      page = 7;
      pushed = 0;
      test_no = page;
    }
    if (counter == 7)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  ");
      lcd.print("TEMP Sensor");
      lcd.setCursor(0, 1);
      lcd.print("=>");
      lcd.print("Back");
      page = 8;
      pushed = 0;
    }
  }//submenu = 3;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void buttons_action_test() {
  if (submenu == menu_tests_index)
  {
    if (page == 1 || page == 2 || page == 3 || page == 4 || page == 5  || page == 6) {
      submenu = menu_test_run_index;
      counter = 0;
      pushed = 1;
      page = 1;
      on_flag = false;
    }
    if (page == 7) {
      submenu = menu_temp_sensor_test_index;
      counter = 0;
      pushed = 1;
      page = 1;
      on_flag = false;
    }
    if (page == 8) //back selected
    {
      submenu = menu_main_index;
      counter = menu_tests_index - 1;
      pushed = 1;
      Ready = 0;
    }
  }//end of submenu 3
}
