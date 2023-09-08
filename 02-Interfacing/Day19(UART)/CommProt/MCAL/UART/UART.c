/*
 * UART.c
 *
 *  Created on: Aug 27, 2023
 *      Author: Marawan Ahmed
 */


#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include <avr/io.h>
#include "UART.h"



void UART_voidInit (void){
	u16 Local_u16BaudRate = 51; //9600
	u8 Local_u8UCSRCValue = 0b10000000;

	/*set baudrate*/
	UBRRH = (unsigned char) (Local_u16BaudRate>>8);
	UBRRL = (unsigned char)  Local_u16BaudRate;
	/*select normal speed*/
	UCSRA = CLR_BIT(UCSRA, U2X);

	/*disable multiprocessor mode*/
	UCSRA = CLR_BIT(UCSRA, MPCM);

	/*enable rexeive and transmit*/
	UCSRB = SET_BIT(UCSRB, RXEN);
	UCSRB = SET_BIT(UCSRB, TXEN);
	/*select 8bit data*/
	UCSRB = CLR_BIT(UCSRB, UCSZ2);
	Local_u8UCSRCValue = SET_BIT(Local_u8UCSRCValue, UCSZ1);
	Local_u8UCSRCValue = SET_BIT(Local_u8UCSRCValue, UCSZ0);

	/*Select asynch mode*/
	Local_u8UCSRCValue = CLR_BIT(Local_u8UCSRCValue, UMSEL);

	/*parity disable*/
	Local_u8UCSRCValue = CLR_BIT(Local_u8UCSRCValue, UPM0);
	Local_u8UCSRCValue = CLR_BIT(Local_u8UCSRCValue, UPM1);

	/*set 2 stop bits*/
	Local_u8UCSRCValue = SET_BIT(Local_u8UCSRCValue, USBS);

	Local_u8UCSRCValue = SET_BIT(Local_u8UCSRCValue, UCPOL);

	/*assign local u8ucsrc*/
	UCSRC = Local_u8UCSRCValue;
}

void UART_voidSendData(u8 Copy_u8){
	/* Wait for empty transmit buffer */
	while (GET_BIT(UCSRA , UDRE) == 0 );
	/* Put data into buffer, sends the data */
	UDR = Copy_u8;
}

u8	 UART_u8ReceiveData (void){
	/* Wait for data to be received */
	while (GET_BIT(UCSRA , RXC) == 0 )	;
	/* Get and return received data from buffer */
	return UDR;
}
