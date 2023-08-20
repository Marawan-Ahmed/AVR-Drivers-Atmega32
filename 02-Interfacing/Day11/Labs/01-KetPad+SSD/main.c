/*
 * main.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Marawan Ahmed
 */

#include <avr/io.h>
#include <util/delay.h>
#include "HAL/KEYPAD/KEYPAD.h"
#include "HAL/SSD/SSD.h"

int main(){
	SSD_voidInitSingleDigit (DIO_PORTA);
	KPD_voidInit();

	while(1){
//		LCD_voidSetLocation (LCD_LINE_1, 0);

		u8 Local_u8PressedKey = KPD_u8GetPressedKey();
		if (Local_u8PressedKey == 'c'){
			DIO_voidSetPortValue(DIO_PORTA, 0xff);
		}
		else if (Local_u8PressedKey != KPD_NO_KEY){
			SSD_voidWriteSingleDigit(DIO_PORTA, Local_u8PressedKey - '0');
		}

//		_delay_ms(500);
	}
}
