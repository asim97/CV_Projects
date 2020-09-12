void refresh_lcd () {
  if ((last_counter > counter) || (last_counter < counter)  || pushed) //Only print on the LCD when a step is detected or the button is pushed.
  {
    Ready = 1;
    //Major screens
    //First page of the menu (choose program ,settings , about)
    submenu_main();

    //Second page of the menu choose program => (program 1,program 2,program 3,program 4)
    submenu_choose_program();

    //Third page of the menu settings => (setting 1,setting 2,setting 3,setting 4)
    submenu_prog_settings();
    submenu_settings_elements();
    submenu_sys_settings();

    //Forth page of the menu tests => (test 1,test 2,test 3,test 4)
    submenu_tests();

    //Fifth page of the menu about => (about authers in 4 pages)
    submenu_about();

    //minor screens
    submenu_prog_save();
    submenu_sys_save();
    submenu_prog_set_val();
    submenu_sys_set_val();
    submenu_test_run();
    submenu_ota();
    submenu_sys_rest();
    submenu_prog_run();
    submenu_prog_done();
    submenu_prog_stop();
    submenu_sys_error();
    submenu_settings_min_sec();
    submenu_temp_offset_set_val();
    submenu_temp_offset_save();
    submenu_screen_warning();
    submenu_heater_power_set_val();
    submenu_heater_power_save();
    submenu_temp_sensor_test();
  }//end of the MENU prints on the LCD

}

void lcd_first_screen() {
  //Print the first page menu.
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("=>");
  lcd.print("Choose Program");
  lcd.setCursor(0, 1);
  lcd.print("  Settings");
}

void splash_screan() {
  //Create Splash screan
  lcd.clear();

  writeBigString("S", 0, 0);
  delay(250);
  writeBigString("T", 3, 0);
  delay(250);
  writeBigString("A", 6, 0);
  delay(250);
  writeBigString("R", 9, 0);
  delay(250);
  writeBigString("T", 12, 0);
  delay(250);
  lcd.setCursor(15, 1);
  lcd.print("L");
  delay(1500);

}
