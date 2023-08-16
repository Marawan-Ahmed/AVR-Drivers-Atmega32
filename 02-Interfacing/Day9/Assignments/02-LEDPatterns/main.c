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

#define LEDS_PORT DIO_PORTB
#define SWITCHS_PORT DIO_PORTD
#define SWITCH_1 DIO_PIN0
#define SWITCH_2 DIO_PIN1
#define SWITCH_3 DIO_PIN2

#define LEDS_MODE_FLASH 0
#define LEDS_MODE_SHIFT_LEFT 1
#define LEDS_MODE_SHIFT_RIGHT 2
#define LEDS_MODE_COVERGE 3
#define LEDS_MODE_DIVERGE 4
#define LEDS_MODE_PING_PONG 5
#define LEDS_MODE_SNAKE 6
#define LEDS_MODE_COVERGE_DIVERGE 7

#define LEDS_MODE_PING_PONG_RIGHT 0
#define LEDS_MODE_PING_PONG_LEFT 1

#define LEDS_MODE_COVERGE_DIVERGE_COVERGE 0
#define LEDS_MODE_COVERGE_DIVERGE_DIVERGE 1

u8 pattern = 0x00;
u8 mode = LEDS_MODE_FLASH;
u8 ping_direction = LEDS_MODE_PING_PONG_RIGHT;
u8 condiv_direction = LEDS_MODE_COVERGE_DIVERGE_COVERGE;

u8 read = 0x00;

int main(){
	DIO_voidSetPortDirection (LEDS_PORT, DIO_PORT_OUTPUT);

	DIO_voidSetPinDirection (SWITCHS_PORT, SWITCH_1, DIO_PIN_INPUT_PULLUP);
	DIO_voidSetPinDirection (SWITCHS_PORT, SWITCH_2, DIO_PIN_INPUT_PULLUP);
	DIO_voidSetPinDirection (SWITCHS_PORT, SWITCH_3, DIO_PIN_INPUT_PULLUP);

	DIO_voidSetPortDirection (LEDS_PORT, DIO_PORT_OUTPUT);
	DIO_voidSetPortDirection (DIO_PORTC, DIO_PORT_OUTPUT);

	while(1){
		read = (DIO_u8GetPinValue(SWITCHS_PORT, SWITCH_3)<<2) | (DIO_u8GetPinValue (SWITCHS_PORT, SWITCH_2)<<1) | (DIO_u8GetPinValue (SWITCHS_PORT, SWITCH_1));
		read = (~read) &0x07;
		DIO_voidSetPortValue(DIO_PORTC, read);
		switch(read){
			case LEDS_MODE_FLASH: flashing(); break;
			case LEDS_MODE_SHIFT_LEFT: shift_left(); break;
			case LEDS_MODE_SHIFT_RIGHT: shift_right(); break;
			case LEDS_MODE_COVERGE: coverge(); break;
			case LEDS_MODE_DIVERGE: diverge(); break;
			case LEDS_MODE_PING_PONG: ping_pong(); break;
			case LEDS_MODE_SNAKE: snake(); break;
			case LEDS_MODE_COVERGE_DIVERGE: coverge_diverge(); break;
			default: flashing();  shift_right(); shift_right(); flashing(); shift_left(); shift_left();
		}
	}
}


void flashing (void){
	if (mode != LEDS_MODE_FLASH) pattern = 0x00;
	mode = LEDS_MODE_FLASH;

	pattern = ~pattern;
	DIO_voidSetPortValue (LEDS_PORT, pattern);

	_delay_ms(500);
}

void shift_left (void){
	if (mode != LEDS_MODE_SHIFT_LEFT) pattern = 0x01;
	mode = LEDS_MODE_SHIFT_LEFT;

	if (pattern == 0x80){
		pattern = 0x01;
	}
	else{
		pattern = pattern<<1;
	}

	DIO_voidSetPortValue (LEDS_PORT, pattern);

	_delay_ms(250);
}

