#ifndef __I2C1_H
#define __I2C1_H			 
#include "stm32f1xx_hal.h"

/* Type definitions for backward compatibility */
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;

#define delay_ms(ms)  HAL_Delay(ms)

/* Private define ------------------------------------------------------------*/

#define I2C1_SCL_PIN      					 	GPIO_PIN_8   
#define I2C1_SCL_GPIO_PORT   	       	GPIOB  
 
#define I2C1_SDA_PIN      					 	GPIO_PIN_9   
#define I2C1_SDA_GPIO_PORT   	       	GPIOB  

#define SCL1_H         	 HAL_GPIO_WritePin(I2C1_SCL_GPIO_PORT, I2C1_SCL_PIN, GPIO_PIN_SET)
#define SCL1_L            HAL_GPIO_WritePin(I2C1_SCL_GPIO_PORT, I2C1_SCL_PIN, GPIO_PIN_RESET)
   
#define SDA1_H         	 HAL_GPIO_WritePin(I2C1_SDA_GPIO_PORT, I2C1_SDA_PIN, GPIO_PIN_SET)
#define SDA1_L         	 HAL_GPIO_WritePin(I2C1_SDA_GPIO_PORT, I2C1_SDA_PIN, GPIO_PIN_RESET)

#define SCL1_read       	HAL_GPIO_ReadPin(I2C1_SCL_GPIO_PORT, I2C1_SCL_PIN)
#define SDA1_read       	HAL_GPIO_ReadPin(I2C1_SDA_GPIO_PORT, I2C1_SDA_PIN)

/* Private function prototypes -----------------------------------------------*/
void I2C1_Configuration(void);
FunctionalState I2C1_WriteByte(uint8_t SendByte, uint16_t WriteAddress, uint8_t DeviceAddress);
FunctionalState I2C1_ReadByte(uint8_t* pBuffer,   uint16_t length,   uint16_t ReadAddress,  uint8_t DeviceAddress);
u8 IIC1_read_one_byte(u16 ReadAddr);
void  IIC1_write_one_byte(u16 WriteAddr,u8 DataToWrite);
void IIC1_write_one_byte_CRC(u16 WriteAddr,u16 DataToWrite);
u8 IIC1_read_one_byte(u16 ReadAddr);
#endif 
/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
