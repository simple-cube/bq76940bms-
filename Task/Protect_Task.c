#include "Protect_Task.h"
extern int Batteryval[50];
uint8_t Temp_up_flag,OV_FLAG,UV_FLAG,OC_FLAG;

void Protect_Task(void *argument)
{
	while(1)
	{
			if((Batteryval[0]>4200)||(Batteryval[1]>4200)||(Batteryval[4]>4200)||(Batteryval[5]>4200)||(Batteryval[6]>4200)||(Batteryval[9]>4200)||(Batteryval[10]>4200)||(Batteryval[11]>4200)||(Batteryval[14]>4200))
					{
						Only_Close_CHG();                        //
						IIC1_write_one_byte_CRC(SYS_STAT,0xFF); //清除状态
						OV_FLAG=1;
					}
     if(OV_FLAG==1)
		 {
					if((Batteryval[0]<4100)&&(Batteryval[1]<4100)&&(Batteryval[4]<4100)&&(Batteryval[5]<4100)&&(Batteryval[6]<4100)&&(Batteryval[9]<4100)&&(Batteryval[10]<4100)&&(Batteryval[11]<4100)&&(Batteryval[14]<4100))
					{
						Only_Open_CHG();                         //
						IIC1_write_one_byte_CRC(SYS_STAT,0xFF); //清除状态
						OV_FLAG=0;
					}
			}
		 
			
					if((Batteryval[0]<2800)||(Batteryval[1]<2800)||(Batteryval[4]<2800)||(Batteryval[5]<2800)||(Batteryval[6]<2800)||(Batteryval[9]<2800)||(Batteryval[10]<2800)||(Batteryval[11]<2800)||(Batteryval[14]<2800))
					{
						Only_Close_DSG();
						IIC1_write_one_byte_CRC(SYS_STAT,0xFF); //清除状态
						UV_FLAG=1;
					}
          if(UV_FLAG==1)
					{
					if((Batteryval[0]>2800)&&(Batteryval[1]>2800)&&(Batteryval[4]>2800)&&(Batteryval[5]>2800)&&(Batteryval[6]>2800)&&(Batteryval[9]>2800)&&(Batteryval[10]>2800)&&(Batteryval[11]>2800)&&(Batteryval[14]>2800))
					{
						Only_Open_DSG();
						IIC1_write_one_byte_CRC(SYS_STAT,0xFF); //清除状态
            UV_FLAG=0;						
					}
		     }
			if(Batteryval[17]>2000)//如果电流大于2000ma，关闭充放电MOS管
			{
			      Close_DSG_CHG();
						IIC1_write_one_byte_CRC(SYS_STAT,0xFF); //清除状态	
				    OC_FLAG=1;
			}
			if( OC_FLAG==1)
			{
						if(Batteryval[17]<2000)//如果电流小于2000ma，打开充放电MOS管
						{
									Open_DSG_CHG();
									IIC1_write_one_byte_CRC(SYS_STAT,0xFF); //清除状态	
									OC_FLAG=0;
						}
						
			}
/*			
						if(Batteryval[18]>Read_Flash(Temp_up))
			{
			      Close_DSG_CHG();
						IIC1_write_one_byte_CRC(SYS_STAT,0xFF); //清除状态	

				    Temp_up_flag = 1;
			}
			if(Temp_up_flag == 1)
			{
			  if(Batteryval[18]<Read_Flash(Temp_up))
				{
					  Open_DSG_CHG();
											IIC1_write_one_byte_CRC(SYS_STAT,0xFF); //清除状态	

				    Temp_up_flag = 0;
					
				}
			
			}		
*/		
			osDelay(200);
	}
}	