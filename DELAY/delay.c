#include "delay.h"


void Delay_ms(uint32_t ms)
{
    delay_cycles(CPUCLK_FREQ/1000*ms);
}
