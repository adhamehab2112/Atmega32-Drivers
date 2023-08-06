/*
 * LMACROS.h
 *
 *  Created on: May 14, 2022
 *      Author: Emad Yousry
 */

#ifndef LMACROS_H_
#define LMACROS_H_

/* Set the value of a certain pin in certain register to HIGH */
#define SET_BIT(REG,BIT_NO)    (REG)|= (1 << BIT_NO)
/* Set the value of a certain pin in certain register to LOW */
#define CLR_BIT(REG,BIT_NO)    (REG)&= ~(1 << BIT_NO)
/* Set the value of a certain register */
#define SET_REG(REG,VAL)       (REG)|= (VAL)
/* Toggle the value of a certain pin in certain port (HIGH--> LOW) OR (LOW --> HIGH)  */
#define TOGGLE_BIT(REG,BIT_NO) (REG)^= (1 << BIT_NO)
/* Get the value of a certain pin in certain port (HIGH/LOW) */
#define GET_BIT(REG,BIT_NO)    ((REG&(1<<BIT_NO))>>BIT_NO)


#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7

#define OK  0
#define NOK 1

#endif /* LMACROS_H_ */
