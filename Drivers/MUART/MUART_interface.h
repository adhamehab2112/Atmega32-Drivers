/*
 * MUART_interface.h
 *
 *  Created on: Sep 15, 2022
 *      Author: emad
 */

#ifndef MCAL_MUART_MUART_INTERFACE_H_
#define MCAL_MUART_MUART_INTERFACE_H_

void MUART_voidInit(void);

void MUART_voidSendChar(u8 Copy_u8Data);

void MUART_voidSendString(char *Copy_u8String);

u8 MUART_u8GetChar(void);

#endif /* MCAL_MUART_MUART_INTERFACE_H_ */
