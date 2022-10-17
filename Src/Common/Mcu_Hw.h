/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition
 *
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
    uint32 VECACT : 8;
    uint32 : 3;
    uint32 RETBASE : 1;
    uint32 VECPEND : 8;
    uint32 : 2;
    uint32 ISRPEND : 1;
    uint32 ISRPRE : 1;
    uint32 : 1;
    uint32 PENDSTCLR : 1;
    uint32 PENDSTSET : 1;
    uint32 UNPENDSV : 1;
    uint32 PENDSV : 1;
    uint32 : 2;
    uint32 NMISET : 1;
} INTCTRL_BF;

typedef union
{
    uint32 R;
    INTCTRL_BF B;
} INTCTRL_Tag;

/***************************************************************NVIC***************************************************/
typedef struct
{
    volatile uint32 EN[5];
    volatile uint32 RESERVED_1[27];
    volatile uint32 DIS[5];
    volatile uint32 RESERVED_2[27];
    volatile uint32 SET_PED[5];
    volatile uint32 RESERVED_3[27];
    volatile uint32 CLR_PED[5];
    volatile uint32 RESERVED_4[27];
    volatile uint32 ACT_INT[5];
    volatile uint32 RESERVED_5[59];
    volatile uint32 PRI[35];
    volatile uint32 RESERVED_6[669];
    volatile uint32 SWTRIG;
} NVIC_REGS_CONFIG;

#define NVIC_REGS ((NVIC_REGS_CONFIG *)(CORTEXM4_PERI_BASE_ADDRESS + 0x100))

/***************************************************************SCB***************************************************/
typedef struct
{
    volatile uint32 CPUID;
    volatile uint32 INTCTRL;
    volatile uint32 VTABLE;
    volatile uint32 APINT;
    volatile uint32 SYSCTRL;
    volatile uint32 CFGCTRL;
    volatile uint32 SYSPRI1;
    volatile uint32 SYSPRI2;
    volatile uint32 SYSPRI3;
    volatile uint32 SYSHNDCTRL;
    volatile uint32 FAULTSTAT;
    volatile uint32 HFAULTSTAT;
    volatile uint32 RESERVED;
    volatile uint32 MMADDR;
    volatile uint32 FAULTADDR;
} SCB_REGS_CONFIG;

#define SCB_REGS ((SCB_REGS_CONFIG *)(CORTEXM4_PERI_BASE_ADDRESS + 0xD00))

/***************************************************************SYS_CTRL***************************************************/
typedef struct
{
    volatile uint32 SYS_CTRL_RESET_REGs[24];
    uint32 Reserved_0[40];
    volatile uint32 SYS_CTRL_RUN_MODE_GC_REGs[24];
    uint32 Reserved_1[40];
    volatile uint32 SYS_CTRL_SLEEP_MODE_GC_REGs[24];
    uint32 Reserved_2[40];
    volatile uint32 SYS_CTRL_DEEP_SLEEP_MODE_GC_REGs[24];
    uint32 Reserved_3[104];
    volatile uint32 SYS_CTRL_PERIPHERAL_READY_REGs[24];
} SYS_CTRL_REGS_CONFIG;

#define SYS_CTRL_REGS ((SYS_CTRL_REGS_CONFIG *)(SYS_CTRL_BASE_ADDRESS + 0x500))

typedef struct
{

    uint32 MOSCDIS : 1;

    uint32 reserved_1 : 3;

    uint32 OSCSRC : 2;
    uint32 XTAL : 5;
    uint32 BYPASS : 1;

    uint32 reserved_2 : 1;

    uint32 PWRDN : 1;

    uint32 reserved_3 : 3;

    uint32 PWMDIV : 3;
    uint32 USEPWMDIV : 1;

    uint32 reserved_4 : 1;

    uint32 USESYSDIV : 1;
    uint32 SYSDIV : 4;

    uint32 ACG : 1;

    uint32 reserved_5 : 4;

} RCC_BIT_FIELD;
typedef union
{
    uint32 reg;
    RCC_BIT_FIELD bit;

} SYS_CTRL_RCC_config;

