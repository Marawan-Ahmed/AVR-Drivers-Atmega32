/*
 * main.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Marawan Ahmed
 */



#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_Types.h"

int main(){
	DDRA = 0xff;

	CLR_BIT(DDRB, PB0);

	while(1){
		if(GET_BIT(PINB, PB0) == 1){
			PORTA = ~PORTA;
		    _delay_ms(1000);
		}
	}
}
