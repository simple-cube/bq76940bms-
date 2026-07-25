#include "UART_Cmd_Task.h"
#include "usart.h"
#include <stdio.h>

extern int Batteryval[50];
extern unsigned char shang[50];
extern unsigned char shang1[50];
extern unsigned char shang2[50];
extern unsigned char shang3[50];

extern unsigned char can_buf1[8];
extern unsigned char can_buf2[8];
extern unsigned char can_buf3[8];
extern unsigned char can_buf4[8];
extern unsigned char can_buf5[8];
extern unsigned char can_buf6[8];
extern unsigned char can_buf7[8];

extern float  Tempval_1,Tempval_2,Tempval_3,Tempval_4;
void UART_Cmd_Task(void *argument)
{
	  char NEW[50]={0};
	int n;

	  for(n=0;n<50;n++)

		{
			USART1->DR = (shang[n] & (uint16_t)0x01FF);
			delay_ms(2);
			
		}
		
	  USART2_Printf( shang1,20,ASCII_CODE);	
		delay_ms(100);
		USART2_Printf( shang2,20,ASCII_CODE);
		delay_ms(100);
		USART2_Printf( shang3,20,ASCII_CODE);
/*
    Can_Send_Msg(can_buf1,8,0x0001);
		delay_ms(2);
		Can_Send_Msg(can_buf2,8,0x0002);
		delay_ms(2);
		Can_Send_Msg(can_buf3,8,0x0003);
		delay_ms(2);
		Can_Send_Msg(can_buf4,8,0x0004);
		delay_ms(2);
		Can_Send_Msg(can_buf5,8,0x0005);
		delay_ms(2);
		Can_Send_Msg(can_buf6,8,0x0006);
		delay_ms(2);
		Can_Send_Msg(can_buf7,8,0x0007);
    delay_ms(2);
*/	
  UartSend("CLR(61);\r\n");
  delay_ms(100);
	UartSend("CLR(61);\r\n");
  delay_ms(100);
  UartSend("DIR(1);\r\n");
		delay_ms(100);
	sprintf(NEW,"DCV16(0,0,'%s%d%s',3);\r\n","第一节电压:",Batteryval[0],"mV"); 
  UartSend(NEW); 
  
	delay_ms(100); 

	sprintf(NEW,"DCV16(0,20,'%s%d%s',3);\r\n","第二节电压:",Batteryval[1],"mV"); 
  UartSend(NEW); 
		
  delay_ms(100);
  
	
	sprintf(NEW,"DCV16(0,40,'%s%d%s',3);\r\n","第三节电压:",Batteryval[4],"mV"); 
  UartSend(NEW); 
  
	delay_ms(100); 
	sprintf(NEW,"DCV16(0,60,'%s%d%s',3);\r\n","第四节电压:",Batteryval[5],"mV"); 
  UartSend(NEW); 
  
	delay_ms(100); 
	sprintf(NEW,"DCV16(0,80,'%s%d%s',3);\r\n","第五节电压:",Batteryval[6],"mV"); 
  UartSend(NEW); 
  
	delay_ms(100); 
	sprintf(NEW,"DCV16(0,100,'%s%d%s',3);\r\n","第六节电压:",Batteryval[9],"mV"); 
  UartSend(NEW); 
		delay_ms(1000);
	UartSend("CLR(61);\r\n");

  delay_ms(100); 
	sprintf(NEW,"DCV16(0,0,'%s%d%s',3);\r\n","第七节电压:",Batteryval[10],"mV"); 
  UartSend(NEW);
	
	delay_ms(100); 
	sprintf(NEW,"DCV16(0,20,'%s%d%s',3);\r\n","第八节电压:",Batteryval[11],"mV"); 
  UartSend(NEW);
	
	delay_ms(100); 
	sprintf(NEW,"DCV16(0,40,'%s%d%s',3);\r\n","第九节电压:",Batteryval[14],"mV"); 
  UartSend(NEW);
	
//	delay_ms(100); 
//	sprintf(NEW,"DCV16(0,60,'%s%d%s',3);\r\n","总电压:",Batteryval[15],"mV");	
//  UartSend(NEW); 
 	
	delay_ms(100); 
	sprintf(NEW,"DCV16(0,60,'%s%d%s',3);\r\n","总电压:",Batteryval[49],"mV"); 
  UartSend(NEW);  
	
  delay_ms(100); 
	sprintf(NEW,"DCV16(0,80,'%s%d%s',3);\r\n","电池SOC为:",Batteryval[16],"%"); 
  UartSend(NEW); 
  
	delay_ms(100); 
	sprintf(NEW,"DCV16(0,100,'%s%.2f%s',3);\r\n","电池温度为:",Tempval_2,"℃"); 
  UartSend(NEW); 
		delay_ms(1000);
	UartSend("CLR(61);\r\n");

	delay_ms(100); 
	sprintf(NEW,"DCV16(0,00,'%s%d%s',3);\r\n","当前电流为:",Batteryval[17],"mA"); 
  UartSend(NEW); 

	delay_ms(100);	
	sprintf(NEW,"DCV16(0,20,'%s',3);\r\n","HWLLO WORLD ！"); 
  UartSend(NEW);
	
	delay_ms(1000);
}