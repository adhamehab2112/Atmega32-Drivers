/*
 * HKEY_PAD_program.c
 *
 *  Created on: Sep 5, 2022
 *      Author: emad
 */

#include "../../LIB/LIB_STD_TYPES.h"

#include "../../MCAL/MDIO/MDIO_interface.h"

#include "HKEY_PAD_interface.h"
#include "HKEY_PAD_config.h"


u8 HKYP_u8GetPressedKey(void)
{
	u8 loc_u8PressedKey = HKYP_NOT_PRESSED;
	u8 loc_u8ColsItr, loc_u8RowsItr;

	u8 loc_u8KYPArr[HKYP_ROWS_NOM][HKYP_COLS_NOM] = KYP_ARR;

	for(loc_u8ColsItr = HKYP_COLS_OFFSET; loc_u8ColsItr < (HKYP_COLS_NOM +HKYP_COLS_OFFSET); loc_u8ColsItr++)
	{
		MDIO_voidSetPinValue(HKYP_PORT, loc_u8ColsItr, MDIO_PIN_LOW);

		for(loc_u8RowsItr = HKYP_ROWS_OFFSET; loc_u8RowsItr < (HKYP_ROWS_NOM + HKYP_ROWS_OFFSET); loc_u8RowsItr++)
		{

			if (0  == MDIO_u8GetPinValue(HKYP_PORT,loc_u8RowsItr))
			{

				while(0  == MDIO_u8GetPinValue(HKYP_PORT,loc_u8RowsItr))
				{
					/*Wait untill key is released*/
				}

				return loc_u8KYPArr[loc_u8RowsItr - HKYP_ROWS_OFFSET][loc_u8ColsItr- HKYP_COLS_OFFSET];

			}else{
				/*DO NOTHING*/
			}


		}

		MDIO_voidSetPinValue(HKYP_PORT, loc_u8ColsItr, MDIO_PIN_HIGH);
	}


	return loc_u8PressedKey;
}
