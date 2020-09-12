/*
 * UART.c
 *
 *  Created on: Oct 31, 2018
 *      Author: Asim
 */
#include "UART.h"
#include <avr/interrupt.h>

extern volatile char Data;

void Uart_init(long BaudRate)
{
	UCSRB=(1<<RXEN)|(1<<TXEN)|(1<<RXCIE);
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UBRRL=(unsigned char)(((F_CPU)/(16*BaudRate))-1);
	SREG|=(1<<7);

}

uint8 UART_send_byte( char byte)
{
	if((UCSRA &(1<<UDRE)))  // while shift register flag != 1 (not empty))
	{
		UDR=byte;
		return OK;
	}
	else
	{
		return NOK;
	}
}

void UART_send_string( char *ptr)
{
	int i=0;

	while(ptr[i] != '\0')
	{
		if( UART_send_byte(ptr[i]) )
		{
			i++;
		}
		else
		{
			/* Don't increment */
		}

	}
}

char  UART_recieve_byte(void)
{
	static volatile char Data=0;

	if((UCSRA & (1<<RXC))==1)
	{
		Data = UDR;
		return Data;
	}
	else
	{
		return Data;
	}
}
void  UART_recieve_string(char * ptr)
{
	int i=0;
	ptr[i]=UART_recieve_byte();
	while(ptr[i] !='#')
	{
		i++;
		ptr[i]=UART_recieve_byte();

	}
	ptr[i]='\0';
}

ISR(USART_RXC_vect)
	{
		Data = UDR;
	}
