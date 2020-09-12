/*
 * Scheduler.c
 *
 *  Created on: Oct 31, 2018
 *      Author: Asim
 */


#include "../MCAL/Timer1.h"

static volatile unsigned long Tic_Cnt = 0;
static void (*Task_Ptr[6]) (void);
static void Scheduler_Update(void);


void Scheduler_init(void)
{
	Timer1_init();
	Timer1_Set_Cbk(Scheduler_Update);
}

void Scheduler_Run(void)
{
	Timer1_start();
}

void Scheduler_2ms_Task_Create(void (*Ptr)(void))
{
	Task_Ptr[0]=Ptr;
}
void Scheduler_5ms_Task_Create(void (*Ptr)(void))
{
	Task_Ptr[1]=Ptr;
}

void Scheduler_10ms_Task_Create(void (*Ptr)(void))
{
	Task_Ptr[2]=Ptr;
}

void Scheduler_100ms_Task_Create(void (*Ptr)(void))
{
	Task_Ptr[3]=Ptr;
}

void Scheduler_500ms_Task_Create(void (*Ptr)(void))
{
	Task_Ptr[4]=Ptr;
}

void Scheduler_1000ms_Task_Create(void (*Ptr)(void))
{
	Task_Ptr[5]=Ptr;
}


/* Kernel Core */
static void Scheduler_Update(void)
{
	Tic_Cnt++;

	if(!(Tic_Cnt % 2) )
	{
		Task_Ptr[0]();
	}
	if(!(Tic_Cnt % 5) )
	{
		Task_Ptr[1]();
	}
	if(!(Tic_Cnt % 10) )
	{
		Task_Ptr[2]();
	}
	if(!(Tic_Cnt % 100) )
	{
		Task_Ptr[3]();
	}
	if(!(Tic_Cnt % 500) )
	{
		Task_Ptr[4]();
	}
	if(!(Tic_Cnt % 1000) )
	{
		Task_Ptr[5]();
	}

}

