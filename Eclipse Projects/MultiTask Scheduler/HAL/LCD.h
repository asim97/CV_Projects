/*
 * LCD.h
 *
 *  Created on: Oct 31, 2018
 *      Author: Asim
 */

#ifndef LCD_H_
#define LCD_H_

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

#define LCD_BIT_MODE 4
#define RS PA3
#define E  PD6

#define LCD_CTRL_PORT_RS PORTA
#define LCD_CTRL_PORT_DIR_RS DDRA
#define LCD_CTRL_PORT_E PORTD
#define LCD_CTRL_PORT_DIR_E DDRD
#define LCD_DATA_PORT PORTB
#define LCD_DATA_PORT_DIR DDRB

#define _8BIT_2LINE (0x38)
#define _4BIT_2LINE (0x28)
#define DISPLAY_ON_CURSOR_ON (0x0E)
#define DISPLAY_ON_CURSOR_OFF (0x0C)
#define CLEAR_DISPLAY (0x01)
#define SET_CURSOR_LOCATION (0x80)
#define ReturnHome (0x02)

void LCD_Init(void);
void LCD_Clear_Display(void);
void LCD_Send_Command(unsigned char command);
void LCD_Send_character(char character);
void LCD_Send_String(char *string);
void LCD_GoTO_Row_Colunmn(char Row,char Column);
void LCD_Send_String_Row_Column(char Row,char Column,char *String);
void LCD_IntToString(int integer,char *String);
void LCD_Set_Custom_Char(unsigned char Location ,unsigned char * Pattern);



#endif /* LCD_H_ */
