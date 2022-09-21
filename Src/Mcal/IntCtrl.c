/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"
#include "Mcu_Hw.h"
#include "IntCtrl_Cfg.h"
#include "IntCtrl_types.h"

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void IntCrtl_Init(void)
 * \Description     : initialize Nvic\SCB Module by parsing the Configuration
 *                    into Nvic\SCB registers
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void IntCrtl_Init(void)
{
    uint8 remainder;
    /* Configure Grouping\SubGrouping System in APINT register in SCB*/
    SCB_REGS->APINT = (0x05FA0000 | (NO_OF_GROUPS_AND_NO_OF_SUBGROUPS << 8));

    /* Assign Group\Subgroup priority in NVIC_PRIx Nvic Registers*/
    /* give each interrupt a different group and subgroup priority */
    for(uint8 i = 0; i < NVIC_MAX_NUMBER_OF_INTERRUPTS;i++)
    {
        remainder = nvic_interrupts[i] % 4;
        if(remainder == 0) // access INTA field
            NVIC_REGS->PRI[nvic_interrupts[i]/4] |= (nvic_group_subgroup_priorites[i] << 5);
        else if(remainder == 1) // access INTB field
            NVIC_REGS->PRI[nvic_interrupts[i]/4] |= (nvic_group_subgroup_priorites[i] << 13);
        else if(remainder == 2) // access INTC field
            NVIC_REGS->PRI[nvic_interrupts[i]/4] |= (nvic_group_subgroup_priorites[i] << 21);
        else if(remainder == 3) // access INTD field
            NVIC_REGS->PRI[nvic_interrupts[i]/4] |= (nvic_group_subgroup_priorites[i] << 29);
    }

    /* Assign Group\Subgroup priority in SCB_SYSPRIx Registers */
    for(uint8 j = 0; j < SCB_MAX_NUMBER_OF_INTERRUPTS; j++)
    {
        if(scb_interrupts[j] == Memory_Management)
            SCB_REGS->SYSPRI1 |= scb_group_subgroup_priorites[j] << 5;
        else if(scb_interrupts[j] == Bus_Fault)
            SCB_REGS->SYSPRI1 |= scb_group_subgroup_priorites[j] << 13;
        else if(scb_interrupts[j] == Usage_Fault)
            SCB_REGS->SYSPRI1 |= scb_group_subgroup_priorites[j] << 21;
        else if(scb_interrupts[j] == SVCall)
            SCB_REGS->SYSPRI2 |= scb_group_subgroup_priorites[j] << 29;
        else if(scb_interrupts[j] == Debug_Monitor)
            SCB_REGS->SYSPRI3 |= scb_group_subgroup_priorites[j] << 5;
        else if(scb_interrupts[j] == PendSV)
            SCB_REGS->SYSPRI3 |= scb_group_subgroup_priorites[j] << 21;
        else if(scb_interrupts[j] == SysTick)
            SCB_REGS->SYSPRI3 |= scb_group_subgroup_priorites[j] << 29;
    }

    /* Enable\Disable based on user configurations in NVIC_ENx Registers */
    for(uint8 k =0; k < NVIC_MAX_NUMBER_OF_INTERRUPTS; k++)
    {
        remainder = nvic_interrupts[k] % 32;
        NVIC_REGS->EN[nvic_interrupts[k]/32] |= (1 << remainder); 
    }

    /* Enable\Disable based on user configurations in SCB_Sys Registers */
    /* we can only enable memory and bus, usage faults as mentioned in datasheet in SYSHNDCTRL register */
    for(uint8 m = 0; m < SCB_MAX_NUMBER_OF_INTERRUPTS; m++)
    {
        if(scb_interrupts[m] == Memory_Management)
            SCB_REGS->SYSHNDCTRL |= 1 << 16;
        else if(scb_interrupts[m] == Bus_Fault)
            SCB_REGS->SYSHNDCTRL |= 1 << 17;
        else if(scb_interrupts[m] == Usage_Fault)
            SCB_REGS->SYSHNDCTRL |= 1 << 18;
    }
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
