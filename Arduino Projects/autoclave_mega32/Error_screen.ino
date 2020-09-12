
void submenu_sys_error() {
  if (submenu == menu_sys_error_index) {
    io_stop_all();
    lcd.clear();
    writeBigString("ERORR ", 0, 0);
    writeBigByteNum(error_code , 1 , 17, 0);
    counter = 0;
    pushed = 0;
    run_prog = false ;
    time_min = 0;
    time_sec = 0;
    EasyBuzzer.singleBeep(
      frequency,  // Frequency in hertz(HZ).
      3000  // Duration of the beep in milliseconds(ms).
    );
  }
}

void buttons_action_sys_error() {
  if (submenu == menu_sys_error_index)
  {
    if (error_in_test_submenu) {
      submenu = menu_tests_index;
      counter = test_no - 1;
    }
    else
    {
      submenu = menu_choose_program_index;
      counter = prog_no - 1;
    }
    pushed = 1;
    on_flag = false;
  }
}

void check_error_code() {
  if (sys_error)     //error screen display code
  {
    submenu = menu_sys_error_index;
    sys_error = false;
    pushed = 1;
  }
  if (warning_code == 1)
    if (digitalRead(door_sensor_pin) == 1)
    {
      submenu = menu_prog_run_index;
      update_outputs = true;
      pushed = 1;
      run_prog = true ;
    }

  if (warning_code == 2)
    if (digitalRead(pressure_switch_pin) == 1)
    {
      submenu = menu_prog_run_index;
      update_outputs = true;
      pushed = 1;
      run_prog = true ;
    }
}

