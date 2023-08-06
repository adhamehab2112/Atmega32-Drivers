/*
 * MI2C_program.c
 *
 *  Created on: Sep 17, 2022
 *      Author: emad
 */

#include "../../LIB/LIB_STD_TYPES.h"
#include "../../LIB/LIB_BIT_MATH.h"

#include "../../MCAL/MUART/MUART_interface.h"

#include "MI2C_interface.h"
#include "MI2C_private.h"

void MI2C_voidMasterInit(void)
{

	/*Configure Prescaller Bits*/
	CLR_BIT(TWSR, TWPS0);
	CLR_BIT(TWSR, TWPS1);

	/*bit rate = 400.000 kbps, F_CPU = 8M
	 * SCL freq= F_CPU/(16+2(TWBR).4^TWPS)*/
	TWBR = 0x02;

	/*Enable Acknowledge*/
	//SET_BIT(TWCR, TWEA);

	/*Enable TWI*/
	SET_BIT(TWCR, TWEN);

}
void MI2C_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
	/*Set Slave Address*/
	TWAR = (Copy_u8SlaveAddress << 1);
	/*Enable TWI*/
	SET_BIT(TWCR, TWEN);
}

void MI2C_voidStart(void)
{
	/* Put Start Condition on SDA | Clear TWI interrupt flag | Enable TWI */

	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

	while(0 == GET_BIT(TWCR,TWINT))
	{
		/*Wait till start condition is transmitted*/
	}

	/*Check the Start Operation in Status Register*/
	while((TWSR & PRESCALLER_MASK) != START_ACK)
	{
		/*Check for the START_ACK*/
	}


}
void MI2C_voidRepeatedStart(void)
{
	/* Put Repeated Start Condition on SDA | Clear TWI interrupt flag | Enable TWI */

	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

	while(0 == GET_BIT(TWCR,TWINT))
	{
		/*Wait till repeated start condition is transmitted*/
	}
	/*Check the Repeated Start Operation in Status Register*/
	while((TWSR & PRESCALLER_MASK) != REP_START_ACK)
	{
		/*Check for the REP_START_ACK*/
	}
}
void MI2C_voidStop(void)
{
	/* Put Stop Condition on SDA | Clear TWI interrupt flag | Enable TWI */

	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

void MI2C_voidSendSlaveAddress_WriteReq(u8 Copy_u8SlaveAddress)
{


//	MUART_voidSendString("sending add ");
	Copy_u8SlaveAddress = Copy_u8SlaveAddress << 1;

	/*Write Instruction*/
	CLR_BIT(Copy_u8SlaveAddress, 0);

	/*Write Address to Data Register */
	TWDR = Copy_u8SlaveAddress;

	/*Clear TWI interrupt flag*/
	SET_BIT(TWCR,TWINT);
//	CLR_BIT(TWCR,TWSTA);


//	MUART_voidSendChar(Copy_u8SlaveAddress+48);

	while (0 == GET_BIT(TWCR,TWINT))
	{
		// Wait till complete TWDR byte transmitted
	}

//	MUART_voidSendString("sending add  ");
	/*Check the SLA+W Operation in Status Register*/
	while((TWSR & PRESCALLER_MASK) != SLAVE_ADD_AND_WR_ACK)
	{
		/*Check for the acknowledgment*/
	}
//	MUART_voidSendString("   ");
}
void MI2C_voidSendSlaveAddress_ReadReq(u8 Copy_u8SlaveAddress)
{

	Copy_u8SlaveAddress = Copy_u8SlaveAddress << 1;

	/*Read Instruction*/
	SET_BIT(Copy_u8SlaveAddress, 0);

	/*Write Address to Data Register */
	TWDR = Copy_u8SlaveAddress;

	while (0 == GET_BIT(TWCR,TWINT))
	{
		// Wait till complete TWDR byte transmitted
	}
	/*Check the SLA+R Operation in Status Register*/
	while((TWSR & PRESCALLER_MASK) != SLAVE_ADD_AND_RD_ACK)
	{
		/*Check for the acknowledgment*/
	}
}

void MI2C_voidMasterWriteByte(u8 Copy_u8Byte, u8 Copy_u8SLA)
{
	//MUART_voidSendString("  \r");
	//MUART_voidSendString(" Sending Start ... \r");
	/*Send Start Condition*/
	MI2C_voidStart();

//	MUART_voidSendString(" Start Sent \r");
//
//	MUART_voidSendString("  \r");
//
//	MUART_voidSendString(" Sending SLA+W ... \r");
	/*Send Slave Address with Write Request*/
	MI2C_voidSendSlaveAddress_WriteReq(Copy_u8SLA);

	//MUART_voidSendString("     SLA+W Sent \r");

	//MUART_voidSendString("  \r");
	/*Put Data in TWDR*/
	TWDR = Copy_u8Byte;
	/*Clear TWI interrupt flag | Enable TWI*/
	TWCR = (1 << TWINT) | (1 << TWEN);

	while (0 == GET_BIT(TWCR,TWINT))
	{
		// Wait till complete TWDR byte transmitted
	}
	//MUART_voidSendString(" Check SLA+W ACK ... \r");

	/*Check Write Byte with ACK Returned*/
	while((TWSR & PRESCALLER_MASK) != WR_BYTE_ACK)
	{
		/*Check for the WR_BYTE_ACK*/
	}

//	MUART_voidSendString(" SLA+W ACK Checked \r");

//	MUART_voidSendString("  \r");

//	MUART_voidSendString(" Sending Stop ... \r");

	/*Send Stop Condition to End the Frame*/
	MI2C_voidStop();
	//MUART_voidSendString("  Stop Sent \r");

//	MUART_voidSendString("  \r");

}
u8 MI2C_u8MasterReadByte(void)
{


	/*Clear TWI interrupt flag | Enable TWI*/
	TWCR = (1 << TWINT) | (1 << TWEN);

	while (0 == GET_BIT(TWCR,TWINT))
	{
		// Wait till complete TWDR byte transmitted
	}
	/*Check Read Byte with ACK Sent*/
	while((TWSR & PRESCALLER_MASK) != RD_BYTE_WITH_ACK)
	{
		/*Check for the WR_BYTE_ACK*/
	}

	/*Return the Value from the Data Register*/
	return TWDR;
}


void MI2C_voidSlaveWriteByte(u8 Copy_u8Byte)
{


}
u8 MI2C_u8SlaveReadByte(void)
{
	/*Clear TWI interrupt Flag | Enable TWI*/
	TWCR = (1 << TWINT) | (1 << TWEN);

	while (0 == GET_BIT(TWCR,TWINT))
	{
		// Wait till complete TWDR byte transmitted
	}

	while((TWSR & PRESCALLER_MASK) != WR_BYTE_ACK)
	{
		/*Check for the WR_BYTE_ACK*/
	}

	return TWDR;
}















