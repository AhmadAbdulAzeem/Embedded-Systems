#include "IntCtrl.h"
#include "SysCtrl.h"
#include "Port.h"

void delayMs(int n);

int main(void)
{
	Port_ConfigType PortConfig1 = {PF4, DIO, HIGH, OUTPUT, PULL_UP, OUT_PUT_CURRENT_STREGNTH_8MA};
	Port_ConfigType PortConfig2 = {PF2, DIO, HIGH, OUTPUT, PULL_UP, OUT_PUT_CURRENT_STREGNTH_8MA};
	//IntCrtl_Init();
	//SysCtrl_Reset();
	// SysCtrl_ClockInit();
	SysCtrl_EnableClockRunMode(GENERAL_PURPOUSE_INPUT_OUTPUT, GPIO_PORT_F_MODULE);
	Port_Init(&PortConfig1);
	Port_Init(&PortConfig2);
	// Dio_WritePort(PORTF, 0b00010100);
	Dio_WriteChannel(PF4, HIGH);
	while(1)
	{
		delayMs(1000);
		Dio_FlipChannel(PF4);
	}
}

/* delay n milliseconds (16 MHz CPU clock) */
void delayMs(int n)
{
	int i, j;
	for(i = 0 ; i < n; i++)
		for(j = 0; j < 3180; j++)
		{} /* do nothing for 1 ms */
}