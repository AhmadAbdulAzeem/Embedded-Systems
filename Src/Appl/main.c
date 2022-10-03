#include "IntCtrl.h"
#include "SysCtrl.h"

int main(void)
{
	//IntCrtl_Init();
	//SysCtrl_Reset();
	SysCtrl_ClockInit();
	SysCtrl_EnableClockRunMode(GENERAL_PURPOUSE_INPUT_OUTPUT, GPIO_PORT_A_MODULE);
	while(1)
	{
		
	}
}
