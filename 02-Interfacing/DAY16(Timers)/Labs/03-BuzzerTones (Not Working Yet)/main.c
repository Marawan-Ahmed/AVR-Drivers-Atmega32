/*
 * main.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Marawan Ahmed
 */


#include <avr/io.h>
#include <avr/interrupt.h>

#include "LIB/STD_Types.h"
#include "LIB/BIT_Math.h"

#include "MCAL/DIO/DIO.h"
#include "MCAL/TIM0/TIM0.h"
#include "MCAL/ADC/ADC.h"


u16	Global_u16Frequency = 1;
u16	Global_u16Periodms;

void CallbackFunc(void);

int main(){
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN2, DIO_PIN_INPUT);
	ADC_voidInit(ADC_DIV_64);
	u16 Local_u16DigitalValue;

	DIO_voidSetPortDirection(DIO_PORTB, DIO_PORT_OUTPUT);

	TIM0_voidOVFCallback(&CallbackFunc);

	TIM0_voidInit();
	TIM0_voidSetPreValue(232);
	TIM0_voidTimerStart(TIM0_PRE_DIV_8);

	sei();
	TIM0_voidOVFINTControl(TIM0_INT_ENABLE);

	while(1){
		Local_u16DigitalValue = ADC_u16GetDigitalValue(ADC_CHANNEL_2);
		Global_u16Periodms = (Local_u16DigitalValue )/1024;
//		DIO_voidTogglePinValue(DIO_PORTB,DIO_PIN0);
//		DIO_voidTogglePinValue(DIO_PORTB,DIO_PIN1);
//		DIO_voidTogglePinValue(DIO_PORTB,DIO_PIN2);
//		DIO_voidTogglePinValue(DIO_PORTB,DIO_PIN3);
	}
}



void CallbackFunc(void){
	static u16 Local_u16Count =0;
	if(Local_u16Count == 30){
		static u16 Local_u16Count_1 =0;
		if(Local_u16Count_1 == Global_u16Periodms){
			DIO_voidTogglePinValue(DIO_PORTB,DIO_PIN7);
			Local_u16Count_1 =0;
		}
		Local_u16Count_1++;
		Local_u16Count =0;
		TIM0_voidSetPreValue(232);
	}

	Local_u16Count++;
}
