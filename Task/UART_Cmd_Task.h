#ifndef UART_CMD_TASK_H
#define UART_CMD_TASK_H
#include "FreeRTOS.h"
#include "cmsis_os.h"

#include "BQ76930.h"
#include "i2c1.h"

void UART_Cmd_Task(void *argument);
#endif
