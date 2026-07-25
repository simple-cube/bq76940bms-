#ifndef __HW_INIT_TASK_TASK_H
#define __HW_INIT_TASK_TASK_H
#include "FreeRTOS.h"
#include "cmsis_os.h"

#include "BQ76930.h"
#include "i2c1.h"

void HardwareInitTask(void *argument);
	
#endif