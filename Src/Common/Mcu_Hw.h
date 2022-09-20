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
/**********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
#define PRI0                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x400))
#define EN0                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
