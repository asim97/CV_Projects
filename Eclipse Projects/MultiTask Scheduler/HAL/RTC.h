/*
 * RTC.h
 *
 *  Created on: Oct 31, 2018
 *      Author: Asim
 */

#ifndef RTC_H_
#define RTC_H_

#include "../MCAL/TWI.h"
#include <util/delay.h>

typedef struct rtc
{
	unsigned char PM_AM:1;
	unsigned char sec;
	unsigned char min;
	unsigned char hour;
	unsigned char day;
	unsigned char date;
	unsigned char month;
	unsigned char year;
	unsigned char control;
}RTC;

#define PM (1)
#define AM (0)

#define RTC_Address (0b01101000)


void RTC_init(void);

void RTC_set_parameters(RTC * RTC_Settings);

RTC  RTC_get_parameters(void);


#endif /* RTC_H_ */
