#include "global.h"

signed char upper_limit = 38;
signed char lower_limit = 5;

// {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
unsigned char __code LEDdata[] = {0x5f, 0x44, 0x9d, 0xd5, 0xc6, 0xd3, 0xdb, 0x47, 0xdf, 0xd7, 0xcf, 0xda, 0x9b, 0xdc, 0x9b, 0x8b};

__bit flashing = 0;
__bit beep_st = 0;


unsigned char x = 0;// timer 
unsigned char set_st = 0;// choose to set upper or lower limit

signed char m;// temp integer value
unsigned char ap;//floating point value

