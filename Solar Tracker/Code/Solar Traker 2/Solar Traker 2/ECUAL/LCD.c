/*
 * LCD.c
 *
 * Created: 7/3/2019 6:50:35 PM
 *  Author: shaher
 */ 

#include "LCD.h"

void LCD_INIT(void)
{
	LCD_Control_DIR |=(1<<RS) |(1<<E);
   
    #if Eight_Bit
	   
	   LCD_Data_DIR =0xFF;
	   
	#else
	   #if Upper_Data_Port
	   
	   LCD_Data_DIR |=(0xF0);
	   
	   #else
	   
	   LCD_Data_DIR |=(0x0F);

       #endif
	  
	#endif
	Send_Instruction(Return_Home); /*what the heal is that?*/
	Send_Instruction(Function_Set);
	Send_Instruction(Display_ON);
	Send_Instruction(Display_Clear);
	
}

void Send_Instruction(uint8 Instruction)
{
	Clear_Bit(LCD_Control_OP,RS);
	//Clear_Bit(LCD_Control_OP,RW);
	
	Set_Bit(LCD_Control_OP,E);
	_delay_ms(1);
	
	#if Eight_Bit
	   LCD_Data_OP=Instruction;
	   _delay_ms(1);
	   Clear_Bit(LCD_Control_OP,E);
	   _delay_ms(1);
	#else
	   #if Upper_Data_Port
	      LCD_Data_OP &=(0x0F); 
		  LCD_Data_OP|=(Instruction &(0xF0));
		  _delay_ms(1);
		  
		  Clear_Bit(LCD_Control_OP,E);
		  _delay_ms(1);
		  
		  Set_Bit(LCD_Control_OP,E);
		  _delay_ms(1);
		  
		  LCD_Data_OP &= (0x0F);
		  LCD_Data_OP|=((Instruction )<<4);
		  _delay_ms(1);
		  
		  Clear_Bit(LCD_Control_OP,E);
		  _delay_ms(1);
		#else
		  LCD_Data_OP &= (0xF0);
		  LCD_Data_OP|=(Instruction &(0x0F));
		  _delay_ms(1);
		  
		  Clear_Bit(LCD_Control_OP,E);
		  _delay_ms(1);
		  
		  Set_Bit(LCD_Control_OP,E);
		  _delay_ms(1);
		  
		  LCD_Data_OP &= (0xF0);
		  LCD_Data_OP|=((Instruction )>>4);
		  _delay_ms(1);
		  
		  Clear_Bit(LCD_Control_OP,E);
		  _delay_ms(1);  

       #endif   

    #endif
}

void LCD_Send_Char(uint8 Data)
{
	Set_Bit(LCD_Control_OP,RS);
	//Clear_Bit(LCD_Control_OP,RW);
	
	Set_Bit(LCD_Control_OP,E);
	_delay_ms(1);
	
	 #if Eight_Bit
	      LCD_Data_OP=Data;
	      _delay_ms(1);
	      Clear_Bit(LCD_Control_OP,E);
	      _delay_ms(1);
	 #else
	    #if Upper_Data_Port
	    LCD_Data_OP &= (0x0F) ;
		LCD_Data_OP|=(Data &(0xF0));
	    _delay_ms(1);
	
	    Clear_Bit(LCD_Control_OP,E);
	    _delay_ms(1);
	
	    Set_Bit(LCD_Control_OP,E);
	    _delay_ms(1);
	
	    LCD_Data_OP &=(0x0F);
		LCD_Data_OP|=((Data )<<4);
	    _delay_ms(1);
	
	    Clear_Bit(LCD_Control_OP,E);
	    _delay_ms(1);
		
	    #else
		
	     LCD_Data_OP &= (0xF0);
	     LCD_Data_OP|=(Data &(0x0F));
	     _delay_ms(1);
	
	     Clear_Bit(LCD_Control_OP,E);
	     _delay_ms(1);
	
	     Set_Bit(LCD_Control_OP,E);
	     _delay_ms(1);
	
	     LCD_Data_OP &= (0xF0);
		 LCD_Data_OP|=((Data )>>4);
	     _delay_ms(1);
	
	     Clear_Bit(LCD_Control_OP,E);
	     _delay_ms(1);

	    #endif

    #endif
}

void LCD_Send_String(uint8 * ptr)
{
	while (* ptr !='\0')
	{
		LCD_Send_Char(*ptr);
		ptr++;
	}
}

void LCD_Clear(void)
{
	Send_Instruction(Display_Clear);
}

void LCD_RowCol(uint8 Row ,uint8 Col)
{
	uint8 Address=0;
	
	switch (Row)
	{
		case 0:
		   Address=Col+LCD_1ST_Base;
		   break;
		case 1:
		   Address=Col+LCD_2ND_Base;
		   break;
		case 2:
		   Address=Col+LCD_3RD_Base;
		   break;
		case 3:
		   Address=Col+LCD_4TH_Base;
		   break;
		default:
		   return;         
	}
	Send_Instruction(DDRAM|Address);
}
void LCD_DisplayInt(sint32 data)
{
	/* String to hold the ascii result */
	char Result[17];
	/* 10 for decimal */
	itoa(data,Result,10);
	/* Display The Result */
	LCD_Send_String(Result);
}