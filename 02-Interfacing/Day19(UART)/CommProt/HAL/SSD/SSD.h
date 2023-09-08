#ifndef SSD_H
#define SSD_H

#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO.h"


#define SSD_ZERO 0
#define SSD_ONE 1
#define SSD_TWO 2
#define SSD_THREE 3
#define SSD_FOUR 4
#define SSD_FIVE 5
#define SSD_SIX 6
#define SSD_SEVEN 7
#define SSD_EIGHT 8
#define SSD_NINE 9



/**********************APIs**********************/
void SSD_voidInitSingleDigit(u8 Copy_u8Port);
void SSD_voidInitDoubleDigit(u8 Copy_u8PortL, u8 Copy_u8PortU);

void SSD_voidWriteSingleDigit(u8 Copy_u8Port, u8 Copy_u8Value);
void SSD_voidWriteDoubleDigit(u8 Copy_u8PortL, u8 Copy_u8PortU, u8 Copy_u8Value);

#endif
