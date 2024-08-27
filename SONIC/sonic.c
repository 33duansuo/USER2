#include "sonic.h"
#include "delay.h"
#include "ti/driverlib/dl_gpio.h"
#include "ti/driverlib/dl_timer.h"
#include "ti/driverlib/dl_timerg.h"
#include "ti/driverlib/m0p/dl_core.h"
#include "ti_msp_dl_config.h"
#include "stdint.h"
#include "stdio.h"


uint32_t OverFlowFlag;

uint32_t GetDis()
{
    uint32_t dis;
    uint32_t cnt = 0;

    DL_GPIO_setPins(GPIO_SONIC_PORT, GPIO_SONIC_PIN_TX_PIN);
    delay_cycles(320);
    DL_GPIO_clearPins(GPIO_SONIC_PORT, GPIO_SONIC_PIN_TX_PIN);


    OverFlowFlag = 0;
    while(1)
    {
        
        if(DL_GPIO_readPins(GPIO_SONIC_PORT,GPIO_SONIC_PIN_RX_PIN))
        {
         
            DL_TimerG_startCounter(TIMER_Sonic_INST);
            DL_TimerG_setTimerCount(TIMER_Sonic_INST,0);
            break;
        }

    }

    
    while(DL_GPIO_readPins(GPIO_SONIC_PORT,GPIO_SONIC_PIN_RX_PIN) && !OverFlowFlag)
    {
        
    }
    //printf("t0.txt=\"%u HZ\"\xff\xff\xff", DL_TimerG_getTimerCount(TIMER_Sonic_INST));

    DL_TimerG_stopCounter(TIMER_Sonic_INST);

    if(OverFlowFlag)
    {
        dis = 10000;
    }
    else 
    {
        cnt = DL_TimerG_getTimerCount(TIMER_Sonic_INST);
        dis = cnt*0.17;
    }
    return dis;
}

uint32_t ReadVoice()
{
    if(DL_GPIO_readPins(GPIO_SONIC_PORT,GPIO_SONIC_PIN_0_PIN)==GPIO_SONIC_PIN_0_PIN)
        return 0;
    else
        return 1;    
}

void TIMER_Sonic_INST_IRQHandler()
{
    switch(DL_TimerG_getPendingInterrupt(TIMER_Sonic_INST))
    {
        case DL_TIMER_IIDX_LOAD:
        {
            OverFlowFlag = 1;
            break;
        }
        default:
            break;
            
    }
}