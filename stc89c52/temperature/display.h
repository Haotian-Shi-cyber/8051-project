#ifndef _DISPLAY_H
#define _DISPLAY_H

// delay for display
void Delay(unsigned int num);

// init display
void Disp_init();

// display temperature
void Disp_Temperature();

// display alarm temperature
void Disp_alarm(signed char temp);
#endif
