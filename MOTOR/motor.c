#include "motor.h"
#include "ti/driverlib/dl_gpio.h"
#include "ti/driverlib/dl_timera.h"
#include "ti_msp_dl_config.h"


void Forward(float f1,float f2)
{
    if(f1<480&&f2<480)
    {    
    int32_t com1 = 499-499*(f1/500);
    int32_t com2 = 499-499*(f2/500);
    DL_TimerA_setCaptureCompareValue(MOTOR_INST, com1, DL_TIMER_CC_0_INDEX);
    DL_TimerA_setCaptureCompareValue(MOTOR_INST, com1, DL_TIMER_CC_2_INDEX);
    DL_TimerA_setCaptureCompareValue(MOTOR_INST, com2, DL_TIMER_CC_1_INDEX);
    DL_TimerA_setCaptureCompareValue(MOTOR_INST, com2, DL_TIMER_CC_3_INDEX);

    DL_GPIO_clearPins(GPIO_CTRL_PIN_LF_0_PORT,GPIO_CTRL_PIN_LF_0_PIN);
    DL_GPIO_setPins(GPIO_CTRL_PIN_LF_1_PORT,GPIO_CTRL_PIN_LF_1_PIN);
    DL_GPIO_clearPins(GPIO_CTRL_PIN_LB_0_PORT,GPIO_CTRL_PIN_LB_0_PIN);
    DL_GPIO_setPins(GPIO_CTRL_PIN_LB_1_PORT,GPIO_CTRL_PIN_LB_1_PIN);

    DL_GPIO_clearPins(GPIO_CTRL_PIN_RB_1_PORT,GPIO_CTRL_PIN_RB_1_PIN);
    DL_GPIO_setPins(GPIO_CTRL_PIN_RB_0_PORT,GPIO_CTRL_PIN_RB_0_PIN);
    DL_GPIO_clearPins(GPIO_CTRL_PIN_RF_1_PORT,GPIO_CTRL_PIN_RF_1_PIN);
    DL_GPIO_setPins(GPIO_CTRL_PIN_RF_0_PORT,GPIO_CTRL_PIN_RF_0_PIN);
    }
     
}
void Stop()
{
    DL_TimerA_setCaptureCompareValue(MOTOR_INST, 499, DL_TIMER_CC_0_INDEX);
    DL_TimerA_setCaptureCompareValue(MOTOR_INST, 499, DL_TIMER_CC_2_INDEX);
    DL_TimerA_setCaptureCompareValue(MOTOR_INST, 499, DL_TIMER_CC_1_INDEX);
    DL_TimerA_setCaptureCompareValue(MOTOR_INST, 499, DL_TIMER_CC_3_INDEX);
}
void TurnLeft(float min,float max)
{
    if(min<70&&max<270)
    {
    int32_t com1 = 499-499*(min/500);
    int32_t com2 = 499-499*(max/500);
    DL_TimerA_setCaptureCompareValue(MOTOR_INST, com1, DL_TIMER_CC_0_INDEX);
    DL_TimerA_setCaptureCompareValue(MOTOR_INST, com1, DL_TIMER_CC_2_INDEX);
    DL_TimerA_setCaptureCompareValue(MOTOR_INST, com2, DL_TIMER_CC_1_INDEX);
    DL_TimerA_setCaptureCompareValue(MOTOR_INST, com2, DL_TIMER_CC_3_INDEX);

    DL_GPIO_clearPins(GPIO_CTRL_PIN_LF_0_PORT,GPIO_CTRL_PIN_LF_0_PIN);
    DL_GPIO_setPins(GPIO_CTRL_PIN_LF_1_PORT,GPIO_CTRL_PIN_LF_1_PIN);
    DL_GPIO_clearPins(GPIO_CTRL_PIN_LB_0_PORT,GPIO_CTRL_PIN_LB_0_PIN);
    DL_GPIO_setPins(GPIO_CTRL_PIN_LB_1_PORT,GPIO_CTRL_PIN_LB_1_PIN);

    DL_GPIO_clearPins(GPIO_CTRL_PIN_RB_1_PORT,GPIO_CTRL_PIN_RB_1_PIN);
    DL_GPIO_setPins(GPIO_CTRL_PIN_RB_0_PORT,GPIO_CTRL_PIN_RB_0_PIN);
    DL_GPIO_clearPins(GPIO_CTRL_PIN_RF_1_PORT,GPIO_CTRL_PIN_RF_1_PIN);
    DL_GPIO_setPins(GPIO_CTRL_PIN_RF_0_PORT,GPIO_CTRL_PIN_RF_0_PIN);
    }
}
void TurnRight(float min,float max)
{
    if(min<70&&max<270)
    {
    int32_t com1 = 499-499*(min/500);
    int32_t com2 = 499-499*(max/500);
    DL_TimerA_setCaptureCompareValue(MOTOR_INST, com1, DL_TIMER_CC_1_INDEX);
    DL_TimerA_setCaptureCompareValue(MOTOR_INST, com1, DL_TIMER_CC_3_INDEX);
    DL_TimerA_setCaptureCompareValue(MOTOR_INST, com2, DL_TIMER_CC_0_INDEX);
    DL_TimerA_setCaptureCompareValue(MOTOR_INST, com2, DL_TIMER_CC_2_INDEX);

    DL_GPIO_clearPins(GPIO_CTRL_PIN_LF_0_PORT,GPIO_CTRL_PIN_LF_0_PIN);
    DL_GPIO_setPins(GPIO_CTRL_PIN_LF_1_PORT,GPIO_CTRL_PIN_LF_1_PIN);
    DL_GPIO_clearPins(GPIO_CTRL_PIN_LB_0_PORT,GPIO_CTRL_PIN_LB_0_PIN);
    DL_GPIO_setPins(GPIO_CTRL_PIN_LB_1_PORT,GPIO_CTRL_PIN_LB_1_PIN);

    DL_GPIO_clearPins(GPIO_CTRL_PIN_RB_1_PORT,GPIO_CTRL_PIN_RB_1_PIN);
    DL_GPIO_setPins(GPIO_CTRL_PIN_RB_0_PORT,GPIO_CTRL_PIN_RB_0_PIN);
    DL_GPIO_clearPins(GPIO_CTRL_PIN_RF_1_PORT,GPIO_CTRL_PIN_RF_1_PIN);
    DL_GPIO_setPins(GPIO_CTRL_PIN_RF_0_PORT,GPIO_CTRL_PIN_RF_0_PIN);
    }
}

void Pid_set(float left, float right)
{
    
}