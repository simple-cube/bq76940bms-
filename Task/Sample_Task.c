#include "Sample_Task.h"

void SampleTask(void *argument)
{	
	  Get_Battery1();
    Get_Battery2();
    //Get_Battery3();
	 // Get_Battery4();
	  Get_Battery5();
	  Get_Battery6();
	  Get_Battery7();
	 // Get_Battery8();
	  //Get_Battery9();
	  Get_Battery10();
	  Get_Battery11();
    Get_Battery12();
    //Get_Battery13();
   // Get_Battery14();
    Get_Battery15(); 	
//		Get_Update_ALL_Data();//总电压
		Get_Pack_Voltage(9);//总电压
		Get_BQ1_2_Temp();
    Get_BQ_Current();	
    BMS_STA();
	  osDelay(100);

}
