/*
 * main.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Marawan Ahmed
 */


#include <avr/io.h>
#include <util/delay.h>
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO.h"
#include "HAL/SSD/SSD.h"

#define GREEN_LED_TIME 10
#define YELLOW_LED_TIME 3
#define RED_LED_TIME 10

#define GREEN_LED 0
#define YELLOW_LED 1
#define RED_LED 2


int main(){
	SSD_voidInitDoubleDigit(DIO_PORTA, DIO_PORTB);
	DIO_voidSetPinDirection (DIO_PORTC, GREEN_LED, DIO_OUTPUT);
	DIO_voidSetPinDirection (DIO_PORTC, YELLOW_LED, DIO_OUTPUT);
	DIO_voidSetPinDirection (DIO_PORTC, RED_LED, DIO_OUTPUT);

	u8 counter = 0;

	while(1){
		DIO_voidSetPinValue (DIO_PORTC, GREEN_LED, DIO_HIGH);
		DIO_voidSetPinValue (DIO_PORTC, YELLOW_LED, DIO_LOW);
		DIO_voidSetPinValue (DIO_PORTC, RED_LED, DIO_LOW);

		for (counter = GREEN_LED_TIME; counter>0; counter--){
			SSD_voidWriteDoubleDigit(DIO_PORTA, DIO_PORTB, counter);
			_delay_ms(1000);
		}

		DIO_voidSetPinValue (DIO_PORTC, GREEN_LED, DIO_LOW);
		DIO_voidSetPinValue (DIO_PORTC, YELLOW_LED, DIO_HIGH);
		DIO_voidSetPinValue (DIO_PORTC, RED_LED, DIO_LOW);

		for (counter = YELLOW_LED_TIME; counter>0; counter--){
			SSD_voidWriteDoubleDigit(DIO_PORTA, DIO_PORTB, counter);
			_delay_ms(1000);
		}

		DIO_voidSetPinValue (DIO_PORTC, GREEN_LED, DIO_LOW);
		DIO_voidSetPinValue (DIO_PORTC, YELLOW_LED, DIO_LOW);
		DIO_voidSetPinValue (DIO_PORTC, RED_LED, DIO_HIGH);

		for (counter = RED_LED_TIME; counter>0; counter--){
			SSD_voidWriteDoubleDigit(DIO_PORTA, DIO_PORTB, counter);
			_delay_ms(1000);
		}
	}
}
