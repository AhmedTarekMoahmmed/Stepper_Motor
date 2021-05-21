/*
 * Stepper_private.h
 *
 *  Created on: Mar 13, 2019
 *      Author: Ahmed Tarek
 */

#ifndef STEPPER_PRIVATE_H_
#define STEPPER_PRIVATE_H_

#define FULL_STEP		(u8)0
#define HALF_STEP		(u8)1



static u8 u8RotateClkWise(u32 Copy_u32StepsNb , f32 Copy_f32Time);
static u8 u8RotateAntiClkWise(u32 Copy_u32StepsNb ,f32 Copy_f32Time);
static u8 u8HalfStepRotateClkWise(u32 Copy_u32StepsNb , f32 Copy_f32Time);
static u8 u8HalfStepRotateAntiClkWise(u32 Copy_u32StepsNb ,f32 Copy_f32Time);

#define INITIAL_LOOP_VALUE				(u8)0
#define STEPPER_MIN_TIME_TO_ROTATE		(u8)2
#define MAX_NO_OF_STEPS					(u32)512
#define MIN_TIM_FOR_4_STEPS				(u32)2
#define MAX_TIM							(u32)4294967295

#define MAX_NO_OF_STEPS_IN_U32			(u32)4294967295


#endif /* STEPPER_PRIVATE_H_ */
