void program_runinng() {
  if (run_prog && sys_error == false) {
    if (update_outputs)
    {
      switch (prog_stage)
      {
        case 1:    //Vacm
          outputs.setNoUpdate(sol_1_exchage_gas, HIGH);
          outputs.setNoUpdate(sol_2_water, LOW);
          outputs.setNoUpdate(sol_3_exchage_vapour, LOW);
          outputs.setNoUpdate(sol_4_dry, LOW);
          outputs.setNoUpdate(pump, HIGH);
          heater_on_flag = false;
          break;
        case 2:   //Fill_1
          outputs.setNoUpdate(sol_1_exchage_gas, HIGH);
          outputs.setNoUpdate(sol_2_water, HIGH);
          outputs.setNoUpdate(sol_3_exchage_vapour, LOW);
          outputs.setNoUpdate(sol_4_dry, LOW);
          outputs.setNoUpdate(pump, HIGH);
          heater_on_flag = false;
          break;
        case 3:   //Fill_2
          outputs.setNoUpdate(sol_1_exchage_gas, LOW);
          outputs.setNoUpdate(sol_2_water, HIGH);
          outputs.setNoUpdate(sol_3_exchage_vapour, LOW);
          outputs.setNoUpdate(sol_4_dry, LOW);
          outputs.setNoUpdate(pump, LOW);
          heater_on_flag = false;
          break;
        case 4:   //Heat
          outputs.setNoUpdate(sol_1_exchage_gas, LOW);
          outputs.setNoUpdate(sol_2_water, LOW);
          outputs.setNoUpdate(sol_3_exchage_vapour, LOW);
          outputs.setNoUpdate(sol_4_dry, LOW);
          outputs.setNoUpdate(pump, LOW);
          heater_on_flag = true;
          break;
        case 5:   //Ster
          if (prog_no == 1) stage_time_min[5] = 25;   //25 min for 121 c
          if (prog_no == 2) stage_time_min[5] = 10;   //25 min for 134 c
          outputs.setNoUpdate(sol_1_exchage_gas, LOW);
          outputs.setNoUpdate(sol_2_water, LOW);
          outputs.setNoUpdate(sol_3_exchage_vapour, LOW);
          outputs.setNoUpdate(sol_4_dry, LOW);
          outputs.setNoUpdate(pump, LOW);
          heater_on_flag = true;
          break;
        case 6:   //Vent_1
          outputs.setNoUpdate(sol_1_exchage_gas, LOW);
          outputs.setNoUpdate(sol_2_water, HIGH);
          outputs.setNoUpdate(sol_3_exchage_vapour, LOW);
          outputs.setNoUpdate(sol_4_dry, LOW);
          outputs.setNoUpdate(pump, LOW);
          heater_on_flag = false;
          break;
        case 7:   //Vent_2
          outputs.setNoUpdate(sol_1_exchage_gas, LOW);
          outputs.setNoUpdate(sol_2_water, LOW);
          outputs.setNoUpdate(sol_3_exchage_vapour, HIGH);
          outputs.setNoUpdate(sol_4_dry, LOW);
          outputs.setNoUpdate(pump, LOW);
          heater_on_flag = false;
          break;
        case 8:   //Dry_1
          outputs.setNoUpdate(sol_1_exchage_gas, HIGH);
          outputs.setNoUpdate(sol_2_water, LOW);
          outputs.setNoUpdate(sol_3_exchage_vapour, LOW);
          outputs.setNoUpdate(sol_4_dry, LOW);
          outputs.setNoUpdate(pump, LOW);
          heater_on_flag = false;
          break;
        case 9:   //Dry_2
          outputs.setNoUpdate(sol_1_exchage_gas, LOW);
          outputs.setNoUpdate(sol_2_water, LOW);
          outputs.setNoUpdate(sol_3_exchage_vapour, LOW);
          outputs.setNoUpdate(sol_4_dry, HIGH);
          outputs.setNoUpdate(pump, LOW);
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
      outputs.updateRegisters();
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

      temp = digitalRead(pump_fed);
      //if (temp == LOW) {
      if (false) {
        error_code = 5;               //pump_fed faild
        sys_error = true;
        break;
      }
      break;

    case 2:   //Fill_1

      temp = digitalRead(pump_fed);
      //if (temp == LOW) {
      if (false) {
        error_code = 5;               //pump_fed faild
        sys_error = true;
        break;
      }

      break;

    default:
      break;
  }
}
