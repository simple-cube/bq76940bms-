#ifndef SOX_TASK_H
#define SOX_TASK_H
#include "FreeRTOS.h"
#include "cmsis_os.h"
#include "BQ76930.h"
#include "i2c1.h"

void SOX_Task(void *argument);
#endif