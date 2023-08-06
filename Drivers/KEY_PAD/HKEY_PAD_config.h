/*
 * HKEY_PAD_config.h
 *
 *  Created on: Sep 5, 2022
 *      Author: emad
 */

#ifndef HAL_HKEY_PAD_CONFIG_H_
#define HAL_HKEY_PAD_CONFIG_H_

#define HKYP_PORT     MDIO_PORTA

#define KYP_ARR {{7,8,9},{4,5,6},{1,2,3},{0,0,0}}

#define HKYP_NOT_PRESSED  255

#define HKYP_ROWS_OFFSET  4
#define HKYP_ROWS_NOM     4

#define HKYP_COLS_OFFSET  0
#define HKYP_COLS_NOM     3


#endif /* HAL_HKEY_PAD_CONFIG_H_ */
