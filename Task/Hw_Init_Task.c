#include "Hw_Init_Task.h"

void HardwareInitTask(void *argument)
{	
//		vTaskSuspendAll();
    I2C1_Configuration();
    BQ76930_config();
//		xTaskResumeAll();
    vTaskDelete(NULL);
}


