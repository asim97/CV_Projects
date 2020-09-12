/*
 * UART.h
 *
 *  Created on: Oct 31, 2018
 *      Author: Asim
 */

#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include "../Service_Layer/PLATFORM_TYPES.h"


void Uart_init(long BaudRate);
uint8 UART_send_byte( char byte);
void UART_send_string( char *ptr);
char UART_recieve_byte(void);
void UART_recieve_string( char *ptr);


#endif /* UART_H_ */
