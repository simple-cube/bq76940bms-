#ifndef BLANCE_TASK_H
#define BLANCE_TASK_H
#include "FreeRTOS.h"
#include "cmsis_os.h"

#include "BQ76930.h"
#include "i2c1.h"
void Balance_Task(void *argument);

#endif