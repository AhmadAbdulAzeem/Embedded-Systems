/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SysCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef SYSCTRL_TYPES_H
#define SYSCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum{
    PERIPHERAL_RESET,
    CORE_ONLY_RESET,
    SYSTEM_RESET
}SysCtrl_SoftwareResetType;

typedef enum{
    WATCH_DOG_TIMER = 0,
    GENERAL_PURPOUSE_TIMER_16_32=1,
    GENERAL_PURPOUSE_INPUT_OUTPUT=2,
    MICRO_DIRECT_MEMORY_ACCESS=3,
    HIB=5,
    UART=6,
    SSI=7,
    I2C=8,
    USB_SCB=10,
    CAN=13,
    ADC=14,
    ACMP=15,
    PWM=16,
    QEI=17,
    EEPROM=22,
    WTIMER_32_64=23,
    NONE
}SysCtrl_PeripheralType;

typedef enum{
    WATCHDOG_MODULE_0 = 0,
    WATCHDOG_MODULE_1 = 1,
    GENERAL_PURPOUSE_TIMER_16_32_BIT_MODULE_0 = 0,
    GENERAL_PURPOUSE_TIMER_16_32_BIT_MODULE_1 = 1,
    GENERAL_PURPOUSE_TIMER_16_32_BIT_MODULE_2 = 2,
    GENERAL_PURPOUSE_TIMER_16_32_BIT_MODULE_3 = 3,
    GENERAL_PURPOUSE_TIMER_16_32_BIT_MODULE_4 = 4,
    GENERAL_PURPOUSE_TIMER_16_32_BIT_MODULE_5 = 5,
    GPIO_PORT_A_MODULE = 0,
    GPIO_PORT_B_MODULE = 1,
    GPIO_PORT_C_MODULE = 2,
    GPIO_PORT_D_MODULE = 3,
    GPIO_PORT_E_MODULE = 4,
    GPIO_PORT_F_MODULE = 5,
    UDMA_MODULE = 0,
    HIBERNATION_MODULE = 0,
    UART_MODULE_0 = 0,
    UART_MODULE_1 = 1,
    UART_MODULE_2 = 2,
    UART_MODULE_3 = 3,
    UART_MODULE_4 = 4,
    UART_MODULE_5 = 5,
    UART_MODULE_6 = 6,
    UART_MODULE_7 = 7,
    SSI_MODULE_0 = 0,
    SSI_MODULE_1 = 1,
    SSI_MODULE_2 = 2,
    SSI_MODULE_3 = 3,
    I2C_MODULE_0 = 0,
    I2C_MODULE_1 = 1,
    I2C_MODULE_2 = 2,
    I2C_MODULE_3 = 3,
    USB_MODULE = 0,
    CAN_MODULE_0 = 0,
    CAN_MODULE_1 = 1,
    ADC_MODULE_0 = 0,
    ADC_MODULE_1 = 1,
    ANALOG_COMPARATOR_MODULE = 0,
    PWM_MODULE_0 = 0,
    PWM_MODULE_1 = 1,
    QEI_MODULE_0 = 0,
    QEI_MODULE_1 = 1,
    EEPROM_MODULE = 0,
    WIDE_GENERAL_PURPOUSE_TIMER_32_64_BIT_MODULE_0 = 0,
    WIDE_GENERAL_PURPOUSE_TIMER_32_64_BIT_MODULE_1 = 1,
    WIDE_GENERAL_PURPOUSE_TIMER_32_64_BIT_MODULE_2 = 2,
    WIDE_GENERAL_PURPOUSE_TIMER_32_64_BIT_MODULE_3 = 3,
    WIDE_GENERAL_PURPOUSE_TIMER_32_64_BIT_MODULE_4 = 4,
    WIDE_GENERAL_PURPOUSE_TIMER_32_64_BIT_MODULE_5 = 5
}SysCtrl_ModuleType;

/*
 * softare_reset: which sw source user wants to reset
 * peripheral: which peripheral user wants to reset if he choose softare_reset: PERIPHERAL_RESET
 * module: you need to specify which module you want to resete 
 * EX: if user chooses peripheral parameter to be (GENERAL_PURPOUSE_INPUT_OUTPUT) he needs to specify which peripheral so set module parameter to which port like (GPIO_PORT_A_MODULE)
 */
typedef struct{
    SysCtrl_SoftwareResetType softare_reset;
    SysCtrl_PeripheralType peripheral;
    SysCtrl_ModuleType module;
}SysCtrl_ConfigType;

#endif  /* SYSCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: SysCtrl_Types.h
 *********************************************************************************************************************/
