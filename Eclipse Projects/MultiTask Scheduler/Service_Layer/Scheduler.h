/*
 * Scheduler.h
 *
 *  Created on: Oct 31, 2018
 *      Author: Asim
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_


extern void Scheduler_init(void);
extern void Scheduler_Run(void);
extern void Scheduler_2ms_Task_Create(void (*Ptr)(void));
extern void Scheduler_5ms_Task_Create(void (*Ptr)(void));
extern void Scheduler_10ms_Task_Create(void (*Ptr)(void));
extern void Scheduler_100ms_Task_Create(void (*Ptr)(void));
extern void Scheduler_500ms_Task_Create(void (*Ptr)(void));
extern void Scheduler_1000ms_Task_Create(void (*Ptr)(void));


#endif /* SCHEDULER_H_ */
