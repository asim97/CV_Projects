void submenu_choose_program() {
  //Second page of the menu (choose program)
  if (submenu == menu_choose_program_index) //menus of choose program
  {
    if (counter == 0) //when Program 1 selected
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("Sterilize at 121 C");
      lcd.setCursor(0, 1);
      lcd.print("  Sterilize at 134 C");
      page = 1;
      pushed = 0;
    }

    if (counter == 1) //when Program 2 selected
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Sterilize at 121 C");
      lcd.setCursor(0, 1);
      lcd.print("=>");
      lcd.print("Sterilize at 134 C");
      page = 2;
      pushed = 0;
    }

    if (counter == 2) //when back selected
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("=>");
      lcd.print("Back");
      lcd.setCursor(0, 1);
      lcd.print("  ");
      page = 5;
      pushed = 0;
    }
  }//submenu = 1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void buttons_action_choose_program() {
  if (submenu == menu_choose_program_index)
  {
    if (page == 1 || page == 2)
    {
      submenu = menu_prog_run_index;
      counter = 0;
      pushed = 1;
      Ready = 0;
      prog_no = page;
      prog_stage = 1;
      time_now_check = millis();
      read_sys_eeprom();
      time_sec = stage_time_sec[1];
      time_min = stage_time_min[1];
      page = 0;
      on_flag = true;
      run_prog = true;
      update_outputs = true;
    }

    if (page == 5) //back selected
    {
      submenu = menu_main_index;
      counter = menu_choose_program_index - 1;
      pushed = 1;
      Ready = 0;
    }
  }//end of submenu 1
}
