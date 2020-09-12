/*
 * Buzzer.c
 *
 *  Created on: Oct 31, 2018
 *      Author: Asim
 */

#include "Buzzer.h"

void Buzzer_init(void)
	{
		BUZZER_DIR |=(1<<BUZZER_PIN);
	}

