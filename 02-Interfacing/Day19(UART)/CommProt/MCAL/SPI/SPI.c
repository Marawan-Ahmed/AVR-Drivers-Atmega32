/*
 * SPI.c
 *
 *  Created on: Aug 29, 2023
 *      Author: Marawan Ahmed
 */

#define SPI_MODE_MASTER	1
#define SPI_MODE_SLAVE	2

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include <avr/io.h>
#include "SPI.h"

void SPI_voidInit			(void){
	#if SPI_MODE == SPI_MODE_MASTER
		/*select order -> MSB*/
		SPCR = CLR_BIT(SPCR, DORD);

		/*select Master mode*/
		SPCR = SET_BIT(SPCR, MSTR);

		/*Clock Polarity & Phase -> RISING_FALLING  setup sample*/
		SPCR = CLR_BIT(SPCR, CPOL);
		SPCR = SET_BIT(SPCR, CPHA);

		/*Set CLock Rate fck/16*/
		SPCR = SET_BIT(SPCR, SPR0);
		SPCR = CLR_BIT(SPCR, SPR1);
		SPSR = CLR_BIT(SPSR, SPI2X);


	#elif SPI_MODE == SPI_MODE_SLAVE
		/*select order -> MSB*/
		SPCR = CLR_BIT(SPCR, DORD);

		/*select Slave mode*/
		SPCR = CLR_BIT(SPCR, MSTR);

		/*Clock Polarity & Phase -> RISING_FALLING  setup sample*/
		SPCR = CLR_BIT(SPCR, CPOL);
		SPCR = SET_BIT(SPCR, CPHA);

		/*Set CLock Rate fck/16*/
		SPCR = SET_BIT(SPCR, SPR0);
		SPCR = CLR_BIT(SPCR, SPR1);
		SPSR = CLR_BIT(SPSR, SPI2X);
	#endif

	/*enable SPI*/
	SPCR = SET_BIT(SPCR, SPE);
}


void SPI_voidMasterSendData	(u8 Copy_u8Data){
	/* Start transmission */
	SPDR = Copy_u8Data;
	/* Wait for transmission complete */
	while(GET_BIT(SPSR,SPIF) == 0);
}

void SPI_voidSlaveSendData	(u8 Copy_u8Data){
	/* Start transmission */
	SPDR = Copy_u8Data;
}

u8 	 SPI_u8ReceiveData		(void){
	/* Wait for reception complete */
	while(GET_BIT(SPSR,SPIF) == 0);
	/* Return data register */
	return SPDR;
}

u8 	 SPI_u8ReceiveTransmit	(u8 Copy_u8Data){
	SPDR = Copy_u8Data;
	/* Wait for transmission complete */
	while(GET_BIT(SPSR,SPIF) == 0);
	return SPDR;
}
