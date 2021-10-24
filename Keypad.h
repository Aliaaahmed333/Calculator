/*
 * Keypad.h
 *
 * Created: 13/09/2021 10:25:20 pm
 *  Author: ALIAA
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define KPD_PORT    PORTD
#define KPD_DIR     DDRD
#define KPD_READ    PIND
#define NUM_COL   4
#define NUM_ROW   4
#define KPD_INIT()   DDRD = 0x0f; PORTD = 0xff; // pull up res 4,5,6,7
#define DELAY_MS(x) _delay_ms(x);

#define COL1(val) if(val == 0)  CLR_BIT(PORTD,0); else   SET_BIT(PORTD,0);
#define COL2(val) if(val == 0)  CLR_BIT(PORTD,1); else   SET_BIT(PORTD,1);
#define COL3(val) if(val == 0)  CLR_BIT(PORTD,2); else   SET_BIT(PORTD,2);
#define COL4(val) if(val == 0)  CLR_BIT(PORTD,3); else   SET_BIT(PORTD,3);
#define ROW1()  GIT_BIT(PIND ,4)
#define ROW2()  GIT_BIT(PIND ,5)
#define ROW3()  GIT_BIT(PIND ,6)
#define ROW4()  GIT_BIT(PIND ,7)

/*******************************************************************
Function Name : Keypad_Init
Purpose       : initalize Keypad pins
parameter     : void
Return Value  : void
*********************************************************************/

void  Keypad_Init ();
/*******************************************************************
Function Name : Keypad_Read
Purpose       : check if one of keypad button is pressed
parameter     : void
Return Value  :  return the button value in case a button is pressed
*                return -1 in case no button pressed
*********************************************************************/

s8  Keypad_Read ();


#endif /* KEYPAD_H_ */