#ifndef KEYPAD_H
#define KEYPAD_H

#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO.h"

/********************************************Cfg********************************************/

/************Select kpd port************/
#define KPD_PORT DIO_PORTC

/************Row pins (output pins)************/
#define KPD_R1_PIN DIO_PIN0
#define KPD_R2_PIN DIO_PIN1
#define KPD_R3_PIN DIO_PIN2
#define KPD_R4_PIN DIO_PIN3

/************Column pins (INPUT pins)************/
#define KPD_C1_PIN DIO_PIN4
#define KPD_C2_PIN DIO_PIN5
#define KPD_C3_PIN DIO_PIN6
#define KPD_C4_PIN DIO_PIN7

/************Keys Cfg************/
#define KPD_KEYS {{'7', '8', '9', '/'},\
				  {'4', '5', '6', '*'},\
				  {'1', '2', '3', '-'},\
				  {'c', '0', '=', '+'}}



#define KPD_NO_KEY '\0'
/********************************************APIs********************************************/

void KPD_voidInit(void);
u8 KPD_u8GetPressedKey(void);



#endif
