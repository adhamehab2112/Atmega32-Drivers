/*
 * MUART_program.c
 *
 *  Created on: Sep 15, 2022
 *      Author: emad
 */


#include "../../LIB/LIB_STD_TYPES.h"
#include "../../LIB/LIB_BIT_MATH.h"


#include "MUART_config.h"
#include "MUART_private.h"
#include "MUART_interface.h"

void MUART_voidInit(void)
{

	/* Configure Baud Rate
	 * BaudRate -> 9600/8MhZ*/
	UBRRL = 51;
	/*Configure Frame Format
	 * 8 data, 1 stop, No Parity*/
	UCSRC =  UCSRC | (UCSRC << 7) | (UCSRC << 2)| (UCSRC << 1); //0x86;
	// Enable RX
	SET_BIT(UCSRB, 4);
	SET_BIT(UCSRB, 3);
}

void MUART_voidSendChar(u8 Copy_u8Data)
{

	while(0 == GET_BIT(UCSRA,5))
	{
		// Wait until transmission Register Empty
		// UDRE = 1 USART Data Register Empty and ready to be written
	}
	// write data to Data Register
	UDR = Copy_u8Data;
}

void MUART_voidSendString(char *Copy_u8String)
{
	u8 loc_u8Char = 0;
	while(Copy_u8String[loc_u8Char] != '\0')
	{
		MUART_voidSendChar(Copy_u8String[loc_u8Char]);
		loc_u8Char++;
	}

}

u8 MUART_u8GetChar(void)
{
	u8 local_u8Result;

	while(0 == GET_BIT(UCSRA,7))
	{
		// Wait until Reception Complete
	}
	local_u8Result = UDR;

	/* Clear Flag */
	SET_BIT(UCSRA,7);

	return local_u8Result;

}
