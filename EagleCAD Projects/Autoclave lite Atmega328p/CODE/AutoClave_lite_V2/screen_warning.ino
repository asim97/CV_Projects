void submenu_screen_warning() {
  if (submenu == menu_screen_warning_index) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("WARNING! (pused)");
    lcd.setCursor(0, 1);
    if (warning_code == 1)
      lcd.print("Close the door !");
    if (warning_code == 2)
      lcd.print("Pressure is HIGH");
    counter = 0;
    pushed = 0;
    run_prog = false ;
//    EasyBuzzer.beep(
//      frequency,  // Frequency in Hertz(HZ).
//      2   // The number of beeps.
//    );
    if (warning_code == 1 || warning_code == 2)
      io_stop_all();

  }
}

void buttons_action_screen_warning() {
  if (submenu == menu_screen_warning_index)
  {
    submenu = menu_prog_run_index;
    update_outputs = true;
    pushed = 1;
    run_prog = true ;
  }
}
