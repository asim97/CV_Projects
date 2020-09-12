/*
 * Timer1.c
 *
 *  Created on: Oct 31, 2018
 *      Author: Asim
 */

#include "Timer1.h"
#include <avr/interrupt.h>

static void (*PTR)(void)= NULL ;

void  Timer1_init(void)
{
	TCCR1A = (1<<FOC1A)|(1<<FOC1B);
	TCCR1B = 0;
	OCR1A = 0;
	OCR1B = 0;
	ICR1 = 0;
	TIMSK |=(1<<TOIE1);
	SREG=(1<<7);
	/* Initial value of Timer Register _1ms */
	TCNT1 = (65536ul - (TimerPeriod /8ul) );
}


void  Timer1_start(void)
{
	/* 8MHZ/64 -> 1_Tic - 8us  */
	TCCR1B = (1<<CS11)|(1<<CS10);
}

void  Timer1_stop(void)
{
	TCCR1B = 0;
}

void  Timer1_clear(void)
{
	TCNT1=0;
}

uint16 Timer1_reading(void)
{
	return TCNT1;
}

void Timer1_Set_Cbk(void (*Cbk)(void))
{
	PTR = Cbk;
}

ISR(TIMER1_OVF_vect)
{
	/* Loading the Timer Register with the desired Value _1ms */
	TCNT1 = (65536ul - (TimerPeriod /8ul) );
	if(PTR != NULL )
	{
		PTR();
	}
}
