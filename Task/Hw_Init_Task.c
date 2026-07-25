#include "Hw_Init_Task.h"

void HardwareInitTask(void *argument)
{	
    I2C1_Configuration();
    BQ76930_config();
    vTaskDelete(NULL);
}


