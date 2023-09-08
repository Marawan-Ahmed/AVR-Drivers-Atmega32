/*
 * main.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Marawan Ahmed
 */

#include <avr/io.h>
#include <util/delay.h>
#include "MCAL/DIO/DIO.h"
#include "MCAL/ADC/ADC.h"
//#include "HAL/LCD/LCD.h"

int main(){
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN4, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN7, DIO_PIN_OUTPUT);

	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);

	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN1, DIO_PIN_INPUT);
	ADC_voidInit(ADC_DIV_64);

	u16 Local_u16DigitalValue, Local_u16AnaloglValue, Local_u16TempValue;
//	LCD_voidInit ();


	while(1){
		Local_u16DigitalValue = ADC_u16GetDigitalValue(ADC_CHANNEL_1);
		Local_u16AnaloglValue = (Local_u16DigitalValue * 5000UL)/1024;
		Local_u16TempValue = Local_u16AnaloglValue/10;

		if(Local_u16TempValue <= 20){
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_HIGH);
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN5, DIO_LOW);
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN6, DIO_LOW);

			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN7, DIO_LOW);
		}

		else if(Local_u16TempValue <= 40){
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_LOW);
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN5, DIO_HIGH);
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN6, DIO_LOW);

			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN7, DIO_LOW);

		}

		else if(Local_u16TempValue > 40){
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_LOW);
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN5, DIO_LOW);
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN6, DIO_HIGH);

			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN7, DIO_HIGH);

		}



//		LCD_voidSendCommand (LCD_CONTROL_CLEAR);
//		_delay_ms(2);

//		LCD_voidSetLocation (LCD_LINE_1, 0);
//		LCD_voidSendString ("The Voltage is ");
//		LCD_voidSetLocation (LCD_LINE_2, 0);
//		LCD_voidSendNumber(Local_u16AnaloglValue);
//		LCD_voidSendString (" mV");
//		_delay_ms(1000);

	}
}

