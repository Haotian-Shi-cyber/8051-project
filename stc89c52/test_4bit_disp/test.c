#include "8051.h"

int main(){
	while(1){
		P0 = ~0x98;
		P2 = 0x7F;
		for(int i = 0; i < 100; i++);
		P2 = 0xff;

		P0 = ~0x8b;
		P2 = 0xdf;
		for(int i = 0; i < 100; i++);
		P2 = 0xff;
	}
	return 0;	
}

