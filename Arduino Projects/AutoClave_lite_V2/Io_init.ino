void io_init() {
  //pinMode (buzzer , OUTPUT);      //Define the pin as output
  pinMode (backlight_lcd_pwm, OUTPUT);      //Define the pin as output
  pinMode (contrast_lcd_pwm , OUTPUT);      //Define the pin as output
  pinMode(heater_triac, OUTPUT);
  pinMode(door_sensor_pin, INPUT_PULLUP);
  //pinMode(water_sensor_pin, INPUT);
  pinMode(pressure_switch_pin, INPUT_PULLUP);
  
  pinMode(pump_fed, INPUT);


  //EasyBuzzer.setPin(buzzer);
}

void io_stop_all()
{
  outputs.setNoUpdate(sol_1_exchage_gas, LOW);
  outputs.setNoUpdate(sol_2_water, LOW);
  outputs.setNoUpdate(sol_3_exchage_vapour, LOW);
  outputs.setNoUpdate(sol_4_dry, LOW);
  outputs.setNoUpdate(pump, LOW);
  heater_on_flag=false;
  outputs.updateRegisters();
}
