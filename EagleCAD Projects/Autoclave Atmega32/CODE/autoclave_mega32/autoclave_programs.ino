/*
     templete for program stages

   void prog_() {
   switch (current_stage)
   {
     case 0:

      break;
     case 1:

       break;
     case 2:

      break;
     case 3:

      break;
     case 4:

      break;
     case 5:

      break;
     case 6:

      break;
     case 7:

      break;
     default:
      break;
  }
  }

    if (prog_stage == 1)  lcd.print("Vacm");
    if (prog_stage == 2)  lcd.print("Fill");
    if (prog_stage == 3)  lcd.print("Heat");
    if (prog_stage == 4)  lcd.print("Ster");
    if (prog_stage == 5)  lcd.print("Vent");
    if (prog_stage == 6)  lcd.print("Dry ");

*/
void program_runinng() {
  if (run_prog && sys_error == false) {
    if (update_outputs)
    {
      switch (prog_stage)
      {
        case 1:    //Vacm
          digitalWrite(sol_1_exchage_gas, HIGH);
          digitalWrite(sol_2_water, LOW);
          digitalWrite(sol_3_exchage_vapour, LOW);
          digitalWrite(sol_4_dry, LOW);
          digitalWrite(pump, HIGH);
          heater_on_flag = false;
          break;
        case 2:   //Fill_1
          digitalWrite(sol_1_exchage_gas, HIGH);
          digitalWrite(sol_2_water, HIGH);
          digitalWrite(sol_3_exchage_vapour, LOW);
          digitalWrite(sol_4_dry, LOW);
          digitalWrite(pump, HIGH);
          heater_on_flag = false;
          break;
        case 3:   //Fill_2
          digitalWrite(sol_1_exchage_gas, LOW);
          digitalWrite(sol_2_water, HIGH);
          digitalWrite(sol_3_exchage_vapour, LOW);
          digitalWrite(sol_4_dry, LOW);
          digitalWrite(pump, LOW);
          heater_on_flag = false;
          break;
        case 4:   //Heat
          digitalWrite(sol_1_exchage_gas, LOW);
          digitalWrite(sol_2_water, LOW);
          digitalWrite(sol_3_exchage_vapour, LOW);
          digitalWrite(sol_4_dry, LOW);
          digitalWrite(pump, LOW);
          heater_on_flag = true;
          break;
        case 5:   //Ster
          if (prog_no == 1) stage_time_min[5] = 25;   //25 min for 121 c
          if (prog_no == 2) stage_time_min[5] = 10;   //25 min for 134 c
          digitalWrite(sol_1_exchage_gas, LOW);
          digitalWrite(sol_2_water, LOW);
          digitalWrite(sol_3_exchage_vapour, LOW);
          digitalWrite(sol_4_dry, LOW);
          digitalWrite(pump, LOW);
          heater_on_flag = true;
          break;
        case 6:   //Vent_1
          digitalWrite(sol_1_exchage_gas, LOW);
          digitalWrite(sol_2_water, HIGH);
          digitalWrite(sol_3_exchage_vapour, LOW);
          digitalWrite(sol_4_dry, LOW);
          digitalWrite(pump, LOW);
          heater_on_flag = false;
          break;
        case 7:   //Vent_2
          digitalWrite(sol_1_exchage_gas, LOW);
          digitalWrite(sol_2_water, LOW);
          digitalWrite(sol_3_exchage_vapour, HIGH);
          digitalWrite(sol_4_dry, LOW);
          digitalWrite(pump, LOW);
          heater_on_flag = false;
          break;
        case 8:   //Dry_1
          digitalWrite(sol_1_exchage_gas, HIGH);
          digitalWrite(sol_2_water, LOW);
          digitalWrite(sol_3_exchage_vapour, LOW);
          digitalWrite(sol_4_dry, LOW);
          digitalWrite(pump, LOW);
          heater_on_flag = false;
          break;
        case 9:   //Dry_2
          digitalWrite(sol_1_exchage_gas, LOW);
          digitalWrite(sol_2_water, LOW);
          digitalWrite(sol_3_exchage_vapour, LOW);
          digitalWrite(sol_4_dry, HIGH);
          digitalWrite(pump, LOW);
          heater_on_flag = false;
          break;

        case 10:   //Done
          run_prog = false ;
          submenu = menu_prog_done_index;
          time_sec = 0;
          time_min = 0;
          counter = 0;
          pushed = 1;
          prog_stage = 0;
          //turn off all outputs
          io_stop_all();          
          break;
        default:
          break;
      }
      delay(5); // delay to make sure all SSR are workig
    }
    switch (prog_stage)
    {
      case 2:   //Fill_1
        if (digitalRead(water_sensor_pin) == HIGH) {
          prog_stage++;
          if (prog_stage < 10) {
            time_sec = stage_time_sec[prog_stage];
            time_min = stage_time_min[prog_stage];
          }
        }
        break;

      case 3:   //Fill_2
        if (digitalRead(water_sensor_pin) == HIGH) {
          prog_stage++;
          if (prog_stage < 10) {
            time_sec = stage_time_sec[prog_stage];
            time_min = stage_time_min[prog_stage];
          }
        }
        else if (time_min <= 0 && time_sec <= 5)
        {
          error_code = 1;  //water fill timeout reached
          sys_error = true;
        }
        break;
      case 4:   //Heat
        //temp_read = temp_desired;                                            /////////////////////////////////remove this line
        if (( temp_read <= temp_desired + temp_delta ) && ( temp_read >= temp_desired ))
        {
          prog_stage++;
          if (prog_stage < 10) {
            time_sec = stage_time_sec[prog_stage];
            time_min = stage_time_min[prog_stage];
          }
        }
        else if (time_min <= 0 && time_sec <= 5)
        {
          error_code = 2;  //heater  timeout reached
          sys_error = true;
        }
        fuzzy_loop_heater();
        break;
      case 5:   //Ster
        fuzzy_loop_heater();
        break;
      case 7:   //Vent_2
        //temp_read=99;                                            /////////////////////////////////remove this line
        if (temp_read <= 99)
        {
          prog_stage++;
          if (prog_stage < 10) {
            time_sec = stage_time_sec[prog_stage];
            time_min = stage_time_min[prog_stage];
          }
        }
        else if (time_min <= 0 && time_sec <= 5)
        {
          error_code = 3;  //Vent_2 timeout reached
          sys_error = true;
        }
        break;
      default:
        break;
    }
    update_outputs = false;
    if (millis() > time_now_check + period_check) check_errors();
    if (digitalRead(door_sensor_pin) == 0)
    {
      submenu = menu_screen_warning_index;
      warning_code = 1;    //door is open
    }
    if (digitalRead(pressure_switch_pin) == 0)
    {
      submenu = menu_screen_warning_index;
      warning_code = 2;         //pressure is high
    }
  }
}

