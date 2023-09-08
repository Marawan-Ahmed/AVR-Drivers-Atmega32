/*
 * INT.C

 *
 *  Created on: Aug 21, 2023
 *      Author: Marawan Ahmed
 */

#include <avr/interrupt.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "INT.h"

ptrFunc_Iv_Ov Global_ISR_INT0_ptr = NULL;
ptrFunc_Iv_Ov Global_ISR_INT1_ptr = NULL;
ptrFunc_Iv_Ov Global_ISR_INT2_ptr = NULL;

void INT_voidEnable(u8 Copy_u8INTIndex, u8 Copy_u8INTSense){
	switch (Copy_u8INTIndex) {
		case INT_INT0:
			switch (Copy_u8INTSense) {
				case INT_SENSE_FALLING_EDGE:
					MCUCR = CLR_BIT(MCUCR, ISC00);
					MCUCR = SET_BIT(MCUCR, ISC01);
					break;
				case INT_SENSE_RISING_EDGE:
					MCUCR = SET_BIT(MCUCR, ISC00);
					MCUCR = SET_BIT(MCUCR, ISC01);
					break;

				case INT_SENSE_ANY_CHANGE:
					MCUCR = SET_BIT(MCUCR, ISC00);
					MCUCR = CLR_BIT(MCUCR, ISC01);
					break;

				case INT_SENSE_LOW_LEVEL:
					MCUCR = CLR_BIT(MCUCR, ISC00);
					MCUCR = CLR_BIT(MCUCR, ISC01);
					break;
			}
			GICR = SET_BIT(GICR, INT0);
			break;

		case INT_INT1:
			switch (Copy_u8INTSense) {
				case INT_SENSE_FALLING_EDGE:
					MCUCR = CLR_BIT(MCUCR, ISC10);
					MCUCR = SET_BIT(MCUCR, ISC11);
					break;
				case INT_SENSE_RISING_EDGE:
					MCUCR = SET_BIT(MCUCR, ISC10);
					MCUCR = SET_BIT(MCUCR, ISC11);
					break;

				case INT_SENSE_ANY_CHANGE:
					MCUCR = SET_BIT(MCUCR, ISC10);
					MCUCR = CLR_BIT(MCUCR, ISC11);
					break;

				case INT_SENSE_LOW_LEVEL:
					MCUCR = CLR_BIT(MCUCR, ISC10);
					MCUCR = CLR_BIT(MCUCR, ISC11);
					break;
			}
			GICR = SET_BIT(GICR, INT1);
			break;

		case INT_INT2:
			switch (Copy_u8INTSense) {
				case INT_SENSE_FALLING_EDGE:
					MCUCSR = CLR_BIT(MCUCSR, ISC2);
					break;
				case INT_SENSE_RISING_EDGE:
					MCUCSR = SET_BIT(MCUCSR, ISC2);
					break;

			}
			GICR = SET_BIT(GICR, INT2);
			break;
	}
}
void INT_voidDisable(u8 Copy_u8INTIndex){
	switch (Copy_u8INTIndex) {
		case INT_INT0:
			GICR = CLR_BIT(GICR, INT0);
			break;

		case INT_INT1:
			GICR = CLR_BIT(GICR, INT1);
			break;

		case INT_INT2:
			GICR = CLR_BIT(GICR, INT2);
			break;
	}
}

void INT_voidSetCallback(u8 Copy_u8INTIndex, ptrFunc_Iv_Ov ptr){
	switch (Copy_u8INTIndex) {
		case INT_INT0:
			Global_ISR_INT0_ptr = ptr;
			break;

		case INT_INT1:
			Global_ISR_INT1_ptr = ptr;
			break;

		case INT_INT2:
			Global_ISR_INT2_ptr = ptr;
			break;
	}
}

ISR(INT0_vect){
	if(Global_ISR_INT0_ptr != NULL){
		Global_ISR_INT0_ptr();
	}
}

ISR(INT1_vect){
	if(Global_ISR_INT1_ptr != NULL){
		Global_ISR_INT1_ptr();
	}
}

ISR(INT2_vect){
	if(Global_ISR_INT2_ptr != NULL){
		Global_ISR_INT2_ptr();
	}
}
