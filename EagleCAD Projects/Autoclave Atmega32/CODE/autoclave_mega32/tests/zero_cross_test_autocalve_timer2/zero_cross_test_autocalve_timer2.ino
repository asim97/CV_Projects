int pin = 2;
int pin_irq = 0; //IRQ that matches to pin 2
int angle_counter = 0;
byte heater_triac = 7;
byte set_power=10;


void setup() {
  // put your setup code here, to run once:
  pinMode(heater_triac, OUTPUT);
  attachInterrupt(pin_irq, zero_cross_isr, RISING);
  sei();//enable interrupts
}

void loop() {
  // put your main code here, to run repeatedly:

}

void zero_cross_isr() {
  angle_counter++;
  if (angle_counter >= 10) angle_counter = 0;
  if (angle_counter >= set_power) digitalWrite(heater_triac, LOW);
  else digitalWrite(heater_triac, HIGH);
}



