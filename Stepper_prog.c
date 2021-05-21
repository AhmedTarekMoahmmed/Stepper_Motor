/*
 * Stepper_prog.c
 *
 *  Created on: Mar 13, 2019
 *      Author: Ahmed Tarek
 */



#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include <util/delay.h>

#include "DIO_interface.h"


#include "STEPPER_interface.h"
#include "STEPPER_config.h"
#include "STEPPER_private.h"



void Stepper_voidInit()
{

}

/*************************************************************************************************/
/*Stepper_u8SetAngle : this function is used to make the stepper move  certain number of degree
 *                      in certain direction for certain time 									 */
/*INPUTS :u16 Copy_u16StepsNo: number of degree gives to motor to move 							 */
/*					Range :			 STEPPER_U32_ANGLE_35 		                            	 */
/*									 STEPPER_U32_ANGLE_45 		                            	 */
/*									 STEPPER_U32_ANGLE_70 		                        		 */
/*									 STEPPER_U32_ANGLE_90 		                        		 */
/*									 STEPPER_U32_ANGLE_135		                        		 */
/*									 STEPPER_U32_ANGLE_180		                        		 */
/*									 STEPPER_U32_ANGLE_225   	                        		 */
/*									 STEPPER_U32_ANGLE_270		                        		 */
/*									 STEPPER_U32_ANGLE_315		                        		 */
/*									 STEPPER_U32_ANGLE_360	                                     */
/*		:u8	Copy_u8Time		:time which's taken to reach the end of the angle           		 */
/*					Range :			 STEPPER_U32_ANGLE_35 		      min time  100              */
/*									 STEPPER_U32_ANGLE_45 		      min time  128              */
/*									 STEPPER_U32_ANGLE_70 		      min time  200    	         */
/*									 STEPPER_U32_ANGLE_90 		      min time  256    	         */
/*									 STEPPER_U32_ANGLE_135		      min time  384    	         */
/*									 STEPPER_U32_ANGLE_180		      min time  512    	         */
/*									 STEPPER_U32_ANGLE_225   	      min time  640    	         */
/*									 STEPPER_U32_ANGLE_270		      min time  768    	         */
/*									 STEPPER_U32_ANGLE_315		      min time  896    	         */
/*									 STEPPER_U32_ANGLE_360	          min time  1024             */
/*		:u8	Copy_u8Direction: the direction of rotation 		 								 */
/*					   Range: ANTICLOCKWISE OR CLOCKWISE									     */
/*OUTPUTS: Error state  : STD_u8_OK ==> that's meaning no error									 */
/*						  STD_u8_ERROR ==> that's meaning  error								 */


u8 Stepper_u8SetAngle(f32 Copy_f32Angle, f32 Copy_f32Time, u8 Copy_u8Direction)
{
	u8 Local_u8OperationState = STD_u8_OK;

	f32 Local_f32StepTime = Copy_f32Time / Copy_f32Angle ;


	switch(Copy_u8Direction)
		{
		case ANTICLOCKWISE    :
			switch(STEPPER_STEP_TYPE)
			{
			case FULL_STEP:
			Local_u8OperationState = u8RotateAntiClkWise(Copy_f32Angle , Local_f32StepTime);
			break;

			case HALF_STEP:
			Local_u8OperationState = u8HalfStepRotateAntiClkWise(Copy_f32Angle , Local_f32StepTime);
			}
			break;

		case CLOCKWISE:
			switch(STEPPER_STEP_TYPE)
			{
			case FULL_STEP:
			Local_u8OperationState = u8RotateClkWise(Copy_f32Angle , Local_f32StepTime);
			break;

			case HALF_STEP:
			Local_u8OperationState = u8HalfStepRotateClkWise(Copy_f32Angle , Local_f32StepTime);
			}

			break;

		default : Local_u8OperationState = STD_u8_ERROR;
		}


	return Local_u8OperationState;
}


/***************************************Stepper_u8SetStepsNo****************************************/

