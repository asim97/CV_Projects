// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)

void DHT_INIT() {
  humidity = dht.readHumidity();
  // Read temperature as Celsius (the default)
  temp_c = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  temp_f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temp_c) || isnan(temp_f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
}

/********** Task Functions **********/
void READ_SENSORS() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  humidity = dht.readHumidity();
  // Read temperature as Celsius (the default)
  temp_c = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  temp_f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temp_c) || isnan(temp_f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  // Compute heat index in Fahrenheit (the default)
  heat_index_f = dht.computeHeatIndex(temp_f, humidity);
  // Compute heat index in Celsius (isFahreheit = false)
  heat_index_c = dht.computeHeatIndex(temp_c, humidity, false);

  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(temp_c);
  Serial.print(F("°C "));
  Serial.print(temp_f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(heat_index_c);
  Serial.print(F("°C "));
  Serial.print(heat_index_f);
  Serial.println(F("°F"));

}

void CHECK_ABNORM() {
  if (temp_c > MAX_TEMP_TH  )
    warning_code = HIGH_TEMP ;
  if (temp_f < MIN_TEMP_TH )
    warning_code = LOW_TEMP ;
  if (digitalRead(FIRE_SEN_D_PIN) == FIRE_SEN_active)
    warning_code = FIRE_DETECTED ;
    
}