void check_errors() {
  switch (prog_stage)
  {
    case 1:    //Vacm
      temp = digitalRead(sol_1_exchage_gas_fed);
      if (temp == LOW) {
        error_code = 4;                //sol_1_exchage_gas_fed faild
        sys_error = true;
        break;
      }
      temp = digitalRead(pump_fed);
      if (temp == LOW) {
        error_code = 5;               //pump_fed faild
        sys_error = true;
        break;
      }
      break;

    case 2:   //Fill_1
      temp = digitalRead(sol_1_exchage_gas_fed);
      if (temp == LOW) {
        error_code = 4;                //sol_1_exchage_gas_fed faild
        sys_error = true;
        break;
      }
      temp = digitalRead(pump_fed);
      if (temp == LOW) {
        error_code = 5;               //pump_fed faild
        sys_error = true;
        break;
      }
      temp = digitalRead(sol_2_water_fed);
      if (temp == LOW) {
        error_code = 6;               //sol_2_water faild
        sys_error = true;
        break;
      }
      break;

    case 3:   //Fill_2
      temp = digitalRead(sol_2_water_fed);
      if (temp == LOW) {
        error_code = 6;               //sol_2_water faild
        sys_error = true;
        break;
      }
      break;

    case 4:   //Heat
      heater_power_calculated_from_saved = analogRead(heater_fed) * 5000 / 1032 * 220 * angle_fired / 170;
      if (((heater_power_now + heater_power_delta_error) < heater_power_calculated_from_saved) || ((heater_power_now - heater_power_delta_error) > heater_power_calculated_from_saved)) {
        error_code = 7;               //HEATER faild
        sys_error = true;
        break;
      }
      if ((heater_power_now + heater_power_delta_warning) < heater_power_calculated_from_saved) {
        submenu = menu_screen_warning_index;
        warning_code = 3;    //heater is drawing less power
        break;
      }
      if ((heater_power_now - heater_power_delta_warning) > heater_power_calculated_from_saved) {
        submenu = menu_screen_warning_index;
        warning_code = 4;    //heater is drawing less power
        break;
      }
      break;
    case 5:   //Ster
      heater_power_calculated_from_saved = analogRead(heater_fed) * 5000 / 1032 * 220 * angle_fired / 170;
      if (((heater_power_now + heater_power_delta_error) < heater_power_calculated_from_saved) || ((heater_power_now - heater_power_delta_error) > heater_power_calculated_from_saved)) {
        error_code = 7;               //HEATER faild
        sys_error = true;
        break;
      }
      if ((heater_power_now + heater_power_delta_warning) < heater_power_calculated_from_saved) {
        submenu = menu_screen_warning_index;
        warning_code = 3;    //heater is drawing less power
        break;
      }
      if ((heater_power_now - heater_power_delta_warning) > heater_power_calculated_from_saved) {
        submenu = menu_screen_warning_index;
        warning_code = 4;    //heater is drawing less power
        break;
      }
      break;

    case 6:   //Vent_1
      temp = digitalRead(sol_2_water_fed);
      if (temp == LOW) {
        error_code = 6;               //sol_2_water faild
        sys_error = true;
        break;
      }
      break;
    case 7:   //Vent_2
      temp = digitalRead(sol_3_exchage_vapour_fed);
      if (temp == LOW) {
        error_code = 8;               //sol_3_water faild
        sys_error = true;
        break;
      }
      break;

    case 8:   //Dry_1
      temp = digitalRead(sol_1_exchage_gas_fed);
      if (temp == LOW) {
        error_code = 4;               //sol_1_exchage_gas_fed faild
        sys_error = true;
        break;
      }
      break;

    case 9:   //Dry_2
      temp = digitalRead(sol_4_dry_fed);
      if (temp == LOW) {
        error_code = 9;               //sol_4_dry_fed faild
        sys_error = true;
        break;
      }
      break;

    default:
      break;
  }
}

