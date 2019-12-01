
#include <xc.h>
#include <pic18f8722.h>
#include "pinmanager_1.h"
#include "Sche.h"
#include "BUTTON.h"
#include "Function.h"
#include "FSM.h"
#include"LCD3.h"
#include"time_1.h"
#include"DHT.h"
#include"DHT11.h"
void __interrupt(high_priority) tcInt(void) {
    if (INTCONbits.TMR0IE && INTCONbits.TMR0IF) {
        INTCONbits.TMR0IF = 0; // clear this interrupt condition
        TMR0 = A;
         countInter++;      
       
        if(countInter ==2)
        {
           
            readButton1();   
            readButton2();   
            countInter=0;
        }
        update();
    }
}

void main(void) {
    PIN();
    start();
    TRISD = 0x0;
    LATD = 0x00;
    mOPEN_LCD;
    mLCD_CLEAR;
    
    tmr();
    
    //insert()
    while(1){
        dispatch();
        FSM();
//        DHT();
//         LCDPutInst(0xC6);
//                     LCDPutChar(temperature_dht11[0]/10+'0');
//                     LCDPutChar(temperature_dht11[0]%10+'0');
//        __delay_ms(2000);
    }

}
