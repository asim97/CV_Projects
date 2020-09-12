//Now we detect when we push the button
void buttons_action() {

  last_counter = counter; //Save the value of the last state

  if (up.uniquePress())
  {
    /* Single beep. */
    EasyBuzzer.singleBeep(frequency, button_buzzer_duration);
    counter ++;
    if (submenu == menu_prog_set_val_index)
      if (min_prog_set)
        temp_sitting_val -= 1;
      else
        temp_sitting_val -= 5;
    if (submenu == menu_sys_set_val_index) temp_sitting_val -= 20;
    if (submenu == menu_temp_offset_index) temp_sitting_val -= 5;
    if (submenu == menu_heater_power_set_val_index) heater_set_val_temp -= 20;
  }
  if (down.uniquePress())
  {
    EasyBuzzer.singleBeep(frequency, button_buzzer_duration);
    counter --;
    if (submenu == menu_prog_set_val_index)
      if (min_prog_set)
        temp_sitting_val += 1;
      else
        temp_sitting_val += 5;
    if (submenu == menu_sys_set_val_index) temp_sitting_val += 20;
    if (submenu == menu_temp_offset_index) temp_sitting_val += 5;
    if (submenu == menu_heater_power_set_val_index) heater_set_val_temp += 20;
  }

  if (ok.uniquePress())
  {
    EasyBuzzer.singleBeep(frequency, button_buzzer_duration);

    buttons_action_choose_program();

    buttons_action_prog_settings();
    buttons_action_settings();
    buttons_action_sys_settings();

    buttons_action_test();

    buttons_action_about();

    buttons_action_main();

    buttons_action_prog_save();
    buttons_action_sys_save();
    buttons_action_prog_set_val();
    buttons_action_sys_set_val();
    buttons_action_test_run();
    buttons_action_ota();
    buttons_action_sys_rest();
    buttons_action_prog_run();
    buttons_action_prog_done();
    buttons_action_prog_stop();
    buttons_action_sys_error();
    buttons_action_min_sec();
    buttons_action_temp_offset_set_val();
    buttons_action_temp_offset_save();
    buttons_action_screen_warning();
    buttons_action_heater_power_set_val();
    buttons_action_heater_power_save();
  }
  limit_counter();

}

void buzzer_tone() {
  digitalWrite(buzzer, HIGH); // Send sound signal...
  delay(300);        // ...for 0.3 sec
  digitalWrite(buzzer, LOW);   // Stop sound...
}

void limit_counter() {
  if (submenu == menu_main_index) {
    if (counter > menu_main_elements - 1 )counter = menu_main_elements - 1;
    if (counter < 0)counter =  0;
  }
  if (submenu == menu_choose_program_index) {
    if (counter > menu_choose_program_elements - 1 )counter = menu_choose_program_elements - 1;
    if (counter < 0)counter =  0;
  }
  if (submenu == menu_prog_settings_index) {
    if (counter > menu_prog_settings_elements - 1 )counter = menu_prog_settings_elements - 1;
    if (counter < 0)counter =  0;
  }
  if (submenu == menu_sys_settings_index) {
    if (counter > menu_sys_settings_elements - 1 )counter = menu_sys_settings_elements - 1;
    if (counter < 0)counter =  0;
  }
  if (submenu ==  menu_about_index) {
    if (counter > menu_about_elements - 1 )counter = menu_about_elements - 1;
    if (counter < 0)counter =  0;
  }
  if (submenu == menu_tests_index) {
    if (counter > menu_tests_elements - 1 )counter = menu_tests_elements - 1;
    if (counter < 0)counter = 0;
  }
  if (submenu == menu_prog_save_index) {
    if (counter > menu_prog_save_elements - 1 )counter = menu_prog_save_elements - 1;
    if (counter < 0)counter = 0;
  }
  if (submenu == menu_sys_save_index) {
    if (counter > menu_sys_save_elements - 1 )counter = menu_sys_save_elements - 1;
    if (counter < 0)counter = 0;
  }
  if (submenu == menu_sys_rest_index) {
    if (counter > menu_sys_rest_elements - 1 )counter = menu_sys_rest_elements - 1;
    if (counter < 0)counter = 0;
  }
  if (submenu == menu_test_run_index) {
    if (counter > menu_test_run_elements - 1 )counter = menu_test_run_elements - 1;
    if (counter < 0)counter = 0;
  }
  if (submenu == menu_ota_index) {
    if (counter > menu_ota_elements - 1 )counter = menu_ota_elements - 1;
    if (counter < 0)counter = 0;
  }
  if (submenu == menu_settings_index) {
    if (counter > menu_settings_elements - 1 )counter = menu_settings_elements - 1;
    if (counter < 0)counter = 0;
  }
  if (submenu == menu_prog_stop_index) {
    if (counter > menu_prog_stop_elements - 1 )counter = menu_prog_stop_elements - 1;
    if (counter < 0)counter = 0;
  }
  if (submenu == menu_min_sec_index) {
    if (counter > menu_min_sec_elements - 1 )counter = menu_min_sec_elements - 1;
    if (counter < 0)counter = 0;
  }
  if (submenu == menu_temp_offset_save_index) {
    if (counter > menu_temp_offset_save_elements - 1 )counter = menu_temp_offset_save_elements - 1;
    if (counter < 0)counter = 0;
  }
  if (submenu == menu_heater_power_save_index) {
    if (counter > menu_heater_power_save_elements - 1 )counter = menu_heater_power_save_elements - 1;
    if (counter < 0)counter = 0;
  }
  if (submenu == menu_prog_set_val_index) {
    if (min_prog_set)
    {
      if (temp_sitting_val > 250 )temp_sitting_val = 250;
      if (temp_sitting_val <= 0)temp_sitting_val = 0;
    }
    else
    {
      if (temp_sitting_val > 59)temp_sitting_val = 59;
      if (temp_sitting_val <= 0)temp_sitting_val = 0;
    }
  }
  if (submenu == menu_sys_set_val_index) {
    if (temp_sitting_val > 100 )temp_sitting_val = 100;
    if (temp_sitting_val <= 0)temp_sitting_val = 0;
  }
  if (submenu == menu_temp_offset_index) {
    if (temp_sitting_val > 50 )temp_sitting_val = 50;
    if (temp_sitting_val <= -50)temp_sitting_val = -50;
  }
  if (submenu == menu_heater_power_set_val_index) {
    if (heater_set_val_temp > 3000 )heater_set_val_temp = 3000;
    if (heater_set_val_temp <= 0)heater_set_val_temp = 0;
  }
}
