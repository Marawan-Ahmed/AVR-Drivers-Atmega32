/*
 * SPI.H
 *
 *  Created on: Aug 29, 2023
 *      Author: Marawan Ahmed
 */

#ifndef SPI_H
#define SPI_H

/***************select mater or slave*******/
#define SPI_MODE	SPI_MODE_MASTER



void SPI_voidInit			(void);
void SPI_voidMasterSendData	(u8 Copy_u8Data);
void SPI_voidSlaveSendData	(u8 Copy_u8Data);
u8 	 SPI_u8ReceiveData		(void);
u8 	 SPI_u8ReceiveTransmit	(u8 Copy_u8Data);

#endif /* MCAL_SPI_SPI_H_ */
