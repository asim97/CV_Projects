void timer2_init() {
  TCCR2 = 0x04; //devider 64
  TCNT2 = 256 - 138;
  TIMSK |= _BV(TOIE2);
}

void zero_cross_isr() {
  angle_counter = 0;
}

ISR(TIMER2_OVF_vect) {
  TCNT2 = 256 - 138;
  angle_counter++;
  if ((angle_counter == angle_fired) && heater_on_flag) //fire triac
  {
    digitalWrite(heater_triac, HIGH);
    delayMicroseconds(triac_fire_us);
    digitalWrite(heater_triac, LOW);
  }
  if (heater_on_flag == false)digitalWrite(heater_triac, LOW);
}



