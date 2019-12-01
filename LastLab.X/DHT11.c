#include"DHT11.h"
#include"LCD3.h"
#include "pinmanager_1.h"
#include<xc.h>
void DHT_Init(void)
{
    Data_Dir = 0;
    Data_Out = 0;
    __delay_ms(20);
    Data_Out = 1;
    __delay_us(20);
    Data_Dir = 1;
}
void DHT_Check(void)
{
    int timeOut = DHT_TO;
    while(Data_In & 1){
        if(--timeOut==0){
            timeOut = DHT_TO;
            return;
        }
    }
    timeOut = DHT_TO;
    while(!(Data_In&1)){
        if(--timeOut==0){
            timeOut = DHT_TO;
            return;
        }
    }
    timeOut = DHT_TO;
    while(Data_In&1){
        if(--timeOut==0){
            timeOut = DHT_TO;
            return;
        }
    }        
}
char DHT_ReadData(void)
{
    char i,datain = 0;
    int timeOut = DHT_TO;  
    for(i=0;i<8;i++)
    {
        while(!(Data_In & 1)){
            if(--timeOut==0){
                return 0;
            }
        }          
        __delay_us(25);         
        if(!Data_In & 1) 
          datain &= ~(1 << (7-i));
        else{
            datain |= (1 << (7-i));
            timeOut = DHT_TO;
            while(Data_In & 1){
                if(--timeOut==0){
                    return 0;
                }
            }
        }        
    }
  return datain;
}
void DHT_Result(){
    DHT_Init();
    DHT_Check();
    RH_Integral = DHT_ReadData();  
    RH_Decimal = DHT_ReadData();   
    T_Integral = DHT_ReadData();   
    T_Decimal = DHT_ReadData();    
    Checksum = DHT_ReadData();
    //mLCD_CLEAR;
    LCDPutInst(0x8A);
    if(Checksum != ((RH_Integral+RH_Decimal+T_Integral+T_Decimal)&0xFF)){
        return;
    }
    else
    {
           LCDPutInst(0xC4);
        LCDPutStr("T:");
        LCDPutChar(T_Integral/10+'0');
        LCDPutChar(T_Integral%10+'0');
        mCURSOR_LINE2;
        LCDPutInst(0xCA);
        LCDPutStr("H:");
        LCDPutChar(RH_Integral/10+'0');
        LCDPutChar(RH_Integral%10+'0');
        return;
    }
}