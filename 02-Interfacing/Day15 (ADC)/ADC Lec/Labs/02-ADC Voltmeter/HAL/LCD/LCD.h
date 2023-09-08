#ifndef LCD_H
#define LCD_H

#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO.h"

#define LCD_DATA_PORT    DIO_PORTC
#define LCD_CONTROL_PORT    DIO_PORTD

#define LCD_CONTROL_RS DIO_PIN7
#define LCD_CONTROL_RW DIO_PIN6
#define LCD_CONTROL_E DIO_PIN5


//function set 0001 dl n f - -    dl->  n->  f->0=5*7 1=5*10
#define LCD_CONTROL_FUNCTION_SET 0b00111000
//display on/off control 00001 d c b    d->display  c->curser  b->surser blink
#define LCD_CONTROL_DISPLAY_ONOFF 0b00001111

#define LCD_CONTROL_CLEAR 0b00000001

#define LCD_LINE_1 1
#define LCD_LINE_2 2

/**********************APIs**********************/
void LCD_voidInit (void);
void LCD_voidSendCommand (u8 Copy_u8Command);
void LCD_voidSendChar (u8 Copy_u8Char);
void LCD_voidSendString (u8 *Copy_u8String);
void LCD_voidSendNumber (u32 Copy_u8Num);
void LCD_voidSetLocation (u8 Copy_u8LineNum, u8 Copy_u8CharNum);
void LCD_voidDrawSpecialChar (u8 Copy_u8CharIndex, u8 *Copy_u8SpecialChar);
void LCD_voidSendSpecialChar (u8 Copy_u8CharIndex);


#endif
