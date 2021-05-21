/*********************************************Stepper_interface.h****************************************************/
/* Author : Ahmed Tarek																								*/
/* Date   : 14 mar 2019  																						 	*/
/* Driver : STEPPER MOTOR																							*/
/* Layer  : HAL         																							*/
/********************************************************************************************************************/
/*Description */
/**/
/********************************************************************************************************************/

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_


#define CLOCKWISE 		(u8)0
#define ANTICLOCKWISE 	(u8)1


#define NO_OF_LOOP_STEPS			u8(512)



void Stepper_voidInit();






#define STEPPER_U32_ANGLE_35     (u32)50
#define STEPPER_U32_ANGLE_45     (u32)64
#define STEPPER_U32_ANGLE_70     (u32)100
#define STEPPER_U32_ANGLE_90     (u32)128
#define STEPPER_U32_ANGLE_135    (u32)192
#define STEPPER_U32_ANGLE_180    (u32)256
#define STEPPER_U32_ANGLE_225    (u32)320
#define STEPPER_U32_ANGLE_270    (u32)384
#define STEPPER_U32_ANGLE_315    (u32)448
#define STEPPER_U32_ANGLE_360    (u32)512


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


u8 Stepper_u8SetAngle(f32 Copy_f32Angle, f32 Copy_f32Time, u8 Copy_u8Direction);



/*************************************************************************************************/
/*Stepper_u8SetStepsNo : this function is used to make the stepper move  certain number of steps
 *                      in certain direction for certain time 									 */
/*INPUTS :u16 Copy_u16StepsNo: number of steps gives to motor to move 							 */
/*						Range:total number of steps per full cycle = 512	in case full step	 */
/*						     total number of steps per full cycle = 512 	in case half step	 */
/*						note:this step equal 4 actual steps in case full step					 */
/*							 this step equal 8 actual steps in case half step	                 */
/*		:u8	Copy_u8Time		: time which's taken to do all no of steps 							 */
/*					Range   : minimum time for the step equal 2 msec	and max time = 4    	 */
/*							if you will parse 2 steps must parse 4 msec min and so on            */
/*		:u8	Copy_u8Direction: the direction of rotation 		 								 */
/*					   Range: ANTICLOCKWISE OR CLOCKWISE									     */
/*OUTPUTS: Error state  : STD_u8_OK ==> that's meaning no error									 */
/*						  STD_u8_ERROR ==> that's meaning  error								 */
/**/

u8 Stepper_u8SetStepsNo(u32 Copy_u16StepsNo, f32 Copy_f32Time, u8 Copy_u8Direction );


/*************************************************************************************************/



/**************************************************************************************************/
/*Stepper_u8SetRotationsNo : this function is used to make the stepper move  certain number of cycle
 *                      in certain direction for certain time 									 */
/*INPUTS :u16 Copy_u16CyclesNo: number of cycle gives to motor to move 							 */
/*						note:this cycle equal 2048 actual steps in case full step   			 */
/*							 this cycle equal 4096 actual steps in case full step	             */
/*		:u8	Copy_u8Time		: time which's taken to do all no of steps 							 */
/*					Range   : minimum time for the step equal 2 msec	and max time = 4	 	 */
/*							if you will parse 2 steps must parse 4 msec min and so on           */
/*		:u8	Copy_u8Direction: the direction of rotation 		 								 */
/*					   Range: ANTICLOCKWISE OR CLOCKWISE									     */
/*OUTPUTS: Error state  : STD_u8_OK ==> that's meaning no error									 */
/*						  STD_u8_ERROR ==> that's meaning no error								 */


u8 Stepper_u8SetRotationsNo(u32 Copy_u16CyclesNo, f32 Copy_f32Time, u8 Copy_u8Direction );

#endif /* STEPPER_INTERFACE_H_ */
