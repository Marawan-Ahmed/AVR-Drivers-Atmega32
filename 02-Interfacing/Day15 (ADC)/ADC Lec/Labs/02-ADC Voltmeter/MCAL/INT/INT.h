/*
 * INT.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Marawan Ahmed
 */

#ifndef INT_H
#define INT_H


/***********************Cfg***********************/
#define INT_INT0	0
#define INT_INT1	1
#define INT_INT2	2


/***********************Sense***********************/
#define INT_SENSE_FALLING_EDGE	0
#define INT_SENSE_RISING_EDGE	1
#define INT_SENSE_ANY_CHANGE	2
#define INT_SENSE_LOW_LEVEL 	3

/**********************APIs**********************/
void INT_voidEnable(u8 Copy_u8INTIndex, u8 Copy_u8INTSense);
void INT_voidDisable(u8 Copy_u8INTIndex);

#endif /* MCAL_INT_INT_H_ */
