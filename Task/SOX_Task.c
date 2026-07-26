#include "SOX_Task.h"
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
extern int SOC;
void SOX_Task(void *argument)
{
	while(1)
	{
		  if(	Batteryval[15] >(4100*9))
       {SOC=100;}
				else if((	Batteryval[15] >(4100*9))&&(Batteryval[15]<(4150*9))){SOC=95;}
				else if((Batteryval[15]>(4050*9))&&(Batteryval[15]<(4100*9))){SOC=90;}
				else if((Batteryval[15]>(4000*9))&&(Batteryval[15]<(4050*9))){SOC=88;}
				else if((Batteryval[15]>(3950*9))&&(Batteryval[15]<(4000*9))){SOC=87;}
				else if((Batteryval[15]>(3900*9))&&(Batteryval[15]<(3950*9))){SOC=86;}
				else if((Batteryval[15]>(3900*9))&&(Batteryval[15]<(3950*9))){SOC=85;}
				else if((Batteryval[15]>(3850*9))&&(Batteryval[15]<(3900*9))){SOC=84;}
				else if((Batteryval[15]>(3800*9))&&(Batteryval[15]<(3850*9))){SOC=83;}
				else if((Batteryval[15]>(3750*9))&&(Batteryval[15]<(3800*9))){SOC=82;}
				else if((Batteryval[15]>(3700*9))&&(Batteryval[15]<(3750*9))){SOC=81;}
				else if((Batteryval[15]>(3650*9))&&(Batteryval[15]<(3700*9))){SOC=80;}
				else if((Batteryval[15]>(3600*9))&&(Batteryval[15]<(3650*9))){SOC=79;}
				else if((Batteryval[15]>(3550*9))&&(Batteryval[15]<(3600*9))){SOC=78;}
				else if((Batteryval[15]>(3500*9))&&(Batteryval[15]<(3550*9))){SOC=77;}
				
				else if((Batteryval[15]>(3450*9))&&(Batteryval[15]<(3500*9))){SOC=40;}
				else if((Batteryval[15]>(3400*9))&&(Batteryval[15]<(3500*9))){SOC=30;}
				else if((Batteryval[15]>(3300*9))&&(Batteryval[15]<(3400*9))){SOC=20;}
				else if((Batteryval[15]>(3200*9))&&(Batteryval[15]<(3300*9))){SOC=10;}
				else if((Batteryval[15]>(3100*9))&&(Batteryval[15]<(3200*9))){SOC=5;}
				Batteryval[16] = SOC;
				
				shang[34]=(char)(Batteryval[16] >> 8);
				shang[35]=(char)(Batteryval[16] &0XFF);

				
				shang2[16]=(char)shang[34];
				shang2[17]=(char)shang[35];
				
				can_buf6[4]=(char)shang[34];
				can_buf6[5]=(char)shang[35];
				osDelay(1000);
	}
}