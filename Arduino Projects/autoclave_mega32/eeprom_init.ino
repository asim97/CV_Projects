void EEPROMWriteInt(int address, int value)
{
  byte two = (value & 0xFF);
  byte one = ((value >> 8) & 0xFF);

  EEPROM.update(address, two);
  EEPROM.update(address + 1, one);
}

int EEPROMReadInt(int address)
{
  long two = EEPROM.read(address);
  long one = EEPROM.read(address + 1);

  return ((two << 0) & 0xFFFFFF) + ((one << 8) & 0xFFFFFFFF);
}

void read_sys_eeprom() {
  for (byte i = 0; i < prog_stages_times_array; i++)    stage_time_min[i] = EEPROM.read(i + 0);
  for (byte i = 0; i < prog_stages_times_array; i++)    stage_time_sec[i] = EEPROM.read(i + 10);
  for (byte i = 0; i < menu_sys_settings_elements; i++)  sys_sittings[i]  = EEPROM.read(i + 20);
  //read temp offset
  temp_offset_sign = EEPROM.read(30);
  temp_offset = EEPROM.read(31);
  if (temp_offset_sign) //if sign =1 then offset is negative
    temp_offset *= -1;

  //read saved heater power value
 heater_power_saved_settings= EEPROMReadInt(28);
}

void init_sys() {
  read_sys_eeprom();

  if ( EEPROM.read(4 + 20) == 0) {   //wifi ota saved status in Sitting eeprom index 20
    pinMode(CH_PD, OUTPUT);
    digitalWrite(CH_PD, LOW);                    //disable wifi module
  }
  else
    pinMode(CH_PD, INPUT);

  //pwm of backlight LED
  temp = sys_sittings[1];
  if (temp >= 100) {
    temp = 100;
    sys_sittings[1] = 100;
  }
  temp = map(temp, 0, 100, backlight_lcd_min, backlight_lcd_max);
  analogWrite(backlight_lcd_pwm, temp);                                 ////////////////////////////////////////uncomment
  //pwm of contrast of lcd
  temp = sys_sittings[2];
  if (temp >= 100) {
    temp = 100;
    sys_sittings[2] = 100;
  }
  temp = map(temp, 0, 100, contrast_lcd_min, contrast_lcd_max);
  analogWrite(contrast_lcd_pwm, temp);                                  ////////////////////////////////////////uncomment
}
