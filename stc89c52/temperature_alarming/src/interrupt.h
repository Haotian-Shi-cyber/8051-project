#ifndef INTERRUPT_H
#define INTERRUPT_H

void timer0() __interrupt 1;
void int0() __interrupt 0;
void int1(void) __interrupt 2;

#endif
