#include "Init_Task.h"
#include "Hw_Init_Task.h"
#include "Sample_Task.h"
#include "UART_Cmd_Task.h"
#include "SOX_Task.h"
#include "Protect_Task.h"
#include "i2c1.h"
#include "stm32f1xx_hal_rcc.h"
#include "usart.h"
extern IWDG_HandleTypeDef hiwdg;
/* Tasks ---------------------------------------------------------------------*/
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
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};
//串口发送任务
osThreadId_t UARTTaskHandle;
const osThreadAttr_t UARTTask_attributes = {
  .name = "UARTTask",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityBelowNormal,
};
//计算SOX任务
osThreadId_t SOXTaskHandle;
const osThreadAttr_t SOXTask_attributes = {
  .name = "SOXTask",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};
//保护任务
osThreadId_t ProtectTaskHandle;
const osThreadAttr_t ProtectTask_attributes = {
  .name = "ProtectTask",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};
//喂狗任务
osThreadId_t WDOGFeedTaskHandle;
const osThreadAttr_t WDOGFeedTask_attributes = {
  .name = "WDOGFeedTask",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityHigh2,
};
/* Message queues ------------------------------------------------------------*/





/* Private function prototypes -----------------------------------------------*/
void WDOGFeedTask(void *argument);

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void Init_Task(void)
{
	/* Check reset source for diagnosis */
	if (__HAL_RCC_GET_FLAG(RCC_FLAG_IWDGRST))
	{
		UartSend("RST:IWDG\r\n");
	}
	else if (__HAL_RCC_GET_FLAG(RCC_FLAG_PORRST))
	{
		UartSend("RST:POR\r\n");
	}
	else if (__HAL_RCC_GET_FLAG(RCC_FLAG_PINRST))
	{
		UartSend("RST:PIN\r\n");
	}
	else if (__HAL_RCC_GET_FLAG(RCC_FLAG_SFTRST))
	{
		UartSend("RST:SOFT\r\n");
	}
	__HAL_RCC_CLEAR_RESET_FLAGS();

	/* Create I2C mutex before any I2C access */
	I2C1_MutexHandle = osMutexNew(NULL);

  HardwareInitTaskHandle = osThreadNew(HardwareInitTask, NULL, &HardwareInitTask_attributes);
	SampleTaskHandle = osThreadNew(SampleTask, NULL, &SampleTask_attributes);
	UARTTaskHandle = osThreadNew(UART_Cmd_Task, NULL, &UARTTask_attributes);
	SOXTaskHandle = osThreadNew(SOX_Task, NULL, &SOXTask_attributes);
	ProtectTaskHandle = osThreadNew(Protect_Task, NULL, &ProtectTask_attributes);
	WDOGFeedTaskHandle   = osThreadNew(WDOGFeedTask, NULL, &WDOGFeedTask_attributes);
}	


void WDOGFeedTask(void *argument)
{

  while(1)
  {
		HAL_IWDG_Refresh(&hiwdg);
    osDelay(200);
  }
}