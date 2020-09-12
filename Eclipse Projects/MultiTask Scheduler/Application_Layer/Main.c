/*
 * Main.c
 *
 *  Created on: Oct 31, 2018
 *      Author: Asim
 */

#include "../Service_Layer/Scheduler.h"
#include "../HAL/Keypad.h"
#include "../HAL/LCD.h"
#include "../HAL/Buzzer.h"
#include "../HAL/ULTRASONIC.h"
#include "../MCAL/UART.h"

/* Global Variables */
long Distance=0;
volatile char Data;
void Task_2ms(void)
	{


	}
void Task_5ms(void)
	{


	}
void Task_10ms(void)
	{

		Distance = UltraSonic_read();
		if(Distance < 15)
			{
				BUZZER_ON;
			}
		else
			{
				BUZZER_OFF;
			}

	}
void Task_100ms(void)
	{
		char Key =0;

		Key = Keypad_get_pressed_key();

		if(Key != 0)
			{
				LCD_GoTO_Row_Colunmn(0,0);
				LCD_Send_character(Key);
			}
		else
			{
				/* Do Nothing */
			}

	}
void Task_500ms(void)
	{


	}
void Task_1000ms(void)
	{
		char arr[10];

	 UART_send_string("The Distance is :");
	 itoa(Distance,arr,10);
	 UART_send_string(arr);
	 UART_send_string(" CM\n\r");
	}

/**/

int main(void)
	{

		/* Init Per. */
		LCD_Init();
		LCD_Clear_Display();

		Keypad_init();

		UltraSonic_init();

		Uart_init(9600ul);

		Scheduler_init();
		Scheduler_2ms_Task_Create(Task_2ms);
		Scheduler_5ms_Task_Create(Task_5ms);
		Scheduler_10ms_Task_Create(Task_10ms);
		Scheduler_100ms_Task_Create(Task_100ms);
		Scheduler_500ms_Task_Create(Task_500ms);
		Scheduler_1000ms_Task_Create(Task_1000ms);
		Scheduler_Run();

		while(1)
			{
				/* Do Nothing */

			}

		return 0;
	}
