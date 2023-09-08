#ifndef DIO_H
#define DIO_H

#include "../../LIB/STD_Types.h"

#define DIO_INPUT 0
#define DIO_OUTPUT 1

#define DIO_PORT_INPUT 0x00
#define DIO_PORT_OUTPUT 0xFF

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_HIGH 1
#define DIO_LOW 0

/**********************APIs**********************/
void DIO_voidSetPinDirection (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);
void DIO_voidSetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
void DIO_voidTogglePinValue (u8 Copy_u8Port, u8 Copy_u8Pin);
u8 DIO_u8GetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin);

void DIO_voidSetPortDirection (u8 Copy_u8Port, u8 Copy_u8DirValue);
void DIO_voidSetPortValue (u8 Copy_u8Port, u8 Copy_u8Value);
#endif
