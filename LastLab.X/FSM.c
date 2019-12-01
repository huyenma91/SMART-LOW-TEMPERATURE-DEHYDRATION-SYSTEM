#include"pinmanager_1.h"
#include"FSM.h"
#include"LCD3.h"
#include"Sche.h"
#include"Function.h"
#include"BUTTON.h"
#include"DHT11.h"

void FSM(void) {
    switch (statepress) {
        case STATE1:
        {
            //start();
            if (flagLCD1 == 0) {
                LATD=0;
                mLCD_CLEAR;
                mCURSOR_LINE1;
                LCDPutStr("LTD System");
                flagLCD1 = 1;
            }

            if (pressRA5 == 0 && flagRA5 == 1) {
                flagRA5 = 0;
                flagLCD1 = 0;
                //LATD++;

                statepress = STATE2;

            }
            break;
        }
        case STATE2:
        {
            if (flagLCD2 == 0) {
                mLCD_CLEAR;
                mCURSOR_LINE1;
                LCDPutInst(0x80);
                LCDPutStr("Max Temp:");
                LCDPutInst(0x89);
                LCDPutChar(maxtemp / 10 + '0');
                LCDPutChar(maxtemp % 10 + '0');
                mCURSOR_LINE2;
                LCDPutStr("RA5 -> next");
                flagLCD2 = 1;
            }

            if (pressRB02 == 0 && flagRB02 == 1) {
                maxtemp=maxtemp+5;
                LCDPutInst(0x89);
                LCDPutChar(maxtemp / 10 + '0');
                LCDPutChar(maxtemp % 10 + '0');
                if(maxtemp==90){
                    maxtemp=15;
                }
                flagRB02 = 0;
            }

            if (pressRA5 == 0 && flagRA5 == 1) {
                flagRA5 = 0;
                statepress = STATE3;
                flagLCD2 = 0;

            }
            break;
        }

        case STATE3:
        {
            if (flagLCD3 == 0) {
                mLCD_CLEAR;
                mCURSOR_LINE1;
                LCDPutStr("MAX humi:");
                 LCDPutInst(0x89);
                LCDPutChar(maxhumi / 10 + '0');
                LCDPutChar(maxhumi % 10 + '0');
                mCURSOR_LINE2;
                LCDPutStr("RA5 -> next");
                
                flagRB02 = 0;
                flagLCD3 = 1;
            }
              if (pressRB02 == 0 && flagRB02 == 1) {
                maxhumi=maxhumi+5;
                 if(maxhumi==95){
                    maxhumi=55;
                }
                LCDPutInst(0x89);
                LCDPutChar(maxhumi / 10 + '0');
                LCDPutChar(maxhumi % 10 + '0');
                flagRB02 = 0;
            }
            if (pressRA5 == 0 && flagRA5 == 1) {
                flagRA5 = 0;
                statepress = STATE4;
                flagLCD3 = 0;
                int lol = maxtemp*50;
                insert(10, 2000, DHT_Result);
                insert(lol, lol, heater);
                insert(lol,  lol, fan2);
                 insert(lol*2, lol, heatpump);
                insert(lol*2,  lol, fan3);
                if(RH_Integral>=maxhumi)
                {
                    insert(1000,  1000, fan1);
                }
                //insert(3000,2000,heatpump);
                //insert(3000,2000,fan3);
            }
            break;
        }

        case STATE4:
        {
            if (flagLCD4 == 0) {
                mLCD_CLEAR;
                mCURSOR_LINE1;
                LCDPutStr("Working");
                mCURSOR_LINE2;
                
                flagLCD4 = 1;
            }
            if (pressRA5 == 0 && flagRA5 == 1) {
                flagRA5 = 0;
                statepress = STATE1;
                
                flagLCD4 = 0;
                start();
            }
            break;
        }

    }
}


