/*
 * ICU.h
 *
 *  Created on: Aug 26, 2023
 *      Author: Marawan Ahmed
 */

#ifndef ICU_H
#define ICU_H


/********************************** Trigger *************************************/
#define ICU_FALLING_EDGE			0
#define ICU_RISING_EDGE				1


/********************************************************** APIs ****************************************************/

void ICU_voidInit			 (void);
void ICU_voidChangeTrigger	 (u8 Copy_u8Trigger);
void ICU_voidSetCallback  	(ptrFunc_Iv_Ov Copy_pf);
u16	 ICU_u16ReadValue	  	 (void);
void ICU_voidDisableInterrupt(void);


#endif /* MCAL_ICU_ICU_H_ */
