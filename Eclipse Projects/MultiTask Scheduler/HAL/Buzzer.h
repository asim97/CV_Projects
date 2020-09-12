/*
 * Buzzer.h
 *
 *  Created on: Oct 31, 2018
 *      Author: Asim
 */

#ifndef HAL_BUZZER_H_
#define HAL_BUZZER_H_

#include <avr/io.h>

#define  BUZZER_DIR		DDRD
#define  BUZZER_PORT	PORTD
#define  BUZZER_PIN		PD7

#define  BUZZER_ON 		( BUZZER_PORT |=(1<<BUZZER_PIN)   )
#define  BUZZER_OFF 	( BUZZER_PORT &=~(1<<BUZZER_PIN)   )
#define  BUZZER_TOGGLE 	( BUZZER_PORT ^=(1<<BUZZER_PIN)   )



extern void Buzzer_init(void);



#endif /* HAL_BUZZER_H_ */
