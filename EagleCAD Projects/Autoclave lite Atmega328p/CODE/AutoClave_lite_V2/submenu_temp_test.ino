
void submenu_temp_sensor_test() {
  if (submenu == menu_temp_sensor_test_index) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp Sensor Test");
    lcd.setCursor(0, 1);
    temp_read = thermocouple.readCelsius();
    lcd.print(" x ");
    lcd.print(temp_read);
    delay(500);
    pushed = 1;
  }
}

void buttons_action_temp_sensor_test() {
  if (submenu == menu_temp_sensor_test_index)
  {
    if (up.isPressed() || down.isPressed())
    {
      submenu = menu_tests_index;
      counter = 6;
      pushed = 1;
    }
  }
}
