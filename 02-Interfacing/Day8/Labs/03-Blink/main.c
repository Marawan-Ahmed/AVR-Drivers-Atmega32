/*
 * main.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Marawan Ahmed
 */

#include <avr/io.h>
#include <util/delay.h>
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO.h"

int main(){
	DIO_voidSetPinDirection (DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	DIO_voidSetPinValue (DIO_PORTA,DIO_PIN0,DIO_HIGH);

	while(1){
		DIO_voidTogglePinValue(DIO_PORTA,DIO_PIN0);
		_delay_ms(1000);
	}
}
