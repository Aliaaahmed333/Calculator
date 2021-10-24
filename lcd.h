/*
 * lcd.h
 *
 * Created: 04/09/2021 11:24:14 ص
 *  Author: ALIAA
 */ 


#ifndef LCD_H_
#define LCD_H_

/*
D7 PORTA  PIN7
D6 PORTA  PIN6
D5 PORTA  PIN5
D4 PORTA  PIN4
RS PORTA  PIN3
EN PORTA  PIN2
*/
#define LCD_INIT_PINS()  DDRA |= 0b11111100;  PORTA &= 0b00000011;
                       
#define D7(VAL)  if (VAL == 0) CLR_BIT(PORTA ,7); else  SET_BIT(PORTA,7);
#define D6(VAL)  if (VAL == 0) CLR_BIT(PORTA ,6); else  SET_BIT(PORTA,6);
#define D5(VAL)  if (VAL == 0) CLR_BIT(PORTA ,5); else  SET_BIT(PORTA,5);
#define D4(VAL)  if (VAL == 0) CLR_BIT(PORTA ,4); else  SET_BIT(PORTA,4);
#define RS(VAL)  if (VAL == 0) CLR_BIT(PORTA ,3); else  SET_BIT(PORTA,3);
#define EN(VAL)  if (VAL == 0) CLR_BIT(PORTA ,2); else  SET_BIT(PORTA,2);   

#define TRIGGER_LCD() EN(1); _delay_ms(1); EN(0); _delay_ms(1);
#define DELAY_MS(x) _delay_ms(x);    
#define LCD_LINE_1   0x80
#define LCD_LINE_2   0xC0
#define LCD_CLEAR_SCREEN   0x01
 
       
/*******************************************************************
Function Name : LCD_Init 
Purpose       : initalize lcd to make it work at 4_bit mode 
parameter     : void
Return Value  : void
*********************************************************************/
void LCD_Init (void);
/*******************************************************************
Function Name : LCD_Write_Comd
Purpose       : to make lcd do aspecific command from datasheet
parameter     : comd
Return Value  : void
*********************************************************************/
void LCD_Write_Comd (u8 comd);
/*******************************************************************
Function Name : LCD_Write_Char
Purpose       : to make lcd display only one char on screen by using 
                4_bit_mode 
parameter     : data
Return Value  : void
*********************************************************************/
void LCD_Write_Char (u8 data);
/*******************************************************************
Function Name : LCD_Write_String
Purpose       : to make lcd display a text on lcd by using 
                4_bit_mode 
parameter     : pointer to text(*text)
Return Value  : void
*********************************************************************/
void LCD_Write_String (u8 * text);
/*******************************************************************
Function Name : LCD_Write_Number
Purpose       : to make lcd display a number on lcd  and this number contain 
                one more digit by using  4_bit_mode 
parameter     : pointer to text(*text)
Return Value  : void
*********************************************************************/
void LCD_Write_Number (s32 number);
/*******************************************************************
Function Name : LCD_Set_Cursor 
Purpose       : to make lcd display on line1 , lin2 and move in 
                col0 ----> col_15 using  4_bit_mode 
parameter     : pointer to text(*text)
Return Value  : void
*********************************************************************/
void LCD_Set_Cursor (u8 line , u8 col);
#endif /* LCD_H_ */