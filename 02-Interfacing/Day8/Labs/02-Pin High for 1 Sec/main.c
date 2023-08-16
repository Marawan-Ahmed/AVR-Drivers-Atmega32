/*
 * main.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Marawan Ahmed
 */

#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"

int main(){
//	DDRA |= (1<<PA0);
	DDRA = SET_BIT(DDRA,PA0);
//	PORTA |= (1<<PA0);
	PORTA = SET_BIT(PORTA,PA0);

    _delay_ms(1000);

//	PORTA &= (1<<PA0);
	PORTA = CLR_BIT(PORTA,PA0);


	while(1);
}
