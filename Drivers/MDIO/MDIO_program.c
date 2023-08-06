/*
 * MDIO_program.c
 *
 *  Created on: Sep 1, 2022
 *      Author: emad
 */

#include "../../LIB/LIB_STD_TYPES.h"
#include "../../LIB/LIB_BIT_MATH.h"

//#include <avr/io.h>
#include "MDIO_interface.h"
#include "MDIO_private.h"
#include "MDIO_config.h"




void MDIO_voidInit()
{
	DDRA  = MDIO_DDRA_DIRECTION;
    DDRB  = MDIO_DDRB_DIRECTION;
    DDRC  = MDIO_DDRC_DIRECTION;
    DDRD  = MDIO_DDRD_DIRECTION;

    PORTA = MDIO_PORTA_VALUE;
    PORTB = MDIO_PORTB_VALUE;
    PORTC = MDIO_PORTC_VALUE;
    PORTD = MDIO_PORTD_VALUE;
}


void MDIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin, u8 Copy_u8Direction)
{
	if((Copy_u8Port <= 3) && (Copy_u8Pin <=7) && (Copy_u8Direction <=1))
	{

		/*Input Direction*/
		if(0 == Copy_u8Direction)
		{
			/*Switch Group Number*/
			switch(Copy_u8Port)
			{
			case 0: CLR_BIT(DDRA,Copy_u8Pin); break;
			case 1: CLR_BIT(DDRB,Copy_u8Pin); break;
			case 2: CLR_BIT(DDRC,Copy_u8Pin); break;
			case 3: CLR_BIT(DDRD,Copy_u8Pin); break;

			}

			/*Output Direction*/
		}else if (1 == Copy_u8Direction)
		{
			/*Switch Group Number*/
			switch(Copy_u8Port)
			{
			case 0: SET_BIT(DDRA,Copy_u8Pin); break;
			case 1: SET_BIT(DDRB,Copy_u8Pin); break;
			case 2: SET_BIT(DDRC,Copy_u8Pin); break;
			case 3: SET_BIT(DDRD,Copy_u8Pin); break;

			}

		}else{/*DO NOTHING*/}


	}else{
		/*DO NOTHING*/
	}

}


void MDIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	if((Copy_u8Port <= 3) && (Copy_u8Pin <=7) && (Copy_u8Value <=1))
	{

		/*Low Value*/
		if(0 == Copy_u8Value)
		{
			/*Switch Group Number*/
			switch(Copy_u8Port)
			{
			case 0: CLR_BIT(PORTA,Copy_u8Pin); break;
			case 1: CLR_BIT(PORTB,Copy_u8Pin); break;
			case 2: CLR_BIT(PORTC,Copy_u8Pin); break;
			case 3: CLR_BIT(PORTD,Copy_u8Pin); break;

			}

			/*High Value*/
		}else if (1 == Copy_u8Value)
		{
			/*Switch Group Number*/
			switch(Copy_u8Port)
			{
			case 0: SET_BIT(PORTA,Copy_u8Pin); break;
			case 1: SET_BIT(PORTB,Copy_u8Pin); break;
			case 2: SET_BIT(PORTC,Copy_u8Pin); break;
			case 3: SET_BIT(PORTD,Copy_u8Pin); break;

			}

		}else{/*DO NOTHING*/}


	}else{
		/*DO NOTHING*/
	}


}

u8  MDIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 local_u8PinValue;

	if(Copy_u8Port <=3  && Copy_u8Pin <=7)
	{

		switch(Copy_u8Port)
		{
			case MDIO_PORTA: local_u8PinValue = GET_BIT(PINA, Copy_u8Pin); break;
			case MDIO_PORTB: local_u8PinValue = GET_BIT(PINB, Copy_u8Pin); break;
			case MDIO_PORTC: local_u8PinValue = GET_BIT(PINC, Copy_u8Pin); break;
			case MDIO_PORTD: local_u8PinValue = GET_BIT(PIND, Copy_u8Pin); break;
		}


	}else{/*DO NOTHING*/}

	return local_u8PinValue;
	
}


void MDIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
	if(Copy_u8Port <= 3)
	{

		/*Input Direction*/
		if(0 == Copy_u8Direction)
		{
			/*Switch Group Number*/
			switch(Copy_u8Port)
			{
			case 0: DDRA = 0; break;
			case 1: DDRB = 0; break;
			case 2: DDRC = 0; break;
			case 3: DDRD = 0; break;

			}

			/*Output Direction*/
		}else if (1 == Copy_u8Direction)
		{
			/*Switch Group Number*/
			switch(Copy_u8Port)
			{
			case 0: DDRA = 255; break;
			case 1: DDRB = 255; break;
			case 2: DDRC = 255; break;
			case 3: DDRD = 255; break;

			}
		}
	
	}else{/*DO NOTHING*/}
}


void MDIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
	if(Copy_u8Port <= 3)
	{
		
		switch(Copy_u8Port)
		{
		case 0: PORTA = Copy_u8Value; break;
		case 1: PORTB = Copy_u8Value; break;
		case 2: PORTC = Copy_u8Value; break;
		case 3: PORTD = Copy_u8Value; break;

		}
	
	}else{/*DO NOTHING*/}

}


u8 MDIO_u8GetPortValue(u8 Copy_u8Port)
{
	u8 local_u8PortValue;

	if(Copy_u8Port <=3)
	{

		switch(Copy_u8Port)
		{
			case 0: local_u8PortValue = PINA; break;
			case 1: local_u8PortValue = PINB; break;
			case 2: local_u8PortValue = PINC; break;
			case 3: local_u8PortValue = PIND; break;
		}


	}else{/*DO NOTHING*/}

	return local_u8PortValue;
}







