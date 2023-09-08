/*
 * ADC.h
 *
 *  Created on: Aug 22, 2023
 *      Author: Marawan Ahmed
 */

#ifndef ADC_H
#define ADC_H

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#define ADC_REF_VOLTEAGE	ADC_REF_AVCC  /*ADC_REF_AVCC, ADC_REF_AREF, ADC_REF_INTERNAL_2.56_V*/

/*******************Prescalar********************/
#define ADC_DIV_2	1
#define ADC_DIV_4	2
#define ADC_DIV_8	3
#define ADC_DIV_16	4
#define ADC_DIV_32	5
#define ADC_DIV_64	6
#define ADC_DIV_128	7

/*******************Channel********************/
#define ADC_CHANNEL_0	0
#define ADC_CHANNEL_1	1
#define ADC_CHANNEL_2	2
#define ADC_CHANNEL_3	3
#define ADC_CHANNEL_4	4
#define ADC_CHANNEL_5	5
#define ADC_CHANNEL_6	6
#define ADC_CHANNEL_7	7


/**********************APIs**********************/
void ADC_voidInit(u8 Copy_u8Prescaler);
u16 ADC_u16GetDigitalValue (u8 Copy_u8Channel);
void ADC_voidDisable (void);



#endif /* MCAL_ADC_ADC_H_ */
