#include "IntCtrl.h"
#include "SysCtrl.h"
#include "Port.h"

int main(void)
{
	Port_ConfigType PortConfig = {PF4, DIO, HIGH, OUTPUT, PULL_UP, OUT_PUT_CURRENT_STREGNTH_8MA};
	//IntCrtl_Init();
	//SysCtrl_Reset();
	// SysCtrl_ClockInit();
	SysCtrl_EnableClockRunMode(GENERAL_PURPOUSE_INPUT_OUTPUT, GPIO_PORT_F_MODULE);
	Port_Init(&PortConfig);
	Dio_WriteChannel(PF4, HIGH);
	while(1)
	{
		
	}
}
