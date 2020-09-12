/*
 * TIMER0.c
 *
 *  Created on: Oct 31, 2018
 *      Author: Asim
 */

#include "TIMER0.h"

 void Timer0_init(void)
{
	 TCCR0=(1<<FOC0);
	 TCNT0=0;
}

 void  Timer0_start(void)
 {
 TCCR0=(1<<FOC0)|(1<<CS00)|(1<<CS02);
 }

 void  Timer0_stop(void)
 	 {
	 	 TCCR0=(1<<FOC0);
 	 }

 void  Timer0_clear(void)
 	 {
	 TCNT0=0;
 	 }

 uint8 Timer0_reading(void)
 	 {
	 	 return TCNT0;
 	 }
