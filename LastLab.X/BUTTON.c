#include"BUTTON.h"
#include"pinmanager_1.h"
void readButton1(void)
{   
    firstReadRA5 = secondReadRA5;
    secondReadRA5 = BTN_RA5;
    firstReadRB0 = secondReadRB0;
    secondReadRB0 = BTN_RB0;
    if (secondReadRA5 ==firstReadRA5 )
    {
        if (firstReadRA5==0 && flagRA5==0 )
        {
            pressRA5 =1;
            flagRA5=1;
        }
        else if(firstReadRA5 == 1 ){
            pressRA5 =0;
         
        }
    }
    //RB0
    if (secondReadRB0 ==firstReadRB0 )
    {
        if (firstReadRB0==0)
        {
            if (flagRB0 == 0) {
                pressRB0 =1;
            }
            if (flagRB0 == 1) {
                count_unit++;
            }
            if(count_unit>100 )
            {
                count1A++;              
            }
        }
        else if(firstReadRB0 == 1 ){
            pressRB0 =0;
            flagRB0 =0;
            count_unit = 0;                 
        }
    }
}

void readButton2(void)
{     
    firstReadRA52 = secondReadRA52;
    secondReadRA52 = BTN_RA5;
    firstReadRB02 = secondReadRB02;
    secondReadRB02 = BTN_RB0;
    if (secondReadRB02 ==firstReadRB02 )
    {
        if (firstReadRB02==0 && flagRB02==0 )
        {
            pressRB02 =1;
            flagRB02=1;           
        }
        else if(firstReadRB02 == 1 ){
            pressRB02 =0;
        }
    }
    //RB0
    if (secondReadRA52 ==firstReadRA52 )
    {
        if (firstReadRA52==0 && flagRA52==0)
        {
            pressRA52 =1;
            
        }
        else if(firstReadRA52 == 1 ){
            pressRA52 =0;
            flagRA52 =0;
        }
    }
}
