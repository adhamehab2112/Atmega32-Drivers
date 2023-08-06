/*
 * MI2C_interface.h
 *
 *  Created on: Sep 17, 2022
 *      Author: emad
 */

#ifndef MCAL_MI2C_MI2C_INTERFACE_H_
#define MCAL_MI2C_MI2C_INTERFACE_H_

void MI2C_voidMasterInit(void);
void MI2C_voidSlaveInit(u8 Copy_u8SlaveAddress);

void MI2C_voidStart(void);
void MI2C_voidRepeatedStart(void);
void MI2C_voidStop(void);

void MI2C_voidSendSlaveAddress_WriteReq(u8 Copy_u8SlaveAddress);
void MI2C_voidSendSlaveAddress_ReadReq(u8 Copy_u8SlaveAddress);

void MI2C_voidSendSlaveData(u8 Copy_u8SlaveData);
u8 MI2C_u8GetSlaveData(void);

void MI2C_voidMasterWriteByte(u8 Copy_u8Byte, u8 Copy_u8SLA);
u8 MI2C_u8MasterReadByte(void);

/*
void MI2C_voidSlaveWriteByte(u8 Copy_u8Byte);
u8 MI2C_u8SlaveReadByte(void);

void MI2C_voidslave_check_slave_address_received_with_write_req(void);
void MI2C_voidslave_check_slave_address_received_with_read_req(void);

u8 MI2C_u8slave_read_byte(void);
void MI2C_voidslave_write_byte(u8 byte);
*/
#endif /* MCAL_MI2C_MI2C_INTERFACE_H_ */
