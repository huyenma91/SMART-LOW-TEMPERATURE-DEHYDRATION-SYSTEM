#ifndef TMR_H
#define	TMR_H

#define FREQ 4000000
//#define SCALE 128
#define BASE_CYCLE 1 //in ms
unsigned long int TANSO=FREQ;
unsigned int B= BASE_CYCLE;
void tmr(void);
double mul(double a, double b);
#endif	


