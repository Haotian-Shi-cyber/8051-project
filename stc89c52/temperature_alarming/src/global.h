#ifndef _GLOBAL_H
#define _GLOBAL_H
#include "8051.h"

__sbit __at (0xB1) SET;
__sbit __at (0xB2) DEC;
__sbit __at (0xB3) ADD;
__sbit __at (0xB6) BEEP;
__sbit __at (0x92) ALARM;
__sbit __at (0xB7) DQ;
__sbit __at (0x85) light_point;

extern __bit flashing;
extern __bit beep_st;

extern unsigned char x;// timer 
extern unsigned char set_st;// choose to set upper or lower limit

// {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
extern unsigned char __code LEDdata[];

extern int tens, digit;

//declared in main
extern signed char m; // integer temperature 
extern unsigned char ap;// after floating point val

			
extern signed char upper_limit;// alarming temperature, default upper limit
extern signed char lower_limit;// alarming temperature, default lower limit
#endif
