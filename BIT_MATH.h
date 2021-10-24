#ifndef BIT_MATH_H
#define BIT_MATH_H
#include <avr/io.h>   // this file include all register addresses macros like DDRA
#define F_CPU 16000000UL // set the frequency of microcontroller
#include <util/delay.h> // this header include all delay function like _delay_ms
//#include <avr/interrupt.h> // this header is necessary when you deal with interrupt


#define SET_BIT(VAR,BIT)    ((VAR) |=(1<<(BIT)))
#define TOG_BIT(VAR,BIT)    ((VAR) ^=(1<<(BIT)))
#define CLR_BIT(VAR,BIT)    ((VAR) &=~(1<<(BIT)))
#define GIT_BIT(VAR,BIT)    (((VAR)>>(BIT)) &  1)





#endif