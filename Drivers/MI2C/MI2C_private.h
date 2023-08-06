/*
 * MI2C_private.h
 *
 *  Created on: Sep 17, 2022
 *      Author: emad
 */

#ifndef MCAL_MI2C_MI2C_PRIVATE_H_
#define MCAL_MI2C_MI2C_PRIVATE_H_


#define START_ACK                0x08 // start has been sent
#define REP_START_ACK            0x10 // repeated start

#define SLAVE_ADD_AND_WR_ACK     0x18 // Master transmit ( slave address + Write request ) ACK
#define SLAVE_ADD_AND_WR_NACK    0x20 // Master transmit ( slave address + Write request ) NACK
#define SLAVE_ADD_AND_RD_ACK     0x40 // Master transmit ( slave address + Read request ) ACK
#define WR_BYTE_ACK              0x28 // Master transmit data ACK
#define RD_BYTE_WITH_ACK         0x50 // Master received data with ACK
#define RD_BYTE_WITH_NACK        0x58 // Master received data with not ACK

#define SLAVE_ADD_RCVD_RD_REQ    0xA8 // means that slave address is received with write req
#define SLAVE_ADD_RCVD_WR_REQ    0x60 // means that slave address is received with read req
#define SLAVE_DATA_RECEIVED      0x80 // means that read byte req is received
#define SLAVE_BYTE_TRANSMITTED   0xC0 // means that write byte req is received


/*TWBR Bits*/
#define TWBR0  0
#define TWBR1  1
#define TWBR2  2
#define TWBR3  3
#define TWBR4  4
#define TWBR5  5
#define TWBR6  6
#define TWBR7  7

/*TWCR Bits*/
#define TWIE   0
#define TWEN   2
#define TWWC   3
#define TWSTO  4
#define TWSTA  5
#define TWEA   6
#define TWINT  7

/*TWSR Bits*/
#define TWPS0   0
#define TWPS1    1
#define TWS3    3
#define TWS4    4
#define TWS5    5
#define TWS6    6
#define TWS7    7

#define PRESCALLER_MASK 0xF8

/*TWDR Bits*/
#define TWD0   0
#define TWD1   1
#define TWD2   2
#define TWD3   3
#define TWD4   4
#define TWD5   5
#define TWD6   6
#define TWD7   7


/*TWAR Bits*/
#define TWGCE  0
#define TWA0   1
#define TWA1   2
#define TWA2   3
#define TWA3   4
#define TWA4   5
#define TWA5   6
#define TWA6   7


#define TWCR   (*(volatile u8 *)0x56)
#define TWDR   (*(volatile u8 *)0x23)
#define TWAR   (*(volatile u8 *)0x22)
#define TWSR   (*(volatile u8 *)0x21)
#define TWBR   (*(volatile u8 *)0x20)

#endif /* MCAL_MI2C_MI2C_PRIVATE_H_ */
