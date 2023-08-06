/*
 * MWDT_program.c
 *
 *  Created on: Sep 14, 2022
 *      Author: emad
 */

#include "../../LIB/LIB_STD_TYPES.h"
#include "../../LIB/LIB_BIT_MATH.h"

#include "MWDT_private.h"
#include "MWDT_interface.h"

void MWDT_voidEnable(void)
{
	SET_BIT(WDTCR,WDTCR_WDE);
}
void MWDT_voidDisable(void)
{
	WDTCR = (1<<WDTCR_WDTOE) | (1<<WDTCR_WDE);
	WDTCR = 0;
}
void MWDT_u8Sleep(u8 Copy_u8SleepTime)
{
	if(Copy_u8SleepTime < 8)
	{
		WDTCR &= 0b11111000;
		WDTCR |= Copy_u8SleepTime;
	}
}
