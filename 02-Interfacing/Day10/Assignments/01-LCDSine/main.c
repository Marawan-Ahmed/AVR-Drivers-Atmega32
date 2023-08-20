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

    u8 line = LCD_LINE_1;
    u8 column;



	while(1){

		for(column = 0; column < 16; column++){
			LCD_voidSetLocation (line, column);

			LCD_voidSendString ("Marawan");
			_delay_ms(500);
			LCD_voidSendCommand (LCD_CONTROL_CLEAR);
			_delay_ms(2);

//			if(column == (15)){
				line = TGL_BIT(line,0);
				line = TGL_BIT(line,1);
				//0b0001
				//0b0010
//			}
		}

	}
}
