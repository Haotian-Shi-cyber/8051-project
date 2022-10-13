#include "8051.h"
#define led P0
void delay(int num){
	while(num--);
}

int main(){
	while(1){
		led = 0x00;
		for(int i = 0; i < 30000; i++);
		led = ~0xfe;
		for(int i = 0; i < 30000; i++);
	}
	return 0;	
}

