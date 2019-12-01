

#include "time_1.h"
#include <math.h>
#include<xc.h>
#include "pinmanager_1.h"
//double mul(double a, double b)
//{
//    double res = 0;
//    for(int i = 0; i < b; i++)
//    {
//        res = res + a;
//    }
//    return res;
//}
void tmr (void){   
    TMR_EN = 0b0;
    SEL_OSTS = 0b0;
    SEL_STA = 0b1;
    SEL_SYSCLK = 0b10;
    TMR0_ON = 0b1;
    TMR0_8BIT = 0b1;
    TMR0_TOCS =0b0;
    TMR0_T0SE =0b0;
    TMR0_PSA = 0b0;

    SEL_FREQ = 0b111;
    TMR0_TOPS=0b111;
//       double temp_1 = mul(256, 1000);
//       double temp_2 = 1/temp_1;
//       double temp = mul(temp_2, 1000000);
//       LATD = temp;
    //A = 256 - temp;
    
       A = 177;
   
}


