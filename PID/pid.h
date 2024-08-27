#pragma once
#include "ti_msp_dl_config.h"
#include "stdint.h"
#include "stdbool.h"
#define Limiter(val,min,max) ((val)<(min)?(min):((val)>(max)?(max):(val)))
typedef struct
{
    float kp,ki,kd;

    float cur_error,last_error,sum_error;

    float output;

    float sun_error_max,output_max;
} pid_t;

void PidInit(pid_t *const pid, float kp, float ki, float kd, uint32_t sum_error_max, uint32_t output_max);

float Pid_update(pid_t *const pid, const float error);