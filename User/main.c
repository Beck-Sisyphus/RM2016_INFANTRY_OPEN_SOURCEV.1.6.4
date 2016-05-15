#include "main.h"
uint32_t Upload_Speed = 1;   // Data upload speed, unit: Hz
#define upload_time (1000000/Upload_Speed)  //Calculating the upload speed, unit: us
uint16_t  power1=0,power2=0;
uint32_t system_micrsecond;   // System time, unit: ms
int main(void)
{
	ControtLoopTaskInit();   //app init
	RemoteTaskInit();
	delay_ms(800);
	BSP_Init();
	system_micrsecond = Get_Time_Micros();
	while(1)
	{
		IMU_getYawPitchRoll(angle);
		if((Get_Time_Micros() - system_micrsecond) > upload_time)
		{
			system_micrsecond = Get_Time_Micros();
			UploadParameter();   //upload data to the PC
			delay_ms(1);
		}
	}
}
