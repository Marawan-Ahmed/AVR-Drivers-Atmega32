/*
 * UART.h
 *
 *  Created on: Aug 27, 2023
 *      Author: Marawan Ahmed
 */

#ifndef UART_H
#define UART_H


void UART_voidInit (void);
void UART_voidSendData(u8 Copy_u8);
u8	 UART_u8ReceiveData (void);
#endif /* MCAL_UART_UART_H_ */