void shift_right (void){
	if (mode != LEDS_MODE_SHIFT_RIGHT) pattern = 0x80;
	mode = LEDS_MODE_SHIFT_RIGHT;

	if (pattern == 0x01){
		pattern = 0x80;
	}
	else{
		pattern = pattern>>1;
	}

	DIO_voidSetPortValue (LEDS_PORT, pattern);

	_delay_ms(250);
}

void coverge (void){
	if (mode != LEDS_MODE_COVERGE) pattern = 0x81;
	mode = LEDS_MODE_COVERGE;

	if (pattern == 0x18){
		pattern = 0x81;
	}
	else{
		u8 u_temp, l_temp;
		u_temp = (pattern & 0xf0) >> 1;
		l_temp = (pattern & 0x0f) << 1;

		pattern = u_temp + l_temp;
	}

	DIO_voidSetPortValue (LEDS_PORT, pattern);

	_delay_ms(300);
}

void diverge (void){
	if (mode != LEDS_MODE_DIVERGE) pattern = 0x18;
	mode = LEDS_MODE_DIVERGE;

	if (pattern == 0x81){
		pattern = 0x18;
	}
	else{
		u8 u_temp, l_temp;
		u_temp = (pattern & 0xf0) << 1;
		l_temp = (pattern & 0x0f) >> 1;

		pattern = u_temp + l_temp;
	}

	DIO_voidSetPortValue (LEDS_PORT, pattern);

	_delay_ms(300);
}

void ping_pong (void){
	if (mode != LEDS_MODE_PING_PONG) {pattern = 0x80; ping_direction = LEDS_MODE_PING_PONG_RIGHT;}
	mode = LEDS_MODE_PING_PONG;

	if (ping_direction == LEDS_MODE_PING_PONG_RIGHT){
		pattern = pattern>>1;
	}
	else if (ping_direction == LEDS_MODE_PING_PONG_LEFT){
		pattern = pattern<<1;
	}

	if (pattern == 0x01){
		ping_direction = LEDS_MODE_PING_PONG_LEFT;
	}
	else if (pattern == 0x80){
		ping_direction = LEDS_MODE_PING_PONG_RIGHT;
	}

	DIO_voidSetPortValue (LEDS_PORT, pattern);

	_delay_ms(250);
}

void snake (void){
	if (mode != LEDS_MODE_SNAKE) pattern = 0x00;
	mode = LEDS_MODE_SNAKE;

	if (pattern == 0xff){
		pattern = 0x00;
	}
	else{
		pattern = pattern<<1 | 0x01;
	}

	DIO_voidSetPortValue (LEDS_PORT, pattern);

	_delay_ms(300);
}

void coverge_diverge (void){
	if (mode != LEDS_MODE_COVERGE_DIVERGE){ pattern = 0x81; condiv_direction = LEDS_MODE_COVERGE_DIVERGE_COVERGE;}
	mode = LEDS_MODE_COVERGE_DIVERGE;

	if (condiv_direction == LEDS_MODE_COVERGE_DIVERGE_COVERGE){
		u8 u_temp, l_temp;
		u_temp = (pattern & 0xf0) >> 1;
		l_temp = (pattern & 0x0f) << 1;

		pattern = u_temp + l_temp;
	}
	else if (condiv_direction == LEDS_MODE_COVERGE_DIVERGE_DIVERGE){
		u8 u_temp, l_temp;
		u_temp = (pattern & 0xf0) << 1;
		l_temp = (pattern & 0x0f) >> 1;

		pattern = u_temp + l_temp;
	}

	if (pattern == 0x81){
		condiv_direction = LEDS_MODE_COVERGE_DIVERGE_COVERGE;
	}
	else if (pattern == 0x18){
		condiv_direction = LEDS_MODE_COVERGE_DIVERGE_DIVERGE;
	}

	DIO_voidSetPortValue (LEDS_PORT, pattern);

	_delay_ms(300);
}
