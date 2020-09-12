#include <ShiftLCD.h>                // for using shift register as LCD interface driver

#define clock_pin         25    //shift register clock pin // SHCP
#define data_pin          9    //shift register data pin  // DS
#define latch_pin         3    //shift register latch pin // STCP

ShiftLCD lcd(data_pin, clock_pin, latch_pin);

void ADC_init(void)
{
  ADMUX = (1 << REFS0) | (1 << MUX0);
  ADCSRA = (1 << ADEN) | (1 << ADPS1) | (1 << ADPS2);

}

int ADC_read(byte Channel)
{
  ADMUX &= 0xE0; // clear least 5 bits (channel)
  Channel &= 0x07; //reassignation for the input argument
  ADMUX |= Channel;

  ADCSRA |= (1 << ADSC);
  while (ADCSRA & (1 << ADSC));
  return ADC;
}

void setup() {
  // put your setup code here, to run once:
  ADC_init();
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(ADC_read(4), DEC);
  lcd.setCursor(0, 1);
  lcd.print(analogRead(A3), DEC);                             //////////////////////////////////////////////////////////////remove this
  delay(500);
}