u8 Stepper_u8SetStepsNo(u32 Copy_u32StepsNo, f32 Copy_f32Time, u8 Copy_u8Direction )
{
	u8 Local_u8OperationState = STD_u8_OK;
	f32 Local_f32StepTime = Copy_f32Time / Copy_u32StepsNo ;

	switch(Copy_u8Direction)
	{
	case ANTICLOCKWISE    :
		switch(STEPPER_STEP_TYPE)
		{
		case FULL_STEP:
		Local_u8OperationState = u8RotateAntiClkWise(Copy_u32StepsNo , Local_f32StepTime);
		break;

		case HALF_STEP:
		Local_u8OperationState = u8HalfStepRotateAntiClkWise(Copy_u32StepsNo , Local_f32StepTime);
		}
		break;
	case CLOCKWISE:
		switch(STEPPER_STEP_TYPE)
		{
		case FULL_STEP:
		Local_u8OperationState = u8RotateClkWise(Copy_u32StepsNo , Local_f32StepTime);
		break;

		case HALF_STEP:
		Local_u8OperationState = u8HalfStepRotateClkWise(Copy_u32StepsNo , Local_f32StepTime);
		}
		break;

	default : Local_u8OperationState = STD_u8_ERROR;
	}

	return Local_u8OperationState;
}




/******************************************Stepper_u8SetRotationsNo**************************************/

u8 Stepper_u8SetRotationsNo(u32 Copy_u32CyclesNo, f32 Copy_f32Time, u8 Copy_u8Direction )
{
	u8 Local_u8OperationState = STD_u8_OK;
	f32 Local_f32StepTime = Copy_f32Time / (MAX_NO_OF_STEPS * Copy_u32CyclesNo) ;


	switch(Copy_u8Direction)
		{
		case ANTICLOCKWISE    :
			switch(STEPPER_STEP_TYPE)
			{
			case FULL_STEP:
			Local_u8OperationState = u8RotateAntiClkWise(Copy_u32CyclesNo , Local_f32StepTime);
			break;

			case HALF_STEP:
			Local_u8OperationState = u8HalfStepRotateAntiClkWise(Copy_u32CyclesNo , Local_f32StepTime);
			}
			break;
		case CLOCKWISE:
			switch(STEPPER_STEP_TYPE)
			{
			case FULL_STEP:
			Local_u8OperationState = u8RotateClkWise(Copy_u32CyclesNo , Local_f32StepTime);
			break;

			case HALF_STEP:
			Local_u8OperationState = u8HalfStepRotateClkWise(Copy_u32CyclesNo , Local_f32StepTime);
			}
			break;

		default : Local_u8OperationState = STD_u8_ERROR;
		}



	return Local_u8OperationState;
}





/**********************************(private function) u8RotateClkWise_u8RotateAntiClkWise_FullStepp***********************************************/

static u8 u8RotateClkWise(u32 Copy_u32StepsNb , f32 Copy_f32Time)
{
	u8 Local_u8OperationState = STD_u8_OK;
	u32 Local_u32Index;

	if ( (Copy_u32StepsNb > MAX_NO_OF_STEPS_IN_U32) ||
			( (Copy_f32Time < MIN_TIM_FOR_4_STEPS) || (Copy_f32Time > MAX_TIM) )
		)
	{
		Local_u8OperationState = STD_u8_ERROR;
	}
	else
	{
	for(Local_u32Index = INITIAL_LOOP_VALUE ; Local_u32Index < Copy_u32StepsNb ; Local_u32Index++)

			{



	DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_ON);
	DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_OFF);
	DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_OFF);
	DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_OFF);
	_delay_ms(Copy_f32Time);

	DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_OFF);
	DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_OFF);
	DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_OFF);
	DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_ON);
	_delay_ms(Copy_f32Time);

	DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_OFF);
	DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_OFF);
	DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_ON);
	DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_OFF);
	_delay_ms(Copy_f32Time);


	DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_OFF);
	DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_ON);
	DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_OFF);
	DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_OFF);
	_delay_ms(Copy_f32Time);

			}
	}
	return Local_u8OperationState;
}



