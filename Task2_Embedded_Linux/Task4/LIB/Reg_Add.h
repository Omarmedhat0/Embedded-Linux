/*
 ============================================================================
 Name        : DIO_Reg_Add.h
 Author      : Omar Medhat Mohamed
 Description : Header file for register addresses
 Date        : 27/11/2023
 ============================================================================
 */

#ifndef Reg_Add_H_
#define Reg_Add_H_
#include "std_types.h"

#define DDRA *((uint8 *)0x3A)
#define DDRB *((uint8 *)0x37)
#define DDRC *((uint8 *)0x34)
#define DDRD *((uint8 *)0x31)

#define PORTA *((uint8 *)0x3B)
#define PORTB *((uint8 *)0x38)
#define PORTC *((uint8 *)0x35)
#define PORTD *((uint8 *)0x32)

#define PINA *((uint8 *)0x39)
#define PINB *((uint8 *)0x36)
#define PINC *((uint8 *)0x33)
#define PIND *((uint8 *)0x30)

#endif /*Reg_Add_H_ */
