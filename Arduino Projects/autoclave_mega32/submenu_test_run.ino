void submenu_test_run() {
  if (submenu == menu_test_run_index)
  {
    //Forth page of the menu tests => (S1 GAS , S2 WAT , S3 VAP , S4 DRY , PUMP , HEATER)
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Test ");
    if (test_no == 1) lcd.print("S1");
    if (test_no == 2) lcd.print("S2");
    if (test_no == 3) lcd.print("S3");
    if (test_no == 4) lcd.print("S4");
    if (test_no == 5) lcd.print("PUMP");
    if (test_no == 6) lcd.print("HEATER");

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

void buttons_action_test_run() {

  if (submenu == menu_test_run_index)
  {
    if (page == 1) {
      on_flag = false;
      lcd.setCursor(11, 0);
      writeBigString("OFF", 11, 0);
      if (test_no == 1) {
        //stop test 1
        digitalWrite(sol_1_exchage_gas, LOW);
      }
      if (test_no == 2) {
        //stop test 2
        digitalWrite(sol_2_water, LOW);
      }
      if (test_no == 3) {
        //stop test 2
        digitalWrite(sol_3_exchage_vapour, LOW);
      }
      if (test_no == 4) {
        //stop test 2
        digitalWrite(sol_4_dry, LOW);
      }
      if (test_no == 5) {
        //stop test 2
        digitalWrite(pump, LOW);
        digitalWrite(sol_1_exchage_gas, LOW);
      }
      if (test_no == 6) {
        //stop test 2
        digitalWrite(heater_triac, LOW);
        heater_on_flag=false;
      }
      counter = page - 1;
      pushed = 1;
      Ready = 0;
    }

    if (page == 2) {
      on_flag = true;
      writeBigString("ON ", 11, 0);
      if (test_no == 1) {
        on_flag = true;
        //run test 1
        digitalWrite(sol_1_exchage_gas, HIGH);
      }
      if (test_no == 2) {
        on_flag = true;
        //run test 2
        digitalWrite(sol_2_water, HIGH);
      }
      if (test_no == 3) {
        on_flag = true;
        //run test 2
        digitalWrite(sol_3_exchage_vapour, HIGH);
      }
      if (test_no == 4) {
        on_flag = true;
        //run test 2
        digitalWrite(sol_4_dry, HIGH);
      }
      if (test_no == 5) {
        //run test 2
        digitalWrite(sol_1_exchage_gas, HIGH);
        digitalWrite(pump, HIGH);
      }
      if (test_no == 6) {
        //run test 2
        digitalWrite(heater_triac, HIGH);
        heater_on_flag=true;
      }
      counter = page - 1;
      pushed = 1;
      Ready = 0;
    }

    if (up.isPressed() || down.isPressed())
    {
      io_stop_all();
      submenu = menu_tests_index;
      on_flag = false;
      page = 1;
      counter = test_no - 1;
    }
  }
}//end of submenu 4
