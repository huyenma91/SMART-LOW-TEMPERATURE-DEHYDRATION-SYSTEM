#include <xc.h>
#include <pic18f8722.h>
#include "pinmanager_1.h"
#include "Function.h"
//#include "DHT.h"
#include "FSM.h"
#include"DHT11.h"

void heater(void)
{if(statepress=STATE4)
    LATD1=~LATD1;
else
    LATD=0;
}
void fan2(void)
{if(statepress==STATE4)
    LATD0=~LATD0;
}
void heatpump(void)
{if(statepress==STATE4)
    LATD2=~LATD2;
}
void fan3(void)
{if(statepress==STATE4)
    LATD3=~LATD3;
}
void  fan1(void)
{if(statepress==STATE4)
    LATD4=~LATD4;
}



void DHT11(void)
{
    DHT_Result();
}
