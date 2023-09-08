/*
 * main.c
 *
 *  Created on: Aug 30, 2023
 *      Author: Marawan Ahmed
 */

#include <avr/io.h>
#include "MCAL/DIO/DIO.h"

#include "MCAL/UART/UART.h"

#include "HAL/KEYPAD/KEYPAD.h"
#include "HAL/LCD/LCD.h"

#include <util/delay.h>



//int main(){
//	LCD_voidInit ();
//
//	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN0, DIO_PIN_INPUT);
//	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN1, DIO_PIN_OUTPUT);
//
//	UART_voidInit();
//	while(1){
//		u8 Local_u8ReceivedMessage = UART_u8ReceiveData();
//		if (Local_u8ReceivedMessage == 'c'){
//			LCD_voidSendCommand (LCD_CONTROL_CLEAR);
//			_delay_ms(2);
//		}
//		else if (Local_u8ReceivedMessage != KPD_NO_KEY){
//			LCD_voidSendChar(Local_u8ReceivedMessage);
//		}
//	}
//}




int main(){
	KPD_voidInit();

	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN0, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN1, DIO_PIN_OUTPUT);

	UART_voidInit();
	while(1){
		u8 Local_u8PressedKey = KPD_u8GetPressedKey();
		UART_voidSendData(Local_u8PressedKey);
//		UART_voidSendData('1');
//		_delay_ms(1000);
	}
}

