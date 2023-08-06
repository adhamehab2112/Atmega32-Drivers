/*
 * MDIO_interface.h
 *
 *  Created on: Sep 1, 2022
 *      Author: emad
 */

#ifndef MCAL_MDIO_INTERFACE_H_
#define MCAL_MDIO_INTERFACE_H_


#define MDIO_PORTA          0
#define MDIO_PORTB          1
#define MDIO_PORTC          2
#define MDIO_PORTD          3



#define MDIO_PIN0           0
#define MDIO_PIN1           1
#define MDIO_PIN2           2
#define MDIO_PIN3           3
#define MDIO_PIN4           4
#define MDIO_PIN5           5
#define MDIO_PIN6           6
#define MDIO_PIN7           7



#define  MDIO_PIN_OUTPUT   1
#define  MDIO_PIN_INPUT    0

#define  MDIO_PIN_HIGH     1
#define  MDIO_PIN_LOW      0





void MDIO_voidInit();

void MDIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin, u8 Copy_u8Direction);


void MDIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);


u8  MDIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);


void MDIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);


void MDIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);


u8 MDIO_u8GetPortValue(u8 Copy_u8Port);




#endif /* MCAL_MDIO_INTERFACE_H_ */
