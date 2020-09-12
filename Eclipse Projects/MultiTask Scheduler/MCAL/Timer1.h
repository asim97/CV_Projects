/*
 * Timer1.h
 *
 *  Created on: Oct 31, 2018
 *      Author: Asim
 */

#ifndef TIMER1_H_
#define TIMER1_H_

#include "../Service_Layer/PLATFORM_TYPES.h"
#include <avr/io.h>

#define _1ms_Period		(1000UL)
#define _10ms_Period	(10000UL)
#define _100ms_Period	(100000UL)

#define TimerPeriod (_1ms_Period)


extern void  Timer1_init(void);
extern void  Timer1_start(void);
extern void  Timer1_stop(void);
extern void  Timer1_clear(void);
extern uint16 Timer1_reading(void);
extern void Timer1_Set_Cbk(void (*Cbk)(void));

#endif /* TIMER1_H_ */
