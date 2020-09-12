/*
 * ADC.c
 *
 *  Created on: Oct 31, 2018
 *      Author: Asim
 */
#include <avr/io.h>
#include "../Service_Layer/PLATFORM_TYPES.h"

void ADC_init(void)
 {
	ADMUX=(1<<REFS0)|(1<<MUX0);
	ADCSRA=(1<<ADEN)|(1<<ADPS1)|(1<<ADPS2);

 }

int ADC_read(uint8 Channel)
 {
	ADMUX &=0xE0; // clear least 5 bits (channel)
	Channel &=0x07; //reassignation for the input argument
	ADMUX |=Channel;

	ADCSRA |=(1<<ADSC);
	while(ADCSRA & (1<<ADSC));
	return ADC;
 }


