// alarm module
#include "alarm.h"
#include "global.h"

void Alarm(){
	if(((m>=upper_limit && beep_st == 1) || (m < lower_limit && beep_st == 1)) && upper_limit>=lower_limit){
		// turn on beep and alarm led
		BEEP = 0; 
		ALARM = 0; 
	} else {
		// turn off beep and alarm led
		BEEP = 1;
		ALARM = 1;
	}
}
