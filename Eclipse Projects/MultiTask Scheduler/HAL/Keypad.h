/*
 * Keypad.h
 *
 *  Created on: Oct 31, 2018
 *      Author: Asim
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../MCAL/DIO.h"
#include "../Service_Layer/PLATFORM_TYPES.h"
#include <avr/io.h>
#include <util/delay.h>

/*Wiring diagram*/

/* * * *c1  c2 c3
 * row1  1  2  3
 * row2  4  5  6
 * row3  7  8  9
 */

#define KEYPAD_PORT_OUT_R PORTA
#define KEYPAD_PORT_IN_R  PINA
#define KEYPAD_PORT_DIR_R DDRA

#define KEYPAD_PORT_OUT_C PORTC
#define KEYPAD_PORT_IN_C  PINC
#define KEYPAD_PORT_DIR_C DDRC

#define FIRST_ROW  (2)
#define SECOND_ROW (1)
#define THIRD_ROW  (0)

#define FIRST_COL  (5)
#define SECOND_COL (6)
#define THIRD_COL  (7)

void  Keypad_init(void);
uint8 Keypad_get_pressed_key(void);


#endif /* KEYPAD_H_ */
