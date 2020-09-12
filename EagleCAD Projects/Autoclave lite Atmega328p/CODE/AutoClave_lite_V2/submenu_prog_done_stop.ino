
void submenu_prog_done() {
  if (submenu == menu_prog_done_index) {
    lcd.clear();
    writeBigString("DONE ", 3, 0);
    counter = 0;
    pushed = 0;
    run_prog = false ;
    time_min = 0;
    time_sec = 0;
    io_stop_all();
  }
}

void buttons_action_prog_done() {
  if (submenu == menu_prog_done_index)
  {
    submenu = menu_choose_program_index;
    counter = prog_no - 1;
    pushed = 1;
    on_flag = false;
  }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void submenu_prog_stop() {
  if (submenu == menu_prog_stop_index) {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Stop Program ?");
    lcd.setCursor(0, 1);
    pushed = 0;
    if (counter == 0) //when Line 1 selected
    {
      lcd.print("=>NO       YES");
      page = 1;
    }
    if (counter == 1) //when Line 2 selected
    {
      lcd.print("  NO     =>YES");
      page = 2;

    }
  }
}

void buttons_action_prog_stop() {
  if (submenu == menu_prog_stop_index)
  {
    if (page == 1) {
      submenu = menu_prog_run_index;
    }
    if (page == 2) {
      submenu = menu_choose_program_index;
      run_prog = false ;
      on_flag = false;
      time_min = 0;
      time_sec = 0;
      io_stop_all();
    }
    page=0;
    counter = prog_no - 1;
    pushed = 1;
    Ready = 0;
  }
}
