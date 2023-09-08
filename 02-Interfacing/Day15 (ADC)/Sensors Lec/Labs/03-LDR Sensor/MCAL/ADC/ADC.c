/*
 * ADC.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Marawan Ahmed
 */
#include <avr/io.h>
#include <util/delay.h>

#define ADC_REF_AVCC	0
#define ADC_REF_AREF	1
#define ADC_REF_INTERNAL_2V56	2

#include "ADC.h"

void ADC_voidInit(u8 Copy_u8Prescaler){
	/*Enable ADC*/
	ADCSRA = SET_BIT(ADCSRA, ADEN);
	ADCSRA &= (0b11111000 | Copy_u8Prescaler);
//	ADCSRA |= Copy_u8Prescaler;

	/*Select VREF*/
	/*ADMUX REFS1,REFS0*/
	#if ADC_REF_VOLTEAGE == ADC_REF_AVCC
		ADMUX = SET_BIT(ADMUX, REFS0);
		ADMUX = CLR_BIT(ADMUX, REFS1);
	#elif ADC_REF_VOLTEAGE == ADC_REF_AREF
		ADMUX = CLR_BIT(ADMUX, REFS0);
		ADMUX = CLR_BIT(ADMUX, REFS1);
	#else
		ADMUX = SET_BIT(ADMUX, REFS0);
		ADMUX = SET_BIT(ADMUX, REFS1);
	#endif

	/*select right adjust*/
	ADMUX = CLR_BIT(ADMUX, ADLAR);



}

u16 ADC_u16GetDigitalValue (u8 Copy_u8Channel){
	/*Select Channel*/
	ADMUX &= 0b11100000;
	ADMUX |= Copy_u8Channel;

	/*Start Conversion*/
	ADCSRA = SET_BIT(ADCSRA, ADSC);
	while(GET_BIT(ADCSRA, ADIF) == 0); // Wait

	ADCSRA = CLR_BIT(ADCSRA,ADIF);

	return ADC;
}

void ADC_voidDisable (void){
	ADCSRA = CLR_BIT(ADCSRA, ADEN);

}