#define SYS_CTRL_RCC_REG ((volatile SYS_CTRL_RCC_config *)(SYS_CTRL_BASE_ADDRESS + 0x060))
#define SYS_CTRL_MOSCCTL_REG *((volatile uint32 *)(SYS_CTRL_BASE_ADDRESS + 0x07C))

/***************************************************************GPIO***************************************************/
#define GPIO_PORT_A_APB_BASE_ADDRESS 0x40004000
#define GPIO_PORT_B_APB_BASE_ADDRESS 0x40005000
#define GPIO_PORT_C_APB_BASE_ADDRESS 0x40006000
#define GPIO_PORT_D_APB_BASE_ADDRESS 0x40007000
#define GPIO_PORT_E_APB_BASE_ADDRESS 0x40024000
#define GPIO_PORT_F_APB_BASE_ADDRESS 0x40025000

typedef struct
{
    volatile uint32 GPIODATA[256];
    volatile uint32 GPIODIR;
    volatile uint32 GPIOIS;
    volatile uint32 GPIOIBE;
    volatile uint32 GPIOIEV;
    volatile uint32 GPIOIM;
    volatile uint32 GPIORIS;
    volatile uint32 GPIOMIS;
    volatile uint32 GPIOICR;
    volatile uint32 GPIOAFSEL;
    volatile uint32 RESERVED[55];
    // volatile uint32 GPIODR2R;
    // volatile uint32 GPIODR4R;
    // volatile uint32 GPIODR8R;
    volatile uint32 GPIODR_2R_4R_8R[3];
    volatile uint32 GPIOODR;
    // volatile uint32 GPIOPUR;
    // volatile uint32 GPIOPDR;
    volatile uint32 GPIO_PUR_PDR[2];  // pull up and pull down regs
    volatile uint32 GPIOSLR;
    volatile uint32 GPIODEN;
    volatile uint32 GPIOLOCK;
    volatile uint32 GPIOCR;
    volatile uint32 GPIOAMSEL;
    volatile uint32 GPIOPCTL;
    volatile uint32 GPIOADCCTL;
    volatile uint32 GPIODMACTL;
    volatile uint32 GPIOPeriphID4;
    volatile uint32 GPIOPeriphID5;
    volatile uint32 GPIOPeriphID6;
    volatile uint32 GPIOPeriphID7;
    volatile uint32 GPIOPeriphID0;
    volatile uint32 GPIOPeriphID1;
    volatile uint32 GPIOPeriphID2;
    volatile uint32 GPIOPeriphID3;
    volatile uint32 GPIOPCellID0;
    volatile uint32 GPIOPCellID1;
    volatile uint32 GPIOPCellID2;
    volatile uint32 GPIOPCellID3;
} GPIO_GENERAL_REGS;

#define GPIO_PORT_A_REGS ((GPIO_GENERAL_REGS *)(GPIO_PORT_A_APB_BASE_ADDRESS))
#define GPIO_PORT_B_REGS ((GPIO_GENERAL_REGS *)(GPIO_PORT_B_APB_BASE_ADDRESS))
#define GPIO_PORT_C_REGS ((GPIO_GENERAL_REGS *)(GPIO_PORT_C_APB_BASE_ADDRESS))
#define GPIO_PORT_D_REGS ((GPIO_GENERAL_REGS *)(GPIO_PORT_D_APB_BASE_ADDRESS))
#define GPIO_PORT_E_REGS ((GPIO_GENERAL_REGS *)(GPIO_PORT_E_APB_BASE_ADDRESS))
#define GPIO_PORT_F_REGS ((GPIO_GENERAL_REGS *)(GPIO_PORT_F_APB_BASE_ADDRESS))

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS 0xE000E000
#define SYS_CTRL_BASE_ADDRESS 0x400FE000
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#endif /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
