/*
 * Keypad.c
 *
 * Created: 13/09/2021 10:24:56 م
 *  Author: ALIAA
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Keypad.h"
const u8 keypad_matrix[] = {
	 7,8,9,'/',
	 4,5,6,'*',
	1,2,3,'-',
    'A',0,'=','+'
};

void  Keypad_Init ()
{
	KPD_INIT();
	
}

s8  Keypad_Read ()
{
	/*
	u8 col , row;
	for ( col = 0; col < NUM_COL; col++)
	{ 
		CLR_BIT(PORTD , col);
		for ( row = 0; row < NUM_ROW ; row++)
		{
			if (GIT_BIT(PIND , (row+4)) == 0)
			{
				 return keypad_matrix[(col+ 4*row)];
			}
		
		 while (GIT_BIT(KPD_PORT , (row+4)) == 0); 
		 _delay_ms(20);
		}
		SET_BIT(PORTD , col);
	}
*/
	u8 i; 
	for(i = 0; i < 4; i++){
		switch(i){
			case 0: COL1(0); COL2(1);COL3(1); COL4(1); break;
			case 1: COL1(1); COL2(0);COL3(1); COL4(1); break;
			case 2: COL1(1); COL2(1);COL3(0); COL4(1); break;
			case 3: COL1(1); COL2(1);COL3(1); COL4(0); break;
		}

		if(ROW1() == 0) return keypad_matrix[i+ 4*0];
		if(ROW2() == 0) return keypad_matrix[i+4*1];
		if(ROW3() == 0) return keypad_matrix[i+4*2];
		if(ROW4() == 0) return keypad_matrix[i+4*3];
		
		DELAY_MS(1);
	}
	
	return -1;
	
	
}