/*
 * MDIO_program.c
 *
 *  Created on: Sep 8, 2022
 *      Author: emad
 */

#include "../../LIB/LIB_STD_TYPES.h"
#include "../../LIB/LIB_BIT_MATH.h"

#include "MADC_private.h"
#include "MADC_interface.h"

void MADC_voidInit(void)
{
	/*AVCC as reference voltage 01 */
	CLR_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);


	/*activate left adjust result*/
	SET_BIT(ADMUX,ADMUX_ADLAR);

    /*set prescaler to divided by 128*/
    SET_BIT(ADCSRA,ADCSRA_ADPS2);
    SET_BIT(ADCSRA,ADCSRA_ADPS1);
    SET_BIT(ADCSRA,ADCSRA_ADPS0);

	/*ENABLE ADC */
	SET_BIT(ADCSRA,ADCSRA_ADEN);

}

u8 MADC_u8ReadChannel(u8 Copy_u8Channel)
{

	/*clear the MUX bits in ADMUX register*/
	ADMUX &= ADMUX_MASK;

	/*set the required channel into the MUX bits*/
	ADMUX |= Copy_u8Channel;

	/* start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	/*pooling (busy waiting) until the conversion complete flag is set*/
	while((GET_BIT(ADCSRA,ADCSRA_ADIF))==0)
	{
		/*pooling (busy waiting) until the conversion complete flag is set*/
	}

	/*clear the conversion complete flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);

	/*return the reading*/
	return ADCH;


}

