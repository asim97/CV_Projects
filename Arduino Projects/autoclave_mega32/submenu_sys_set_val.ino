
void submenu_sys_set_val() {
  //Third page of the menu settings (setting 1 ,.....)
  if (submenu == menu_sys_set_val_index)
  {
    if (setting_no == 1 || setting_no == 2) {
      lcd.clear();
      lcd.setCursor(0, 0);
      if (setting_no == 1) lcd.print("Backlight");
      if (setting_no == 2) lcd.print("Contrats");

      lcd.setCursor(0, 1);
      lcd.print("CR: ");
      lcd.print(sys_sittings[setting_no], DEC);

      writeBigByteNum(temp_sitting_val , 3 , 10, 0);

      lcd.setCursor(19, 0);
      lcd.print("%");
      page = 50;
      pushed = 0;
    }
  }
}

void buttons_action_sys_set_val() {

  if (submenu == menu_sys_set_val_index)
  {
    if (page == 50)
    {
      if (setting_no == 1) {
        submenu = menu_sys_save_index;
      }
      if (setting_no == 2) {
        submenu = menu_sys_save_index;
      }
      counter = 0;
      pushed = 1;
      Ready = 0;
    }//end of submenu 4
  }
}
