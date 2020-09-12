/*
 * TIMER1.c
 *
 *  Created on: Oct 31, 2018
 *      Author: Asim
 */

#include "Timer2.h"

 void Timer2_init(void)
{
	 TCCR2=(1<<FOC2);
	 TCNT2=0;
}

 void  Timer2_start(void)
 {
 TCCR2=(1<<FOC2)|(1<<CS20)|(1<<CS21)|(1<<CS22);
 }

 void  Timer2_stop(void)
 	 {
	 	 TCCR2=(1<<FOC2);
 	 }

 void  Timer2_clear(void)
 	 {
	 TCNT2=0;
 	 }

 uint8 Timer2_reading(void)
 	 {
	 	 return TCNT2;
 	 }
