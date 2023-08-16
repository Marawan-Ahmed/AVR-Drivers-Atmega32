/*
 * main.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Marawan Ahmed
 */

#include <avr/io.h>


int main(){
	DDRA |= (1<<PA0);
	PORTA |= (1<<PA0);


	while(1);
}
