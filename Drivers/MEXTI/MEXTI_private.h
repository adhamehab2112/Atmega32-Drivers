/*
 * MEXTI_private.h
 *
 *  Created on: Sep 7, 2022
 *      Author: emad
 */

#ifndef MCAL_MEXTI_MEXTI_PRIVATE_H_
#define MCAL_MEXTI_MEXTI_PRIVATE_H_


#define I_BIT    7
#define INT1     7

#define SC10     2
#define SC11     3



#define SREG     (*(volatile u8 *)0x5F)

#define MCUCR    (*(volatile u8 *)0x55)
#define MCUCSR   (*(volatile u8 *)0x54)
#define GICR     (*(volatile u8 *)0x5B)
#define GIFR     (*(volatile u8 *)0x5A)

#endif /* MCAL_MEXTI_MEXTI_PRIVATE_H_ */
