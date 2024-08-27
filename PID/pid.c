#include "pid.h"
#include "math.h"
#include "openmv.h"

void PidInit(pid_t *const pid, float kp, float ki, float kd, uint32_t sum_error_max, uint32_t output_max)
{
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;

    pid->cur_error = 0;
    pid->last_error = 0;
    pid->last_error = 0;

    pid->sun_error_max = sum_error_max;
    pid->output_max = output_max;
}

float Pid_update(pid_t *const pid, const float error)
{
    pid->last_error = pid->cur_error;
    pid->cur_error = error;
    pid->sum_error += pid->cur_error;
    pid->sum_error = Limiter(pid->sum_error, -pid->sun_error_max, pid->sun_error_max);
    pid->output = pid->kp*pid->cur_error + /*pid->ki*pid->sum_error +*/ pid->kd*(pid->cur_error-pid->last_error);

    return pid->output = Limiter(pid->output, -pid->output_max, pid->output_max);
}