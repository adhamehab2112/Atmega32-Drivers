/*
 * HCLCD_interface.h
 *
 *  Created on: Sep 4, 2022
 *      Author: emad
 */

#ifndef HAL_HCLCD_INTERFACE_H_
#define HAL_HCLCD_INTERFACE_H_


void HCLCD_voidInit(void);

void HCLCD_voidSendCmd(u8 Copy_u8Cmd);

void HCLCD_voidSendData(u8 Copy_u8Data);

void HCLCD_voidWriteChar(u8 Copy_u8Char);

void HCLCD_voidWriteString(u8 *Copy_u8String);

void HCLCD_voidWriteNumber(u32 Copy_u8Number, u8 Copy_u8Xpos, u8 Copy_u8Ypos);

void HCLCD_voidGoToXY(u8 Copy_Xpos, u8 Copy_Ypos);

void HCLCD_voidWriteSpecialChar(u8 *Copy_pu8CharArr, u8 Copy_u8CharLocation);

void HCLCD_voidDisplaySpecialChar(u8 Copy_u8CharLocation, u8 Copy_u8Xpos, u8 Copy_u8Ypos);

void HCLCD_voidSetCursorBlink(void);

void HCLCD_voidShiftDiplayRight(void);

void HCLCD_voidShiftDiplayLeft(void);


#endif /* HAL_HCLCD_INTERFACE_H_ */
