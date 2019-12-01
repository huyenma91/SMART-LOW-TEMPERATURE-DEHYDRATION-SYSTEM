#include<xc.h>
#include"pinmanager_1.h"
#include "LCD3.h"
void PIN(void){
    MODE_RA5 = HIGH;
    MODE_RB0 = HIGH;
    OUT_LED =0x0;
    PORT_D=0x0;
    GLO_EN = HIGH;
    TMR0_EN = HIGH;
    INT_FLAG = LOW;
       
    OUT_LED = 0;
    LED = 0;   
    ADCON1 = 0b00001111; 
    // Config LCDs
    LATA = 0x00;
    TRISA = 0xF3;    
    LATB = 0x00;
    TRISB = 0xFF;
    LATC = 0x00;
    TRISC = 0xD7;
//     OSCCON = 0b01100111;
//    OSCTUNE = 0b00001111;
    //ADCON1 = 0b00001111;
}

