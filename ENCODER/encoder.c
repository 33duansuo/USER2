#include "encoder.h"
#include "ti/driverlib/dl_timerg.h"
#include "ti_msp_dl_config.h"
#include "stdint.h"


uint32_t encoder_l = 0;
uint32_t encoder_r = 0;
uint32_t R = 0;
uint32_t L = 0;


void EncoderInit()
{
    NVIC_EnableIRQ(ENCODER_L_INST_INT_IRQN);
    NVIC_EnableIRQ(ENCODER_R_INST_INT_IRQN);
    DL_TimerG_startCounter(ENCODER_R_INST);
    DL_TimerG_startCounter(ENCODER_R_INST);
}

void ENCODER_L_INST_IRQHandler()
{
    switch (DL_TimerG_getPendingInterrupt(ENCODER_L_INST)) 
    {
        case DL_TIMERG_IIDX_LOAD:
                encoder_l++;
            break;
        default:
            break;
    }
}

void ENCODER_R_INST_IRQHandler()
{
    switch (DL_TimerG_getPendingInterrupt(ENCODER_R_INST)) 
    {
        case DL_TIMERG_IIDX_LOAD:
                encoder_r++;
            break;
        default:
            break;
    }
}
