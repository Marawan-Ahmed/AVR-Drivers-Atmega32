#include <avr/io.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../HAL/SSD/SSD.h"

u8 SSD_mappingArray[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void SSD_voidInitSingleDigit(u8 Copy_u8Port){
	DIO_voidSetPortDirection (Copy_u8Port, DIO_PORT_OUTPUT);
}

void SSD_voidInitDoubleDigit(u8 Copy_u8PortL, u8 Copy_u8PortU){
	DIO_voidSetPortDirection (Copy_u8PortL, DIO_PORT_OUTPUT);
	DIO_voidSetPortDirection (Copy_u8PortU, DIO_PORT_OUTPUT);
}

void SSD_voidWriteSingleDigit(u8 Copy_u8Port, u8 Copy_u8Value){
//	DIO_voidSetPortValue (Copy_u8Port, SSD_mappingArray[Copy_u8Value]);
	DIO_voidSetPortValue (Copy_u8Port, 0xff);
}

void SSD_voidWriteDoubleDigit(u8 Copy_u8PortL, u8 Copy_u8PortU, u8 Copy_u8Value){
	DIO_voidSetPortValue (Copy_u8PortL, SSD_mappingArray[Copy_u8Value%10]);
	DIO_voidSetPortValue (Copy_u8PortU, SSD_mappingArray[Copy_u8Value/10]);
}
