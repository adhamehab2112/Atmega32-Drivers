/*
 * MEXTI_program.c
 *
 *  Created on: Sep 7, 2022
 *      Author: emad
 */

#include "../../LIB/LIB_STD_TYPES.h"
#include "../../LIB/LIB_BIT_MATH.h"

#include "MEXTI_private.h"
#include "MEXTI_interface.h"


void (*pfunEXTI_ISR)(void);


void MEXTI_voidINT1Init(void)
{

	/*Enable EXTI1*/
	SET_BIT(GICR, INT1);

	/*Configure Control Sense EXT1*/
	/*Falling Edge*/
	CLR_BIT(MCUCR, SC10);
	SET_BIT(MCUCR, SC11);

	/*Enable Global Interrupt*/
	SET_BIT(SREG, I_BIT);

}

/***************************************************************************************/
/* Description: Interface to get the ID of the pressed key, return 0 incase no key     */
/*              is pressed, this function doesn't handle the sitaution if 2 keys are   */
/*              pressed at the same time                               	     		   */
/* Input      : Nothing                                                                */
/* Output     : Nothing                                                                */
/***************************************************************************************/
void EXTI1_voidCallback(void(*ptr)(void))
{

	pfunEXTI_ISR = ptr;

}



void __vector_2(void) __attribute__((signal));

void __vector_2(void)
{

	pfunEXTI_ISR();

}







