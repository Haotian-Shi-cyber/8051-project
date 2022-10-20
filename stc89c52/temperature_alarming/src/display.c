#include "display.h"
#include "global.h"

void Delay(unsigned int num){
	while(--num);
}

// common anode
// low power results in lighting led
void Disp_init(){
	// 4 digit 12 pin, please refer to manual
	P0 = ~0x80; // to display ----
	P2 = 0x00; // pnp transistor, let current go
	Delay(800);
}

void Disp_Temperature(){ // display temperaturea
	// the trick to display temperauture is using small delay on each digit to trick human eyes
	P0 = ~0x98; // display C at 4th 
	P2 = 0x7F; 
	Delay(100); 
	P2 = 0xff; 
	
	P0 = ~LEDdata[ap]; // display floating point val at 3th
       	P2 = 0xdf;
	Delay(100);
	P2 = 0xff;

	P0 = ~LEDdata[m%10]; // display digit at 2nd
	light_point = 0;     // display point
	P2 = 0xf7;
	Delay(100);
	P2 = 0xff;

	P0 = ~LEDdata[m/10]; // display tens at 1st
	P2 = 0xfd;
	Delay(100);
	P2 = 0xff;
}

void Disp_alarm(signed char temp){ // display temperaturea
	// the trick to display temperauture is using small delay on each digit to trick human eyes
	P0 = ~0x98; // display C at 4th 
	P2 = 0x7F; 
	Delay(100); 
	P2 = 0xff; 
	
	P0 = ~LEDdata[temp%10]; // display digit
       	P2 = 0xdf;
	Delay(100);
	P2 = 0xff;

	P0 = ~LEDdata[temp/10]; // display tens
	P2 = 0xf7;
	Delay(100);
	P2 = 0xff;
	
	if(set_st == 1){
		P0 = ~0xCE;// H
	} else if(set_st == 2){
		P0 = 0xe5;// L
	}
	P2 = 0XFD;
	Delay(100);
	P2 = 0xff;
}
