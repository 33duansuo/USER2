#include "print.h"
#include "stdio.h"
#include "string.h"
#include "stdint.h"
#include "ti/driverlib/dl_uart_main.h"
#include "ti_msp_dl_config.h"

int fputc(int c, FILE* stream)
{
    DL_UART_Main_transmitDataBlocking(UART_SCREEN_INST,c);
    return c;
}

int fputs(const char* restrict s, FILE* restrict stream)
{
    uint16_t i,len;
    len = strlen(s);
    for(int i =0;i<len;i++)
    {
        DL_UART_Main_transmitDataBlocking(UART_SCREEN_INST,s[i]);
    }
    return len;
}

int puts(const char* s)
{
    int count = fputs(s,stdout);
    count += fputs("\n",stdout);
    return count;
}