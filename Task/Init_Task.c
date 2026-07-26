#include "Init_Task.h"
#include "Hw_Init_Task.h"
#include "Sample_Task.h"
#include "UART_Cmd_Task.h"
#include "SOX_Task.h"
//硬件初始化
osThreadId_t HardwareInitTaskHandle;
const osThreadAttr_t HardwareInitTask_attributes = {
  .name = "HardwareInitTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
//采样任务
osThreadId_t SampleTaskHandle;
const osThreadAttr_t SampleTask_attributes = {
  .name = "SampleTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};
//串口发送任务
osThreadId_t UARTTaskHandle;
const osThreadAttr_t UARTTask_attributes = {
  .name = "UARTTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityBelowNormal,
};
//计算SOX任务
osThreadId_t SOXTaskHandle;
const osThreadAttr_t SOXTask_attributes = {
  .name = "SOXTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};
void Init_Task(void)
{
	
  HardwareInitTaskHandle = osThreadNew(HardwareInitTask, NULL, &HardwareInitTask_attributes);
	SampleTaskHandle = osThreadNew(SampleTask, NULL, &SampleTask_attributes);
	UARTTaskHandle = osThreadNew(UART_Cmd_Task, NULL, &UARTTask_attributes);
	SOXTaskHandle = osThreadNew(SOX_Task, NULL, &SOXTask_attributes);
}	