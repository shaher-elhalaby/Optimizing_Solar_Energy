/*
 * LCD.h
 *
 * Created: 7/3/2019 6:50:24 PM
 *  Author: shaher
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "MACROSH.h"
#include "MC_Config.h"
#include "StandardTypes.h"
#include <avr/io.h>
#include <stdlib.h>


/* Ports Configuration Defination */
#define LCD_Control_DIR  DDRC
#define LCD_Control_OP   PORTC
#define LCD_Control_PIN  PINC

#define LCD_Data_DIR    DDRC
#define LCD_Data_OP     PORTC
#define LCD_Data_PIN    PINC

#define RS  2
#define RW  
#define E   3

/***************************************/

/* Instruction Set */
#define Display_Clear           0x01
#define Return_Home             0x02
#define Display_OFF             0x08
#define Display_ON              0x0c |((Cursor)<<1) | ((Blink))
#define Display_Shift_Left      0x18
#define Display_shift_Right     0x1c
#define Cursor_Shift_Right	    0x14
#define Cursor_Shift_left	    0x10
#define Function_Set            0x20 | ((Eight_Bit)<<4) | ((Two_Lines)<<3) | ((_5x10Dots)<<2) /*what the meaning of two lines*/
#define DDRAM                   0x80
#define CGRAM                   0x40

#define LCD_1ST_Base            0x00 /*how to get?*/
#define LCD_2ND_Base            0x40
#define LCD_3RD_Base            0x10
#define LCD_4TH_Base            0x50

/**************************************/

/*LCD Config */
#define Cursor      0
#define Blink       0
#define Eight_Bit   0
#define Two_Lines   1
#define _5x10Dots   0

#define LCD_Left    1
#define LCD_Right   0

#define LCD_DIR(DIR)         ((DIR == LCD_Left) ? Send_Instruction(Display_Shift_Left) : Send_Instruction( Display_shift_Right ))
#define Cursor_DIR(DIR)      ((DIR == LCD_Left) ? Send_Instruction( Cursor_Shift_left) : Send_Instruction( Cursor_Shift_Right ))
    /*?*/
/**************************************/

/*When Using Upper Data Port DB4->DB7*/
#define Upper_Data_Port  1

/**************************************/

/* Function Set*/

void LCD_INIT(void);
void Send_Instruction(uint8 Instruction);
void LCD_Send_Char(uint8 Data);
void LCD_Send_String(uint8 * ptr);
void LCD_RowCol(uint8 Row ,uint8 Col);
void LCD_Clear(void);
void LCD_DisplayInt(sint32 data);

/**************************************/

#endif /* LCD_H_ */