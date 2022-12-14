/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Port.h"

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
GPIO_GENERAL_REGS *GPIO_ARR[6] = {GPIO_PORT_A_REGS,
                                  GPIO_PORT_B_REGS,
                                  GPIO_PORT_C_REGS,
                                  GPIO_PORT_D_REGS,
                                  GPIO_PORT_E_REGS,
                                  GPIO_PORT_F_REGS};
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/*
 * TODO: configure more than one pin ConfigPtr should be pointer to array
 * TODO: Handle interrupts and alternative function
 */
void Port_Init(const Port_ConfigType *ConfigPtr)
{
    /* Set the direction of the GPIO port pins by programming the GPIODIR register. */
    if (ConfigPtr->PortPinDirection == OUTPUT)
        GPIO_ARR[(ConfigPtr->PinNumber) / 8]->GPIODIR |= 1 << ((ConfigPtr->PinNumber) % 8);
    else
        GPIO_ARR[(ConfigPtr->PinNumber) / 8]->GPIODIR &= ~(1 << ((ConfigPtr->PinNumber) % 8));

    GPIO_ARR[(ConfigPtr->PinNumber) / 8]->GPIODR_2R_4R_8R[ConfigPtr->PortPinOutputCurrent] |= 1 << ((ConfigPtr->PinNumber) % 8);

    GPIO_ARR[(ConfigPtr->PinNumber) / 8]->GPIO_PUR_PDR[ConfigPtr->PortPinInternalAttach] |= 1 << ((ConfigPtr->PinNumber) % 8);

    GPIO_ARR[(ConfigPtr->PinNumber) / 8]->GPIODEN |= 1 << ((ConfigPtr->PinNumber) % 8);
}

void Dio_WriteChannel(Port_PinType ChannelId, Port_PinLevelValueType Level)
{
    if (Level == HIGH)
        GPIO_ARR[ChannelId / 8]->GPIODATA[255] |= 1 << (ChannelId % 8);
    else
        GPIO_ARR[ChannelId / 8]->GPIODATA[255] &= ~(1 << (ChannelId % 8));
}

Port_PinLevelValueType Dio_ReadChannel(Port_PinType ChannelId)
{
    uint8 data;
    data = GPIO_ARR[ChannelId / 8]->GPIODATA[255];
    return (1 & (data >> (ChannelId % 8)));
}

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    uint8 data;
    data = GPIO_ARR[PortId]->GPIODATA[255];
    return data;
}

void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    GPIO_ARR[PortId]->GPIODATA[255] = Level;
}

void Dio_FlipChannel(Port_PinType ChannelId)
{
    GPIO_ARR[ChannelId / 8]->GPIODATA[255] ^= 1 << (ChannelId % 8);
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
