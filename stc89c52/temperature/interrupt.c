#include "display.h"
#include "global.h"
// timer0 interrupt
// every 50ms increment x
void timer0() __interrupt 1{
	// 15536 to 65536
	// 50ms == 50000us
	// 1us = 1/10^6; 1M machine cycles = 12M clock cycles
	
	TH0 = 0x3c;
	TL0 = 0xb0;
	x++;
}

/* external interrupt 0 */
// decrease
void int0() __interrupt 0{
	EX0 = 0;// turn off external interrupt 0
	if(DEC == 0 && set_st == 1){// decrease upper limits
		while(DEC == 0){// holds d
			Disp_alarm(upper_limit);
		}
		upper_limit--;
		if(upper_limit < lower_limit)
			upper_limit = lower_limit;
		
		}
	else if(DEC == 0 && set_st == 2){// decrease lower limits
		while(DEC == 0){
			Disp_alarm(lower_limit);
		}
		lower_limit--;
		if(lower_limit < 0)
			lower_limit = 0;
	}
}

/* external interrupt 1 */
// increase
void int1(void) __interrupt 2{
	EX1 = 0;// turn off external interrupt 1
	if(ADD == 0 && set_st == 1){//increase upper limits
		while(ADD = 0){
			Disp_alarm(upper_limit);
		}
		upper_limit++;
		if(upper_limit > 99)
			upper_limit = 99;
	}
	else if(ADD == 0 && set_st == 2){
		while(ADD == 0){
			Disp_alarm(lower_limit);
		}
		lower_limit++;
		if(lower_limit > upper_limit)
			lower_limit = upper_limit;

	}
}
