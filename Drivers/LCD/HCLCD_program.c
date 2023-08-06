/*
 * HCLCD_program.c
 *
 *  Created on: Sep 4, 2022
 *      Author: emad
 */


#include "../../LIB/LIB_STD_TYPES.h"

#include "../../MCAL/MDIO/MDIO_interface.h"

#include "HCLCD_interface.h"
#include "HCLCD_config.h"

#include <avr/delay.h>

void HCLCD_voidInit(void)
{
	_delay_ms(40);
	/*Function Set with 2 line and font 5*7*/
	HCLCD_voidSendCmd(0b00111000);

	/*Display Control with Entire Data and no Cursor*/
	HCLCD_voidSendCmd(0b00001100);

	/*Display Clear*/
	HCLCD_voidSendCmd(0b00000001);

	/*Entry Mode Set*/
	HCLCD_voidSendCmd(0b00000110);
}

void HCLCD_voidSendCmd(u8 Copy_u8Cmd)
{
	/*Configure RS to LOW*/
	MDIO_voidSetPinValue(HCLCD_CONTROL_PORT,HCLCD_RS_PIN,MDIO_PIN_LOW);

	/*Configure RW to LOW*/
	MDIO_voidSetPinValue(HCLCD_CONTROL_PORT,HCLCD_RW_PIN,MDIO_PIN_LOW);

	/*Send Command*/
	MDIO_voidSetPortValue(HCLCD_DATA_PORT, Copy_u8Cmd);

	/*Configure E to HIGH*/
	MDIO_voidSetPinValue(HCLCD_CONTROL_PORT,HCLCD_E_PIN,MDIO_PIN_HIGH);

	_delay_ms(2);
	/*Configure E to LOW*/
	MDIO_voidSetPinValue(HCLCD_CONTROL_PORT,HCLCD_E_PIN,MDIO_PIN_LOW);
}

void HCLCD_voidSendData(u8 Copy_u8Data)
{

	/*Configure RS to HIGH*/
	MDIO_voidSetPinValue(HCLCD_CONTROL_PORT,HCLCD_RS_PIN,MDIO_PIN_HIGH);

	/*Configure RW to LOW*/
	MDIO_voidSetPinValue(HCLCD_CONTROL_PORT,HCLCD_RW_PIN,MDIO_PIN_LOW);

	/*Send Command*/
	MDIO_voidSetPortValue(HCLCD_DATA_PORT, Copy_u8Data);
	/*Configure E to HIGH*/
	MDIO_voidSetPinValue(HCLCD_CONTROL_PORT,HCLCD_E_PIN,MDIO_PIN_HIGH);

	_delay_ms(2);
	/*Configure E to LOW*/
	MDIO_voidSetPinValue(HCLCD_CONTROL_PORT,HCLCD_E_PIN,MDIO_PIN_LOW);

}






void HCLCD_voidWriteChar(u8 Copy_u8Char)
{
	HCLCD_voidSendData(Copy_u8Char);
}


void HCLCD_voidWriteString(u8 *Copy_pu8StrArr)
{
	u8 local_u8Iterator = 0;

	while(Copy_pu8StrArr[local_u8Iterator] != 0)
	{
		HCLCD_voidSendData(Copy_pu8StrArr[local_u8Iterator]);

		local_u8Iterator++;
	}

}

