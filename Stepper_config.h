/*
 * Stepper_config.h
 *
 *  Created on: Mar 13, 2019
 *      Author: Ahmed Tarek
 */

#ifndef STEPPER_CONFIG_H_
#define STEPPER_CONFIG_H_

#define STEPPER_COIL1			 DIO_PIN0
#define STEPPER_COIL2            DIO_PIN1
#define STEPPER_COIL3            DIO_PIN2
#define STEPPER_COIL4            DIO_PIN3

#define COIL_U8_ON				 (u8)1
#define COIL_U8_OFF				 (u8)0

/*STEPPER_STEP_TYPE : To choose between full step or half step	*/
/*Range 			: FULL_STEP									*/
/*					: HALF_STEP									*/
#define STEPPER_STEP_TYPE		FULL_STEP

#endif /* STEPPER_CONFIG_H_ */
