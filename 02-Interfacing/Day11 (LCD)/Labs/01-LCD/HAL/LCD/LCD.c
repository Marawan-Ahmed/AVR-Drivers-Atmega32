#include <avr/io.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/DIO/DIO.h"
#include "LCD.h"
#include <util/delay.h>

void LCD_voidInit (void){
	DIO_voidSetPortDirection (LCD_DATA_PORT, DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection (LCD_CONTROL_PORT, LCD_CONTROL_RS, DIO_OUTPUT);
	DIO_voidSetPinDirection (LCD_CONTROL_PORT, LCD_CONTROL_RW, DIO_OUTPUT);
	DIO_voidSetPinDirection (LCD_CONTROL_PORT, LCD_CONTROL_E, DIO_OUTPUT);

	_delay_ms(35);

	LCD_voidSendCommand (LCD_CONTROL_FUNCTION_SET);
	_delay_us(50);

	LCD_voidSendCommand (LCD_CONTROL_DISPLAY_ONOFF);
	_delay_us(50);

	LCD_voidSendCommand (LCD_CONTROL_CLEAR);
	_delay_ms(2);
}

void LCD_voidSendCommand (u8 Copy_u8Command){
	DIO_voidSetPinValue (LCD_CONTROL_PORT, LCD_CONTROL_RS, DIO_LOW);
	DIO_voidSetPinValue (LCD_CONTROL_PORT, LCD_CONTROL_RW, DIO_LOW);

	DIO_voidSetPortValue (LCD_DATA_PORT, Copy_u8Command);

	DIO_voidSetPinValue (LCD_CONTROL_PORT, LCD_CONTROL_E, DIO_HIGH);

	_delay_us(1);

	DIO_voidSetPinValue (LCD_CONTROL_PORT, LCD_CONTROL_E, DIO_LOW);

}

void LCD_voidSendChar (u8 Copy_u8Char){
	DIO_voidSetPinValue (LCD_CONTROL_PORT, LCD_CONTROL_RS, DIO_HIGH);
	DIO_voidSetPinValue (LCD_CONTROL_PORT, LCD_CONTROL_RW, DIO_LOW);

	DIO_voidSetPortValue (LCD_DATA_PORT, Copy_u8Char);

	DIO_voidSetPinValue (LCD_CONTROL_PORT, LCD_CONTROL_E, DIO_HIGH);

	_delay_us(1);

	DIO_voidSetPinValue (LCD_CONTROL_PORT, LCD_CONTROL_E, DIO_LOW);
}

void LCD_voidSendString (u8 *Copy_u8String){
	while(*Copy_u8String != '\0'){
		LCD_voidSendChar (*Copy_u8String);
		Copy_u8String ++;
	}

}

void LCD_voidSendNumber (u32 Copy_u8Num){
	u8 str[10];
    u8 i, rem, len = 0;

    u32 n = Copy_u8Num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }

    for (i = 0; i < len; i++)
    {
        rem = Copy_u8Num % 10;
        Copy_u8Num = Copy_u8Num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';

    LCD_voidSendString (str);
}

void LCD_voidSetLocation (u8 Copy_u8LineNum, u8 Copy_u8CharNum){
	switch(Copy_u8LineNum){
		case LCD_LINE_1: LCD_voidSendCommand(0x80 + Copy_u8CharNum); break;

		case LCD_LINE_2: LCD_voidSendCommand(0xc0 + Copy_u8CharNum); break;

		default: return;
	}
}

void LCD_voidDrawSpecialChar (u8 Copy_u8CharIndex, u8 *Copy_u8SpecialChar){
	u8 i;

	if(Copy_u8CharIndex < 8){
		LCD_voidSendCommand (0x40 + (Copy_u8CharIndex*8));
		for(i=0;i<8;i++) LCD_voidSendChar(*(Copy_u8SpecialChar+i));
	}
}

void LCD_voidSendSpecialChar (u8 Copy_u8CharIndex){
	LCD_voidSendChar (Copy_u8CharIndex);
}

