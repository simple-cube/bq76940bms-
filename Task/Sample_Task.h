#ifndef __SAMPLE_TASK_H
#define __SAMPLE_TASK_H

#include "FreeRTOS.h"
#include "cmsis_os.h"

#include "BQ76930.h"
#include "i2c1.h"

void SampleTask(void *argument);

#endif