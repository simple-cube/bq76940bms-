#ifndef PROTECT_TASK_H
#define PROTECT_TASK_H
#include "FreeRTOS.h"
#include "cmsis_os.h"

#include "BQ76930.h"
#include "i2c1.h"
void Protect_Task(void *argument);
#endif