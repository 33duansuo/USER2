#include "openmv.h"
#include "ti_msp_dl_config.h"

unsigned char RxBuffer2[11]={0};
//uint8_t uart_data[5] = {0};
uint32_t count1 = 0;
double angl[3]={0};
double acc[3]={0};
double anglSpeed[3]={0};

void UART_OPENMV_INST_IRQHandler()
{
                //濡傛灉浜х敓浜嗕覆鍙ｄ腑鏂�
    switch( DL_UART_getPendingInterrupt(UART_OPENMV_INST))
    {
        case DL_UART_IIDX_RX://濡傛灉鏄帴鏀朵腑鏂�
        {
                RxBuffer2[count1++] = DL_UART_Main_receiveData(UART_OPENMV_INST);
                        if(RxBuffer2[0]!=0x55)
                        {
                            count1= 0;
                        }

                               if(RxBuffer2[0]-0x55==0)
                               {
                                               switch(RxBuffer[1])
                                               {
                                                   case 0x51:
                                                   acc[0] = ((short)(RxBuffer2[3]<<8|RxBuffer2[2]))/32768.0*16*9.8;
                                                   acc[1] = ((short)(RxBuffer2[5]<<8|RxBuffer2[4]))/32768.0*16*9.8;
                                                   acc[2] = ((short)(RxBuffer2[7]<<8|RxBuffer2[6]))/32768.0*16*9.8;
                                                   break;
                                                   case 0x52:
                                                   anglSpeed[0] = ((short)(RxBuffer2[3]<<8|RxBuffer2[2]))/32768.0*2000;
                                                   anglSpeed[1] = ((short)(RxBuffer2[5]<<8|RxBuffer2[4]))/32768.0*2000;
                                                   anglSpeed[2] = ((short)(RxBuffer2[7]<<8|RxBuffer2[6]))/32768.0*2000;
                                                   break;
                                                   case 0x53:
                                                   angl[0] = ((short)(RxBuffer2[3]<<8|RxBuffer2[2]))/32768.0*180;
                                                   angl[1] = ((short)(RxBuffer2[5]<<8|RxBuffer2[4]))/32768.0*180;
                                                   angl[2] = ((short)(RxBuffer2[7]<<8|RxBuffer2[6]))/32768.0*180;
                                                   break;
                                                }
                               }
                          if(count1>= 11)  //溢出判断
                                              {
                                                count1 = 0;
                                              }

            break;
        }
        default:
            break;
    }
    DL_UART_clearInterruptStatus(UART_OPENMV_INST,DL_UART_INTERRUPT_RX);    
}
