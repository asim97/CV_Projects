/*
 * ULTRASONIC.h
 *
 *  Created on: Oct 31, 2018
 *      Author: Asim
 */

#ifndef HAL_ULTRASONIC_H_
#define HAL_ULTRASONIC_H_

#include "../Service_Layer/PLATFORM_TYPES.h"

#define DISTANCE (CM)


#define ULTRASONIC_TRIG_DDR  (DDRD)
#define ULTRASONIC_TRIG_PIN	 (PD2)
#define ULTRASONIC_TRIG_PORT  (PORTD)

#define ULTRASONIC_ECHO_DDR  (DDRD)
#define ULTRASONIC_ECHO_PIN	 (PD3)
#define ULTRASONIC_ECHO_PORT  (PIND)

extern void UltraSonic_init(void);
extern uint16 UltraSonic_read(void);


#endif /* HAL_ULTRASONIC_H_ */
