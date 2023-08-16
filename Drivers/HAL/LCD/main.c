/*
 * main.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Marawan Ahmed
 */


#include <avr/io.h>
#include <util/delay.h>
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO.h"
#include "HAL/LCD/LCD.h"


int main(){
	LCD_voidInit ();


//	LCD_voidSendChar ('M');
//	LCD_voidSendChar ('A');
//	LCD_voidSendChar ('R');
//	LCD_voidSendChar ('A');
//	LCD_voidSendChar ('W');
//	LCD_voidSendChar ('A');
//	LCD_voidSendChar ('N');
//
//	LCD_voidSendChar (' ');
//
//	LCD_voidSendChar ('A');
//	LCD_voidSendChar ('h');
//	LCD_voidSendChar ('m');
//	LCD_voidSendChar ('e');
//	LCD_voidSendChar ('d');
	LCD_voidSendString ("Marawan Ahmed");
	LCD_voidSetLocation (LCD_LINE_2, 0);
	LCD_voidSendNumber (2024+2019);

	while(1){
		LCD_voidSetLocation (LCD_LINE_1, 0);
		LCD_voidSendChar ('m');
		_delay_ms(500);
		LCD_voidSetLocation (LCD_LINE_1, 0);
		LCD_voidSendChar ('M');
		_delay_ms(500);
	}
}
