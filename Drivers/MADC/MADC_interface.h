/*
 * MADC_interface.h
 *
 *  Created on: Sep 8, 2022
 *      Author: emad
 */

#ifndef MCAL_MADC_MADC_INTERFACE_H_
#define MCAL_MADC_MADC_INTERFACE_H_

#define ADC_Channel_0            0
#define ADC_Channel_1            1
#define ADC_Channel_2            2
#define ADC_Channel_3            3
#define ADC_Channel_4            4
#define ADC_Channel_5            5
#define ADC_Channel_6            6
#define ADC_Channel_7            7


void MADC_voidInit(void);

u8 MADC_u8ReadChannel(u8 Copy_u8Channel);

#endif /* MCAL_MADC_MADC_INTERFACE_H_ */
