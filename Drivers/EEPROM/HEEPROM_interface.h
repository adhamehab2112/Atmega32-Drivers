/*
 * HEEPROM_interface.h
 *
 *  Created on: Sep 19, 2022
 *      Author: PC
 */

#ifndef HAL_EEPROM_HEEPROM_INTERFACE_H_
#define HAL_EEPROM_HEEPROM_INTERFACE_H_

void HEEprom_voidWrite_Data(u8 copy_u8Data , u8 copyy_u8PA , u8 copy_u8BA);
void MI2C_voidSend_BYTE_Address_WriteReq(u8 Copy_u8BYTE_Address);

#endif /* HAL_EEPROM_HEEPROM_INTERFACE_H_ */
