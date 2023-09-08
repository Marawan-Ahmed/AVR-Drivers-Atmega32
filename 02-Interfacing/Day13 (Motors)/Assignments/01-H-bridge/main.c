/*
 * main.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Marawan Ahmed
 */

#include <avr/io.h>
#include <util/delay.h>
#include "MCAL/DIO/DIO.h"
#include "HAL/LCD/LCD.h"


int main(){

	DIO_voidSetPinDirection(DIO_PORTC, DIO_PIN0, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTC, DIO_PIN1, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTC, DIO_PIN2, DIO_PIN_INPUT_PULLUP);
	DIO_voidSetPinDirection(DIO_PORTC, DIO_PIN3, DIO_PIN_INPUT_PULLUP);

	DIO_voidSetPinValue(DIO_PORTC, DIO_PIN0, DIO_LOW);
	DIO_voidSetPinValue(DIO_PORTC, DIO_PIN1, DIO_LOW);

	LCD_voidInit ();

	while(1){

		if (!(DIO_u8GetPinValue(DIO_PORTC, DIO_PIN2))){
			DIO_voidSetPinValue(DIO_PORTC, DIO_PIN0, DIO_HIGH);
			DIO_voidSetPinValue(DIO_PORTC, DIO_PIN1, DIO_LOW);

			LCD_voidSendCommand (LCD_CONTROL_CLEAR);
			_delay_ms(2);

			LCD_voidSetLocation (LCD_LINE_1, 0);
			LCD_voidSendString ("Clock Wise");
		}

		if (!(DIO_u8GetPinValue(DIO_PORTC, DIO_PIN2))){
			DIO_voidSetPinValue(DIO_PORTC, DIO_PIN0, DIO_LOW);
			DIO_voidSetPinValue(DIO_PORTC, DIO_PIN1, DIO_HIGH);
			LCD_voidSendCommand (LCD_CONTROL_CLEAR);

			_delay_ms(2);

			LCD_voidSetLocation (LCD_LINE_1, 0);
			LCD_voidSendString ("Anti Clock Wise");
		}

		_delay_ms(500);

	}
}
