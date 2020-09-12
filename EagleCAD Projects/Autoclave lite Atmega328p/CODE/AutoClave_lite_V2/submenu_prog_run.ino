
void submenu_prog_run() {

  if (submenu == menu_prog_run_index)
  {
    pushed = 0;

    lcd.clear();
    lcd.setCursor(0, 0);

    if (prog_stage == 1)  lcd.print("Vacuuming");//
    if (prog_stage == 2)  lcd.print("Filling_1");
    if (prog_stage == 3)  lcd.print("Filling_2");
    if (prog_stage == 4)  lcd.print("Heating  ");
    if (prog_stage == 5)  lcd.print("Sterilize");
    if (prog_stage == 6)  lcd.print("Venting_1");
    if (prog_stage == 7)  lcd.print("Venting_2");
    if (prog_stage == 8)  lcd.print("Drying_1 ");
    if (prog_stage == 9)  lcd.print("Drying_2 ");

    lcd.setCursor(0, 1);
    lcd.print("ETC ");
    lcd.print(time_min, DEC);       //print time in mint
    lcd.print(":");
    lcd.print(time_sec, DEC);       //print time in mint
    temp_read = thermocouple.readCelsius();
    writeBigByteNum((byte)temp_read , 3 , 10, 0);
    lcd.setCursor(19, 0);
    lcd.print("C");

  }
}



void buttons_action_prog_run() {
  if (submenu == menu_prog_run_index)
  {
    if (up.isPressed() || down.isPressed())
    {
      submenu = menu_prog_stop_index;
      counter = 0;
      pushed = 1;
      run_prog = true;
    }
  }
}

void screen_timer() {
  if (run_prog && sys_error == false) {
    if (millis() > time_now + run_screen_refresh) {
      time_now = millis();
      temp_read = thermocouple.readCelsius();
      pushed = 1;
      time_sec--;
      if (time_sec < 0) {
        time_min--;
        time_sec = 59;
      }
      if (time_min < 0) {
        prog_stage++;
        time_now_check = millis();
        if (prog_stage < 10) {
          time_sec = stage_time_sec[prog_stage];
          time_min = stage_time_min[prog_stage];
          if (prog_stage == 5) {
            if (prog_no == 1 ) {
              time_sec = stage_time_sec[prog_stage];
              time_min = stage_time_min[prog_stage];                                ///offset is added here
            }
            if (prog_no == 2 )
            {
              time_min = stage_time_min[0];                                ///offset is added here
              time_sec = stage_time_sec[0];
            }
          }
          update_outputs = true;
        }
      }
    }
  }
}
