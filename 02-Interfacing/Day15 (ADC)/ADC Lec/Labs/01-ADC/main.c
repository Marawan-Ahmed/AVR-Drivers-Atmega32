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

int main(){
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN4, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);

	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_INPUT);
	ADC_voidInit(ADC_DIV_64);

	u16 Local_u16DigitalValue, Local_u16AnaloglValue;


	while(1){
		Local_u16DigitalValue = ADC_u16GetDigitalValue(ADC_CHANNEL_0);
		Local_u16AnaloglValue = (Local_u16DigitalValue * 5000UL)/1024;

		if((Local_u16AnaloglValue >= 0) && (Local_u16AnaloglValue <= 1500)){
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_HIGH);
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN5, DIO_LOW);
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN6, DIO_LOW);
		}
		else if(Local_u16AnaloglValue > 1500 && Local_u16AnaloglValue <= 3000){
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_LOW);
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN5, DIO_HIGH);
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN6, DIO_LOW);
		}
		else if(Local_u16AnaloglValue > 3000 && Local_u16AnaloglValue <= 5000){
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_LOW);
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN5, DIO_LOW);
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN6, DIO_HIGH);
		}

	}
}

