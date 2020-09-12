void io_init() {
  pinMode (buzzer , OUTPUT);      //Define the pin as output
  pinMode (backlight_lcd_pwm, OUTPUT);      //Define the pin as output
  pinMode (contrast_lcd_pwm , OUTPUT);      //Define the pin as output

  pinMode (RX_PIN, INPUT);      //Define the pin as INPUT
  pinMode (TX_PIN, INPUT);      //Define the pin as INPUT

  pinMode(sol_1_exchage_gas, OUTPUT);
  pinMode(sol_2_water, OUTPUT);
  pinMode(sol_3_exchage_vapour, OUTPUT);
  pinMode(sol_4_dry, OUTPUT);
  pinMode(pump, OUTPUT);
  pinMode(heater_triac, OUTPUT);

  pinMode(door_sensor_pin, INPUT);
  pinMode(water_sensor_pin, INPUT);
  pinMode(pressure_switch_pin, INPUT);
  pinMode(sol_1_exchage_gas_fed, INPUT);
  pinMode(sol_2_water_fed, INPUT);
  pinMode(sol_3_exchage_vapour_fed, INPUT);
  pinMode(sol_4_dry_fed, INPUT);
  pinMode(pump_fed, INPUT);
  pinMode(heater_fed, INPUT);  //      HEATER is analog innput

  EasyBuzzer.setPin(buzzer);
}

void io_stop_all()
{
  digitalWrite(sol_1_exchage_gas, LOW);
  digitalWrite(sol_2_water, LOW);
  digitalWrite(sol_3_exchage_vapour, LOW);
  digitalWrite(sol_4_dry, LOW);
  digitalWrite(pump, LOW);
  heater_on_flag=false;
}
