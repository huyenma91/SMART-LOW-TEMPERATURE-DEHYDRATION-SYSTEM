#include <xc.h>
#include"Sche.h"
#define MAX_NUM 10
struct Node{
    int delay;
    int realdelay;
    int period;
    int runMe;
    void (*func_ptr)();
};

struct Node SCH_Task[10];
void (*ptr[10])();
int index = 0;
int count = 0;
void start(void)
{
    count = 0;
    index = 0;
    for(int i=0; i< MAX_NUM;i++)
        {
            SCH_Task[i].delay=-1;
            SCH_Task[i].realdelay=-1;
            SCH_Task[i].period=0;
            SCH_Task[i].runMe=0;
            SCH_Task[i].func_ptr=NULL;
        }
    
}
    void insert(int delay, int period, void (*func_ptr)())
    {
        if(count == MAX_NUM)
        {
            return;
        }
        if(count == 0)
        {
            SCH_Task[0].delay = delay/10;
            SCH_Task[0].realdelay = delay/10;
            SCH_Task[0].period = period/10;
            SCH_Task[0].runMe = 0;
            SCH_Task[0].func_ptr=func_ptr;
            count ++;
            return;
        }
        else
        { 
            int i;
            int time = 0;
            for( i = count - 1; (i>=0 && SCH_Task[i].realdelay>=delay/10);i--){
            SCH_Task[i+1] = SCH_Task[i];
            }
            for(int j = 0; j<=i; j++)
            {
                time += SCH_Task[j].delay;
            }
            SCH_Task[i+1].delay = delay/10-time;
            SCH_Task[i+1].period = period/10;
            SCH_Task[i+1].realdelay = delay/10;
            SCH_Task[0].runMe = 0;
            SCH_Task[i+1].func_ptr=func_ptr;
            count++;
            if(SCH_Task[i+2].delay>0)
            {
               SCH_Task[i+2].delay = SCH_Task[i+2].delay-SCH_Task[i+1].delay;
            }
            return;
        }
    }
    void remove(void){
        if(count == 0)
            return;
        else
        {
            for(int i = 1; i<count;i++)
            {
                 SCH_Task[i-1] = SCH_Task[i];
            }
            SCH_Task[count-1].delay = -1;
            SCH_Task[count-1].period = 0;
            SCH_Task[count-1].runMe = 0;
            SCH_Task[count-1].func_ptr=NULL;
            count--;
        }
    };
    void update(void){
        int i = 0;
        int j = 0;
        index = 0;
        if(count < 5)
            return;
        SCH_Task[i].delay-=1;
        while(SCH_Task[i].delay <= 0)
        {        
            ptr[index] = SCH_Task[i].func_ptr;
            int time = 0;
            int temp_1 =SCH_Task[i].period;
            int temp_2 = SCH_Task[i].period;   
            void (*ptr_temp)() = SCH_Task[i].func_ptr;
            remove();
            if(temp_2!=0){
            for(j = 0; (j <= count-1 && temp_2>=SCH_Task[j].delay); j++)
            {
                    time=SCH_Task[j].delay;
                    temp_2 -= time;
            }
            for(int t = count-1; t >= j; t--)
            {
                SCH_Task[t+1] = SCH_Task[t];
            }
            SCH_Task[j].delay = temp_2;
            SCH_Task[j].period = temp_1;
            SCH_Task[j].func_ptr = ptr_temp;
            count++;
            
            if(SCH_Task[j+1].delay>0)
            {
                SCH_Task[j+1].delay = SCH_Task[j+1].delay-SCH_Task[j].delay;
            }
            i = 0;
        }
            index++;
        }
    };
    
    void deleteTask(void (*func_ptr)())
    {
        for(int i = 0; i < count; i++)
        {
            if(SCH_Task[i].func_ptr == func_ptr)
            {
                
                for(int j = i+1; j<=count-1;j++)
                {
                    SCH_Task[j-1] = SCH_Task[j];
                }
                count --;
                SCH_Task[count].delay = -1;
                SCH_Task[count].period = 0;
                SCH_Task[count].runMe = 0;
                SCH_Task[count].func_ptr=NULL;
                return;
            }
        }
    };
     
    void dispatch()
    {

        for(int i = 0; (i < 10 && ptr[i]!=NULL); i++)
        {
            void (*pFn)() = ptr[i];
            if(ptr[i]!=0){
            (*pFn)();
             ptr[i]=NULL;}
        }
    };


