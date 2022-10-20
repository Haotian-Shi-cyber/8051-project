#include "temp_sensor.h"
#include "timer.h"
#include "display.h"
#include "alarm.h"
#include "global.h"
#include "interrupt.h"

//defined first here

int main(){
	unsigned int z;
	
	// IE register
	EA = 1; // set EA bit to 1 allows each interrupts source to be individually enable or disabled or clearing its enable bit; 
	InitTimer();
	ET0 = 1; // enable the timer0 overflow interrupt

	// TCON register
	IT0 = 1;// interrupt 0 falling edge triggered external interrupt
	IT1 = 1;// interrupt 1 falling edge triggered external interrupt

	check_temp();// check current temperature, update global variable m and ap
	check_temp();

	// init display - - - - for some time
	for(z = 0; z < 300; z++){
		Disp_init();
	}

	while(1){
		/*
		 SET button used to set temperature limits
		 set_set == 1 is to set upper limit
		 set_set == 2 is to set lower limit
		*/

		// if SET button is pushed
		if(SET == 0){
			Delay(2000);
			while(SET == 0);// make sure it holds some time
			set_st++; // choose upper or lower limit
			x = 0;
			flashing = 1;
			if(set_st > 2)
				set_st = 0; // make sure it has only to choose upper or lower limits

		}

		// if SET button is not pushed, and shows current temp (default)
		if(set_st == 0)	{
			// turn off external interrupt 1 and 0
			EX0 = 0; 
			EX1 = 0;

			check_temp();// set current temp
			Disp_Temperature();// display temp
			Alarm(); // detect if alarm
		}
		else if(set_st == 1) {
			BEEP = 1; // turn off alarm
			ALARM = 1; // turn off led
			EX0 = 1; // enable interrupt 0
			EX1 = 1;// enable interrupt 1
			// every 500ms, changing state of flashing to make it flashing the num on the display
			if(x >= 10){
				if(flashing)
					flashing = 0;
				else
					flashing = 1;
				x = 0;
			}
			if(flashing){
				Disp_alarm(upper_limit);
			}
		}
		else if(set_st == 2) {
			BEEP = 1;
			ALARM = 1;
			EX0 = 1;
			EX1 = 1;
			// every 50ms, changing state of flashing to make it flashing the num on the display
			if(x >= 10){
				if(flashing)
					flashing = 0;
				else
					flashing = 1;
				x = 0;
			}
			if(flashing){
				Disp_alarm(lower_limit);
			}
		}
	}
}
