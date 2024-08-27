#pragma once

#include "ti_msp_dl_config.h"
#include "stdint.h"

#define F 78
#define MIN 40
#define MID 130
#define MAX 250
#define S 0

void Forward(float f1,float f2);
void Back();
void TurnLeft(float min,float max);
void TurnRight(float min,float max);
void Pid_set(float left, float right);
void Stop();