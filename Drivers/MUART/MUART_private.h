/*
 * MUART_private.h
 *
 *  Created on: Sep 15, 2022
 *      Author: emad
 */

#ifndef MCAL_MUART_MUART_PRIVATE_H_
#define MCAL_MUART_MUART_PRIVATE_H_

#define UDR     (*(volatile u8 *)0x2C)
#define UCSRA   (*(volatile u8 *)0x2B)
#define UCSRB   (*(volatile u8 *)0x2A)
#define UCSRC   (*(volatile u8 *)0x40)
#define UBRRH   (*(volatile u8 *)0x40)
#define UBRRL   (*(volatile u8 *)0x29)



#define NO_PARITY    1
#define ENEV_PARITY  2
#define ODD_PARITY   3


#define TRANSIMITTER

#endif /* MCAL_MUART_MUART_PRIVATE_H_ */
