/*
 * MWDT_private.h
 *
 *  Created on: Sep 14, 2022
 *      Author: emad
 */

#ifndef MCAL_MWDT_MWDT_PRIVATE_H_
#define MCAL_MWDT_MWDT_PRIVATE_H_

#define WDTCR				*((volatile u8*)0x41)

#define WDTCR_WDTOE			4
#define WDTCR_WDE			3

#endif /* MCAL_MWDT_MWDT_PRIVATE_H_ */
