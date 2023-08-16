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
	DDRA |= 0x0f;
	PORTA = 0x55;

	while(1){
		PORTA = ~PORTA;
	    _delay_ms(1000);
	}
}
