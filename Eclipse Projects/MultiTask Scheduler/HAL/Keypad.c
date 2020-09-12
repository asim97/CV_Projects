/*
 * Keypad.c
 *
 *  Created on: Oct 31, 2018
 *      Author: Asim
 */

#include "Keypad.h"

/* * * *c1  c2 c3
 * row1  1  2  3
 * row2  4  5  6
 * row3  7  8  9
 */

/*Keypad initialization*/
void Keypad_init(void)
{
	/*configure Keypad columns as outputs others as inputs*/
	KEYPAD_PORT_DIR_R&=0xF8;
	KEYPAD_PORT_DIR_C|=0xE0;

	/*Pull up resistors for all rows*/
	SET_BIT(KEYPAD_PORT_OUT_R,FIRST_ROW);
	SET_BIT(KEYPAD_PORT_OUT_R,SECOND_ROW);
	SET_BIT(KEYPAD_PORT_OUT_R,THIRD_ROW);

	SET_BIT(KEYPAD_PORT_OUT_C,FIRST_COL);
	SET_BIT(KEYPAD_PORT_OUT_C,SECOND_COL);
	SET_BIT(KEYPAD_PORT_OUT_C,THIRD_COL);

}
/*Scanning any pressed key */
uint8 Keypad_get_pressed_key(void)
{
	uint8 KeyPressed=0;

	/*First column */

	_delay_ms(5);

	CLEAR_BIT(KEYPAD_PORT_OUT_C,FIRST_COL);
	SET_BIT(KEYPAD_PORT_OUT_C,SECOND_COL);
	SET_BIT(KEYPAD_PORT_OUT_C,THIRD_COL);

	_delay_ms(5); //Configuration Stability

	if(BIT_CLEARED(KEYPAD_PORT_IN_R,FIRST_ROW)){KeyPressed='1';}
	else if(BIT_CLEARED(KEYPAD_PORT_IN_R,SECOND_ROW)){KeyPressed='4';}
	else if(BIT_CLEARED(KEYPAD_PORT_IN_R,THIRD_ROW)){KeyPressed='7';}

	/*Second column */
	SET_BIT(KEYPAD_PORT_OUT_C,FIRST_COL);
	CLEAR_BIT(KEYPAD_PORT_OUT_C,SECOND_COL);
	SET_BIT(KEYPAD_PORT_OUT_C,THIRD_COL);

	_delay_ms(5);

	if(BIT_CLEARED(KEYPAD_PORT_IN_R,FIRST_ROW)){KeyPressed='2';}
	else if(BIT_CLEARED(KEYPAD_PORT_IN_R,SECOND_ROW)){KeyPressed='5';}
	else if(BIT_CLEARED(KEYPAD_PORT_IN_R,THIRD_ROW)){KeyPressed='8';}

	/*Third column */
	SET_BIT(KEYPAD_PORT_OUT_C,FIRST_COL);
	SET_BIT(KEYPAD_PORT_OUT_C,SECOND_COL);
	CLEAR_BIT(KEYPAD_PORT_OUT_C,THIRD_COL);

	_delay_ms(5);

	if(BIT_CLEARED(KEYPAD_PORT_IN_R,FIRST_ROW)){KeyPressed='3';}
	else if(BIT_CLEARED(KEYPAD_PORT_IN_R,SECOND_ROW)){KeyPressed='6';}
	else if(BIT_CLEARED(KEYPAD_PORT_IN_R,THIRD_ROW)){KeyPressed='9';}

	return KeyPressed;
}
