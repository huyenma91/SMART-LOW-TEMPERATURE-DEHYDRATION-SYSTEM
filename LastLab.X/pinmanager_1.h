
#ifndef PINMANAGER_1_H
#define	PINMANAGER_1_H

#include <xc.h> // include processor files - each processor file is guarded. 

#pragma config  OSC = INTIO67
#pragma config 	FCMEN = OFF
#pragma config 	IESO = OFF
#pragma config 	PWRT = OFF
#pragma config 	BOREN = OFF
#pragma config 	WDT = OFF
#pragma config 	MCLRE = ON
#pragma config 	LVP = OFF
#pragma config 	XINST = OFF

//define output 
#define HIGH 1
#define LOW 0
#define LED LATD
#define OUT_LED TRISD
#define PORT_D PORTD
//define button
#define BTN_RA5 PORTAbits.RA5
#define BTN_RB0 PORTBbits.RB0
//define port mode
#define MODE_RA5 TRISAbits.RA5
#define MODE_RB0 TRISBbits.RB0
//define timer0
#define TMR_EN OSCCONbits.IDLEN
#define SEL_OSTS OSCCONbits.OSTS
#define SEL_STA OSCCONbits.IOFS
#define SEL_SYSCLK OSCCONbits.SCS
#define SEL_FREQ OSCCONbits.IRCF
#define TMR0_ON T0CONbits.TMR0ON
#define TMR0_8BIT T0CONbits.T08BIT
#define TMR0_TOCS T0CONbits.T0CS
#define TMR0_T0SE T0CONbits.T0SE
#define TMR0_PSA T0CONbits.PSA
#define TMR0_TOPS T0CONbits.T0PS


#define GLO_EN INTCONbits.GIE
#define TMR0_EN INTCONbits.TMR0IE
#define TMR0_FLAG INTCONbits.TMR0IF
#define INT_FLAG INTCONbits.INT0IF
//time
#define RA5pressquick 100
#define RA5pressslow 300
#define RA5speedquick 10
#define RA5speedslow 50
#define RB0pressquick 100
#define RB0pressslow 300
#define RB0speedquick 10
#define RB0speedslow 50

//int global_hour = 0;
//int global_minute = 0;
//int global_second = 0;
int hr =0, min =0, sec=0, khac=0;
 int reset = 1;
 int resetStop =1;

int stopwatch_count = 0; // 1/100 second of WDT
int stopwatch_minute = 0; // minute of WDT
int stopwatch_second = 0; // second of WDT

int pressRA5, pressRB0;
int firstReadRA5 = 0,secondReadRA5=0;
int firstReadRB0 = 0,secondReadRB0=0;

int pressRA52, pressRB02=0;
int firstReadRA52 = 0,secondReadRA52=0;
int firstReadRB02 = 0,secondReadRB02=0;

unsigned char portValue = 0; 
char flagRA5 =0;
char flagRB0 =0;
char flagRA52 =0;
char flagRB02 =0;
int A=0;
void PIN(void);
int cur_state=0;
int stateprocess =0;
int blink_count = 0;
int blink_flag=0;
int flagcount=0;
int flagcount1=0;
int stopflag=1;
int temp_temp =0;

int count1A=0;
int state1A=0;
int count2A=0;

int count_unit = 0;
int countInter =0;
int flagLCD1=0;
int flagLCD2=0;
int flagLCD3=0;
int flagLCD4=0;

int maxtemp=20;
int maxhumi=80;
enum Statepress{STATE1,STATE2,STATE3,STATE4};
enum Statepress statepress; 
#endif	/* XC_HEADER_TEMPLATE_H */

