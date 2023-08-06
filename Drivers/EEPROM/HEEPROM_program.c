/*
 * HEEPROM_program.c
 *
 *  Created on: Sep 19, 2022
 *      Author: PC
 */

#include "../../MCAL/MI2C/MI2C_interface.h"
#include "../../MCAL/MI2C/MI2C_interface.h"
#include "../../MCAL/MI2C/MI2C_private.h"

void HEEprom_voidWrite_Data(u8 copy_u8Data , u8 copyy_u8PA , u8 copy_u8BA)
{

	MI2C_voidStart();

	MI2C_voidSendSlaveAddress_WriteReq(copyy_u8PA);





}
