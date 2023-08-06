/*
 * HLED_program.c
 *
 *  Created on: Sep 1, 2022
 *      Author: emad
 */

#include "../../LIB/LIB_STD_TYPES.h"
#include "../../MCAL/MDIO/MDIO_interface.h"


void HLED_voidON(u8 Copy_u8Port,u8 Copy_u8Pin)
{

	MDIO_voidSetPinDirection(Copy_u8Port, Copy_u8Pin, MDIO_PIN_OUTPUT);
	MDIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, MDIO_PIN_HIGH);

}


void HLED_voidOFF(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	MDIO_voidSetPinDirection(Copy_u8Port, Copy_u8Pin, MDIO_PIN_OUTPUT);
	MDIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, MDIO_PIN_LOW);
}


void HLED_voidToggle(u8 Copy_u8Port,u8 Copy_u8Pin)
{


	if (0 == MDIO_u8GetPinValue(Copy_u8Port, Copy_u8Pin))
	{

		MDIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, MDIO_PIN_HIGH);

	}else if (1 == MDIO_u8GetPinValue(Copy_u8Port, Copy_u8Pin))
	{
		MDIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, MDIO_PIN_LOW);

	}else{
		/*DO NOTHING*/
	}
}





