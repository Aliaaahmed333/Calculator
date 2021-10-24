/*
 * cal.c
 *
 * Created: 30/09/2021 06:47:20 م
 * Author : ALIAA
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "lcd.h"
#include "Keypad.h"

volatile s8 key = -1;
int main(void)
{
	u8 arr[16] ;
	u8 buf [10];
	s32 num2 = 0;
	f32 res, num1 = 0;
	u8 c = 0, operand = 0, flag = 0,  copy_val = 0,check = 0;
	s8 index = 0;
	
	LCD_Init();
	Keypad_Init();
   /* starting calculate */
	LCD_Write_String("Simple Calculate ");
	_delay_ms(400);
	LCD_Write_Comd(LCD_CLEAR_SCREEN);
   while(1)
    {
	  /* if i don't press any key don't increment index of array */
		while(Keypad_Read() == -1);
		key = Keypad_Read();
		if (key != -1) 
		{
			arr[index] = key; /* save key i press in array */
			if (arr[index] < 10) /* if i press number from 0 to 9 */
			{
				LCD_Write_Number(arr[index]);
			/* loop to prevent number print more time in lcd  and waiting to press another key*/
				while(Keypad_Read() != -1); 
			}
			else /* if press char not number eg (+,-,*,/) */
			{
			/* if i want to clear screen to do another calculation */
				if (arr[index] == 'A') {
					flag = 0;
					num1 = 0;
					num2 = 0;
					index = -1;
					c = 0;
					LCD_Write_Comd(LCD_CLEAR_SCREEN);
				}
				else {
				LCD_Write_Char(arr[index]);
			/* loop to prevent number print more time in lcd  and waiting to press another key*/
				while(Keypad_Read() != -1);
					if (arr[index] == '='){
					copy_val = index;
					index = -1; 
					for (u8 j = 0; j < copy_val ; j++){ /* loop in array which  save key i press */
						if (arr[j] > 10){ /* if arr[j] is character eg *,+,/,-  */
							operand = arr[j];
				/* check threre is syntax error or not like ++,+*,+/ */
						if (arr[j+1] > 10 && (arr[j+1] == '+' || arr[j+1] == '*' || arr[j+1] == '/')){
							    LCD_Set_Cursor(LCD_LINE_2,2);
								LCD_Write_String("syntax error");
								check = 1; /* to check if there is syntax error or not and breek from loop */
								break;
							}
						
	          /* if theres is no syntax error  */
	                  else{
						  flag++;
			  /* if theres is one operation in array like (15 + 44)   */
					if (flag < 2 && operand != '=' ){
			 /* this loop happen for one time in the first operation to calculate num1 */
						for (s8 i = j-1; i >= 0 ; i--) 
						{
			/* example 15 = 5* pow (10,0) = 5 , 5+ 1*pow(10,1) = 15 */
							num1 += arr[i] * pow(10,c);
							c++;	
						}
											
						c = 0; /* return it 0 to count again */
						u8 x = j+1;
			/* tis loop start from number and break if there is '=' or another operand to count digit of num2 */
						while (arr[x] < 10)
						{
							c++;
							x++; 
						}
						x = j+1;
						c--;
						/* to calculate num2  */
						while (arr[x] < 10)
						{
							num2 += arr[x] * pow(10,c);
							c--;
							x++;
						}
						/* calculate res */
						switch(operand){
							case '+' : res = num1 + num2; break;
							case '-' : res = num1 - num2; break;
							case '*' : res = num1 * num2; break;
							case '/' : res = num1 / num2; break;
						}
					} // end if (flag < 2 && operand != '=' )  
				
		/* this condition to check if there is more operation i want to do like (15 + 5 / 2 = )  
		by make res of operation is num1 of after operation */
					else{
						num1 = res; 
						num2 = 0;
						c = 0;
						u8 x = j+1;
						/* to count digit of num2 */
						while (arr[x] < 10)
						{
							c++;
							x++;
						}
						c--;
						x = j+1;
						/* calculate num2 */
						while (arr[x] < 10)
						{
							num2 += arr[x] *  pow(10,c);
							c--;
							x++;
						}
						
						switch(operand)
						{
							case '+' : res = num1 + num2; break;
							case '-' : res = num1 - num2; break;
							case '*' : res = num1 * num2; break;
							case '/' : res = num1 / num2; break;
						}
					  }// end of there is more operation i need to do  
					  } // else if there is no syntax error 
					}// end of if (arr[j] >10) is character 
				}// end of loop save keys i press 
	               /* if theres is no syntax error and no print last result */
					 if ( !check ){
					 LCD_Set_Cursor(LCD_LINE_2,2);
					   /* this to print floating number */
					  sprintf (buf, "%f", res);
					  LCD_Write_String(buf);
					 }
			 }// end of if (arr[index] == '=')
		  } // end of else i don't press of reset calculator 
		 } // end of if (arr[index] > 10)is char 
	   } // end of if (key != -1);
		index++;
			
    }
}

