#include "timer.h"
#include "8051.h"

void InitTimer(){
	//TMOD REG, NOT BIT ADDRESSABLE
	TMOD = 0x1;// please refer to TMOD manual, M1 = 0 & M0 = 1, 16 bit timer/counter
	
	TH0 = 0x3c;// timer/counter 0 high byte 0x00111100
	TL0 = 0xb0;// timer/coutner 0 low byte 0x10110000 50ms
	TR0 = 1;// timer 0 enabled!!
}

