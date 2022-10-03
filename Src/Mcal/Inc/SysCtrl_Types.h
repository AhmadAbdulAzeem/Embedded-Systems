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
#define ENABLED          1
#define DISABLED         0

#define    RUN_MODE_CLOCK_CONTROL	                	    0
#define    DEEP_SLEEP_MODE_CONTROL	                        1
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*************************************************************Reset control*******************************************/

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


/*************************************************************Clock control*******************************************/
typedef enum{
    MOSC = 0X0,                     /* Main oscillator */
    PIOSC = 0x1,                    /* Precision internal oscillator */
    PIOSC_DIVIDED_BY_4 = 0x2,       /* Precision internal oscillator / 4 */
    LFIOSC = 0X3                    /* Low-frequency internal oscillator */
}SysCtrl_OscillatorSource;

typedef enum{
    CRYSTAL_VALUE_4_MHz = 0X06, 
    CRYSTAL_VALUE_4_096_MHz = 0X07, 
    CRYSTAL_VALUE_4_9152_MHz = 0X08, 
    CRYSTAL_VALUE_5_MHz_USB = 0X09,
    CRYSTAL_VALUE_5_12_MHz = 0X0A,
    CRYSTAL_VALUE_6_MHz_USB = 0X0B,
    CRYSTAL_VALUE_6_144_MHz = 0X0C,
    CRYSTAL_VALUE_7_3728_MHz = 0X0D,
    CRYSTAL_VALUE_8_MHz_USB = 0X0E,
    CRYSTAL_VALUE_8_192_MHz = 0X0F,
    CRYSTAL_VALUE_10_MHz_USB = 0X10,
    CRYSTAL_VALUE_12_MHz_USB = 0X11,
    CRYSTAL_VALUE_12_288_MHz = 0X12,
    CRYSTAL_VALUE_13_56_MHz = 0X13,
    CRYSTAL_VALUE_14_31818_MHz = 0X14,
    CRYSTAL_VALUE_16_MHz_USB = 0X15,
    CRYSTAL_VALUE_16_384_MHz = 0X16,
    CRYSTAL_VALUE_18_MHz_USB = 0X17,
    CRYSTAL_VALUE_20_MHz_USB = 0X18,
    CRYSTAL_VALUE_24_MHz_USB = 0X19,
    CRYSTAL_VALUE_25_MHz_USB = 0X1A
}SysCtrl_CrystalValueType;


typedef enum{
    SYSDIV_DIVISOR1__RESERVED=0,
    SYSDIV_DIVISOR2_RESERVED,
    SYSDIV_DIVISOR3_66_O_67MHZ,
    SYSDIV_DIVISOR4_50MHZ,
    SYSDIV_DIVISOR5_40MHZ,
    SYSDIV_DIVISOR6_33_O_33MHZ,
    SYSDIV_DIVISOR7_28_O_57MHZ,
    SYSDIV_DIVISOR8_25MHZ,
    SYSDIV_DIVISOR9_22_O_22MHZ,
    SYSDIV_DIVISOR10_20MHZ,
    SYSDIV_DIVISOR11_18_O_18MHZ,
    SYSDIV_DIVISOR12_16_O_67MHZ,
    SYSDIV_DIVISOR13_15_O_38MHZ,
    SYSDIV_DIVISOR14_14_O_29MHZ,
    SYSDIV_DIVISOR15_13_O_33MHZ,
    SYSDIV_DIVISOR16_12_O_5MHZ
}SysCtrl_SysDivisorType;
#endif  /* SYSCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: SysCtrl_Types.h
 *********************************************************************************************************************/
