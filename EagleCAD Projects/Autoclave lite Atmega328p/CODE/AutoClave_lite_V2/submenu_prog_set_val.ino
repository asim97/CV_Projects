
void submenu_prog_set_val() {
  //Third page of the menu settings (setting 1 ,.....)
  if (submenu == menu_prog_set_val_index)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("    Set New value");
    pushed = 0;
    lcd.setCursor(0, 1);
    lcd.print("DF:");

    if (min_prog_set)
      lcd.print(prog_defults_min[setting_no], DEC);
    else
      lcd.print(prog_defults_sec[setting_no], DEC);

    lcd.setCursor(7, 1);
    lcd.print("CR:");

    if (min_prog_set)
      lcd.print(stage_time_min[setting_no], DEC);
    else
      lcd.print(stage_time_sec[setting_no], DEC);

    lcd.setCursor(14, 1);
    lcd.print("NW:");
    lcd.print(temp_sitting_val, DEC);

    page = 1;
  }
}

void buttons_action_prog_set_val() {

  if (submenu == menu_prog_set_val_index)
  {
    if (page == 1)
    {
      if (setting_no <=9 )
        submenu = menu_prog_save_index;
      counter = 0;
      pushed = 1;
      Ready = 0;
    }//end of submenu 4
  }
}
