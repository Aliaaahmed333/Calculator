/*
 * lcd.c
 *
 * Created: 04/09/2021 11:24:36 am
 *  Author: ALIAA
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "lcd.h"
/*******************************************************************
Function Name : LCD_Init
Purpose       : Initalize lcd to make it work at 4_bit mode
parameter     : void
Return Value  : void
*********************************************************************/
void LCD_Init (void)
{
	 LCD_INIT_PINS();

	 LCD_Write_Comd(0x2); // enable 4 bit mode 
	 LCD_Write_Comd(0x28); // function set
	  DELAY_MS(1);
	 LCD_Write_Comd(0x0C); //Display ON/OFF Control
	   DELAY_MS(1);
	 LCD_Write_Comd(0x01); //Display Clear
	   DELAY_MS(3);
    LCD_Write_Comd(0x06); //Display entry mode (make curser increment to right)
	  DELAY_MS(3);
}

/*******************************************************************
Function Name : LCD_Write_Comd
Purpose       : to make lcd do aspecific command from datasheet
parameter     : comd
Return Value  : void
*********************************************************************/
void LCD_Write_Comd (u8 comd)
{
	RS(0);
	DELAY_MS(1);
	D7(GIT_BIT(comd,7));
	D6(GIT_BIT(comd,6));
	D5(GIT_BIT(comd,5));
	D4(GIT_BIT(comd,4));
	TRIGGER_LCD() ;
	D7(GIT_BIT(comd,3));
	D6(GIT_BIT(comd,2));
	D5(GIT_BIT(comd,1));
	D4(GIT_BIT(comd,0));
	TRIGGER_LCD() ;
}

/*******************************************************************
Function Name : LCD_Write_Char
Purpose       : to make lcd display only one char on screen by using 
                4_bit_mode 
parameter     : data
Return Value  : void
*********************************************************************/
void LCD_Write_Char (u8 data)
{
	RS(1);
	DELAY_MS(1);
   D7(GIT_BIT(data,7));     
   D6(GIT_BIT(data,6));
   D5(GIT_BIT(data,5));
   D4(GIT_BIT(data,4));
   TRIGGER_LCD() ;
   
  D7(GIT_BIT(data,3));
  D6(GIT_BIT(data,2));
  D5(GIT_BIT(data,1));
  D4(GIT_BIT(data,0));
  TRIGGER_LCD() ;	
	
}

/*******************************************************************
Function Name : LCD_Write_String
Purpose       : to make lcd display a text on lcd by using
                4_bit_mode
parameter     : pointer to text(*text)
Return Value  : void
*********************************************************************/
void LCD_Write_String (u8 * text)
{
	u8 i = 0;
	while (text[i] != '\0')
	{
		LCD_Write_Char(text[i]);
		i++;
	}
	
}

/*******************************************************************
Function Name : LCD_Write_Number
Purpose       : to make lcd display a number on lcd  and this number contain 
                one more digit by using  4_bit_mode 
parameter     : pointer to text(*text)
Return Value  : void
*********************************************************************/
void LCD_Write_Number (s32 number)
{
	u8 arr[12]	;
	s8 index = 0;
	if (number != 0)
	{
		while (number != 0)
		{
			arr[index] = number%10;
			number/=10;
			index++;
		}
		index --;
		for (s8 i = index; i >= 0; i--) 
		{
			LCD_Write_Char(arr[i]+'0');
		}
	}
	else 
	{
		LCD_Write_Char('0');
	}
}

/*******************************************************************
Function Name : LCD_Set_Cursor 
Purpose       : to make lcd display on line1 , lin2 and move in 
                col0 ----> col_15 using  4_bit_mode 
parameter     : pointer to text(*text)
Return Value  : void
*********************************************************************/
void LCD_Set_Cursor (u8 line , u8 col)
{
	if (col >= 0 && col < 16)
	{
		if (line == LCD_LINE_1)
		{
			LCD_Write_Comd(LCD_LINE_1 + col);
		}
		 else if (line == LCD_LINE_2)
		 {
			 LCD_Write_Comd(LCD_LINE_2 + col); 
		 }
	}
	
	
}