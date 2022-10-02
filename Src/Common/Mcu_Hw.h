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
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;

typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;

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
}NVIC_REGS_CONFIG;

#define NVIC_REGS        ((NVIC_REGS_CONFIG *)(CORTEXM4_PERI_BASE_ADDRESS+0x100))


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
}SCB_REGS_CONFIG;

#define SCB_REGS        ((SCB_REGS_CONFIG *)(CORTEXM4_PERI_BASE_ADDRESS+0xD00))

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
}SYS_CTRL_REGS_CONFIG;

#define SYS_CTRL_REGS        ((SYS_CTRL_REGS_CONFIG *)(SYS_CTRL_BASE_ADDRESS+0x500))



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define SYS_CTRL_BASE_ADDRESS                  0x400FE000
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
