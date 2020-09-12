/*
 * ULTRASONIC.c
 *
 *  Created on: Oct 31, 2018
 *      Author: Asim
 */

#include "ULTRASONIC.h"
#include "../Service_Layer/PLATFORM_TYPES.h"
#include "../MCAL/DIO.h"
#include "../MCAL/TIMER2.h"
#include <util/delay.h>

void UltraSonic_init(void)
{
	SET_BIT(ULTRASONIC_TRIG_DDR,ULTRASONIC_TRIG_PIN);
	CLEAR_BIT(ULTRASONIC_ECHO_DDR,ULTRASONIC_ECHO_PIN);
	Timer2_init();

}

uint16 UltraSonic_read(void)
{
	double Time=0;
	uint16 Distance=0;

	CLEAR_BIT(ULTRASONIC_TRIG_PORT,ULTRASONIC_TRIG_PIN);
	_delay_ms(5);
	SET_BIT(ULTRASONIC_TRIG_PORT,ULTRASONIC_TRIG_PIN);
	_delay_us(10);
	CLEAR_BIT(ULTRASONIC_TRIG_PORT,ULTRASONIC_TRIG_PIN);

	while(BIT_CLEARED(ULTRASONIC_ECHO_PORT,ULTRASONIC_ECHO_PIN));

	Timer2_start();

	while( ( BIT_SET(ULTRASONIC_ECHO_PORT,ULTRASONIC_ECHO_PIN))&&(Timer2_reading() <250) );

	Timer2_stop();

	Time=Timer2_reading();
#if DISTANCE == CM
		Time*=(0.017*128);

#elif DISTANCE == M
		Time*=(0.00017*128);
#endif
		Distance=(uint16)Time;
		Timer2_clear();
		return Distance;

}


