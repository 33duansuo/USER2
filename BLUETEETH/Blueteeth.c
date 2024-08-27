#include "Blueteeth.h"

uint8_t count2 = 0;
uint8_t BT_Buffer[3] = {0};
uint8_t BT = 0;

void UART_BT_INST_IRQHandler()
{
    switch(DL_UART_getPendingInterrupt(UART_BT_INST))
    {
        case DL_UART_IIDX_RX:
        {
            BT_Buffer[count2++] = DL_UART_Main_receiveData(UART_BT_INST);
            if(BT_Buffer[0]!=0x0a)
            {
                count2 = 0;
                BT_Buffer[0]=0;
            }
            else if(BT_Buffer[0]==0x0a&&BT_Buffer[count2-1]==0x0d)
            {
                BT = BT_Buffer[1];
                count2 = 0;

            }
//            if(count2>=3)
//            {
//                count2 = 0;
//            }
            break;
        }
        default:
            break;
    }    
    DL_UART_clearInterruptStatus(UART_BT_INST,DL_UART_INTERRUPT_RX);
}

void BT_Trnasmit(uint8_t data)
{
    for(int i =0;i<10;i++)
    {
        DL_UART_Main_transmitData(UART_BT_INST,0x0a);
        delay_cycles(3200);

        DL_UART_Main_transmitData(UART_BT_INST,data);
        delay_cycles(3200);

        DL_UART_Main_transmitData(UART_BT_INST,0x0d);
        delay_cycles(3200);
    }
}