/******************************u8RotateAntiClkWise_FullStepp************************************/
static u8 u8RotateAntiClkWise(u32 Copy_u32StepsNb ,f32 Copy_f32Time)
{

	u8 Local_u8OperationState = STD_u8_OK;
	u32 Local_u16Index;



	if ( (Copy_u32StepsNb > MAX_NO_OF_STEPS_IN_U32) ||
			( (Copy_f32Time < MIN_TIM_FOR_4_STEPS) || (Copy_f32Time > MAX_TIM) )
		)
	{
		Local_u8OperationState = STD_u8_ERROR;
	}
	else
	{

		for(Local_u16Index = INITIAL_LOOP_VALUE ; Local_u16Index < Copy_u32StepsNb ; Local_u16Index++)

				{
			DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_ON);
			DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_OFF);
			_delay_ms(Copy_f32Time);

			DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_ON);
			DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_OFF);
			_delay_ms(Copy_f32Time);

			DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_ON);
			DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_OFF);
			_delay_ms(Copy_f32Time);


			DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_ON);
			_delay_ms(Copy_f32Time);
			}


	}

	return Local_u8OperationState;

}



/**********************************(private function) u8RotateClkWise_u8RotateAntiClkWise_HalfStepp***********************************************/

static u8 u8HalfStepRotateClkWise(u32 Copy_u32StepsNb , f32 Copy_f32Time)
{
	u8 Local_u8OperationState = STD_u8_OK;
	u32 Local_u32Index;

	if ( (Copy_u32StepsNb > MAX_NO_OF_STEPS_IN_U32) ||
			( (Copy_f32Time < MIN_TIM_FOR_4_STEPS) || (Copy_f32Time > MAX_TIM) )
		)
	{
		Local_u8OperationState = STD_u8_ERROR;
	}
	else
	{
	for(Local_u32Index = INITIAL_LOOP_VALUE ; Local_u32Index < Copy_u32StepsNb ; Local_u32Index++)

			{


			DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_ON);
			_delay_ms(Copy_f32Time);


		/*
			DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_ON);
			DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_ON);
			_delay_ms(Copy_f32Time);
		*/


			DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_ON);
			DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_OFF);
			_delay_ms(Copy_f32Time);


		/*
			DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_ON);
			DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_ON);
			DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_OFF);
			_delay_ms(Copy_f32Time);
		*/


			DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_ON);
			DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_OFF);
			_delay_ms(Copy_f32Time);




			DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_ON);
			DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_ON);
			DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_OFF);
			_delay_ms(Copy_f32Time);

			DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_ON);
			DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_OFF);
			_delay_ms(Copy_f32Time);

			DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_ON);
			DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_ON);
			_delay_ms(Copy_f32Time);

			}
	}
	return Local_u8OperationState;
}



/******************************u8RotateAntiClkWise_HalfStep************************************/
static u8 u8HalfStepRotateAntiClkWise(u32 Copy_u32StepsNb ,f32 Copy_f32Time)
{

	u8 Local_u8OperationState = STD_u8_OK;
	u32 Local_u16Index;



	if ( (Copy_u32StepsNb > MAX_NO_OF_STEPS_IN_U32) ||
			( (Copy_f32Time < MIN_TIM_FOR_4_STEPS) || (Copy_f32Time > MAX_TIM) )
		)
	{
		Local_u8OperationState = STD_u8_ERROR;
	}
	else
	{

		for(Local_u16Index = INITIAL_LOOP_VALUE ; Local_u16Index < Copy_u32StepsNb ; Local_u16Index++)

				{




			DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_ON);
			DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_OFF);
			_delay_ms(Copy_f32Time);

			DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_ON);
			DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_ON);
			DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_OFF);
			_delay_ms(Copy_f32Time);


			DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_ON);
			DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_OFF);
			_delay_ms(Copy_f32Time);

			DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_ON);
			DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_ON);
			DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_OFF);
			_delay_ms(Copy_f32Time);

			DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_ON);
			DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_OFF);
			_delay_ms(Copy_f32Time);

			DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_ON);
			DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_ON);
			_delay_ms(Copy_f32Time);


			DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_ON);
			_delay_ms(Copy_f32Time);


			DIO_u8SetPinValue(STEPPER_COIL1,COIL_U8_ON);
			DIO_u8SetPinValue(STEPPER_COIL2,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL3,COIL_U8_OFF);
			DIO_u8SetPinValue(STEPPER_COIL4,COIL_U8_ON);
			_delay_ms(Copy_f32Time);





				}
	}

	return Local_u8OperationState;

}






