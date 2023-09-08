/*
 * ICU.c
 *
 *  Created on: Aug 26, 2023
 *      Author: Marawan Ahmed
 */



#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "ICU.h"


//void (*ICU_pf) (void);
ptrFunc_Iv_Ov Global_ISR_ICU_ptr = NULL;


void ICU_voidInit (void){
	/* Select Timer1 Normal Mode */
	TCCR1A = CLR_BIT(TCCR1A, WGM10);
	TCCR1A = CLR_BIT(TCCR1A, WGM11);
	TCCR1A = CLR_BIT(TCCR1B, WGM12);
	TCCR1A = CLR_BIT(TCCR1B, WGM13);

	/* Prescaler (8) */
	TCCR1B &= 0b11111000;
	TCCR1B |= 0b00000010;

	/* enable interrupt */
	TIMSK = SET_BIT(TIMSK, TICIE1);

	/* select trigger(Rising) */
	TIMSK = SET_BIT(TCCR1B, ICES1);
}


void ICU_voidChangeTrigger	 (u8 Copy_u8Trigger){
	switch (Copy_u8Trigger) {
		case ICU_FALLING_EDGE: TCCR1B = CLR_BIT(TCCR1B, ICES1);	break;
		case ICU_RISING_EDGE:  TCCR1B = SET_BIT(TCCR1B, ICES1);	break;
	}
}


void ICU_voidSetCallback  	(ptrFunc_Iv_Ov Copy_pf){
	Global_ISR_ICU_ptr = Copy_pf;
}


u16	 ICU_u16ReadValue (void){
	return ICR1;
}


void ICU_voidDisableInterrupt(void){
	/* disable interrupt */
	TIMSK = CLR_BIT(TIMSK, TICIE1);
}


ISR(TIMER1_CAPT_vect){
	Global_ISR_ICU_ptr();
}

//void ICU_HW (void){
//	static u8 Local_u8Count =0;
//	static u16 Local_u16Read_1, Local_u16Read_2, Local_u16Read_3;
//
//	if (Local_u8Count == 1) {
//		Local_u16Read_1 = ICU_u16ReadValue();
//
//	} else if(Local_u8Count == 2){
//		Local_u16Read_2 = ICU_u16ReadValue();
//		ICU_voidChangeTrigger(ICU_FALLING_EDGE);
//		PeriodTicks = Local_u16Read_2 - Local_u16Read_1;
//	}
//	else if(Local_u8Count == 3){
//		Local_u16Read_3 = ICU_u16ReadValue();
//		ONTicks = Local_u16Read_3 - Local_u16Read_2;
//		ICU_voidDisableInterrupt();
//	}
//
//	Local_u8Count++;
//}
