/*
 * TWI.h
 *
 *  Created on: Oct 31, 2018
 *      Author: Asim
 */

#ifndef TWI_H_
#define TWI_H_

#define TWI_SPEED 100

void TWI_init(void);

void TWI_address(unsigned char address);

void TWI_start(void);

void TWI_send_DeviceAddress_Write	(unsigned char address);
void TWI_send_DeviceAddress_Read 	(unsigned char address);

void TWI_send_data(unsigned char Data);

unsigned char  TWI_recieve_data_ACK(void);
unsigned char  TWI_recieve_data_NACK(void);

void TWI_stop(void);



#endif /* TWI_H_ */