void HCLCD_voidWriteNumber(u32 Copy_u8Number, u8 Copy_u8Xpos, u8 Copy_u8Ypos)
{
	u8 loc_u8Remainder = 0;

	if(Copy_u8Number == 0){

		HCLCD_voidGoToXY(Copy_u8Xpos, Copy_u8Ypos);

		HCLCD_voidSendData(Copy_u8Number+48);

	}else{



		while(Copy_u8Number > 0)
		{

			loc_u8Remainder = Copy_u8Number % 10;

			if(Copy_u8Number > 99999)
			{
				HCLCD_voidGoToXY(Copy_u8Xpos, Copy_u8Ypos + 5);

				HCLCD_voidSendData(loc_u8Remainder+48);
			}
			else if(Copy_u8Number > 9999)
			{
				HCLCD_voidGoToXY(Copy_u8Xpos, Copy_u8Ypos + 4);

				HCLCD_voidSendData(loc_u8Remainder+48);
			}
			else if(Copy_u8Number > 999)
			{
				HCLCD_voidGoToXY(Copy_u8Xpos, Copy_u8Ypos + 3);

				HCLCD_voidSendData(loc_u8Remainder+48);
			}
			else if(Copy_u8Number > 99)
			{

				HCLCD_voidGoToXY(Copy_u8Xpos, Copy_u8Ypos + 2);

				HCLCD_voidSendData(loc_u8Remainder+48);

			}else if(Copy_u8Number > 9)
			{
				HCLCD_voidGoToXY(Copy_u8Xpos, Copy_u8Ypos + 1);

				HCLCD_voidSendData(loc_u8Remainder+48);

			}else if (Copy_u8Number >= 0)
			{
				HCLCD_voidGoToXY(Copy_u8Xpos, Copy_u8Ypos);

				HCLCD_voidSendData(Copy_u8Number+48);



			}else{/*DO NOTHING*/}

			Copy_u8Number = Copy_u8Number / 10;

		}
	}

}


void HCLCD_voidGoToXY(u8 Copy_Xpos, u8 Copy_Ypos)
{
	u8 local_u8Address;
	/*First row x=1*/
	if(1 == Copy_Xpos)
	{
		/*The address of the first character is 0x00*/
		local_u8Address = 0x0 + Copy_Ypos;
		/*Second row x=2*/
	}else if (2 == Copy_Xpos)
	{
		/*The address of the first character is 0x40*/
		local_u8Address =  0x40 + Copy_Ypos ;

	}else {/*DO NOTHING*/}

	/*Send DDRAM Address Command*/
	HCLCD_voidSendCmd(local_u8Address+128);

}




void HCLCD_voidWriteSpecialChar(u8 *Copy_pu8CharArr, u8 Copy_u8CharLocation)
{

	u8 local_u8CGRAM_ADD = 0 , local_u8Iterator;
	/*Calculate the CGRAM of the given location*/
	local_u8CGRAM_ADD = Copy_u8CharLocation * 8;
	/*Send CGRAM address command*/
	HCLCD_voidSendCmd(local_u8CGRAM_ADD+64);
	/*Write the special character to the CGRAM*/
	for(local_u8Iterator=0;local_u8Iterator<8;local_u8Iterator++)
	{
		/*Send the bytes of the special character*/
		HCLCD_voidSendData(Copy_pu8CharArr[local_u8Iterator]);

	}

}


void HCLCD_voidDisplaySpecialChar(u8 Copy_u8CharLocation, u8 Copy_u8Xpos, u8 Copy_u8Ypos)
{

	u8 local_u8CGRAM_ADD = 0 ;
	/*Calculate the CGRAM of the given location*/
	local_u8CGRAM_ADD = Copy_u8CharLocation * 8;
	/*Send CGRAM address command*/
	HCLCD_voidSendCmd(local_u8CGRAM_ADD+64);
	/*Send the cursor to X Y position*/
	HCLCD_voidGoToXY(Copy_u8Xpos,Copy_u8Ypos);
	/*Display the character at the given location*/
	HCLCD_voidSendData(Copy_u8CharLocation);

}

void HCLCD_voidSetCursorBlink(void)
{
	/*Send Cursor Blink command*/
	HCLCD_voidSendCmd(0b00001111);
}


void HCLCD_voidShiftDiplayRight(void)
{
	HCLCD_voidSendCmd(0b00011100);
}

void HCLCD_voidShiftDiplayLeft(void)
{
	HCLCD_voidSendCmd(0b00011000);
}



