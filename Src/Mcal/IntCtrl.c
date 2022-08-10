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
    /* TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
    APINT = (0x05FA0000 | (NO_OF_GROUPS_AND_NO_OF_SUBGROUPS << 8));

    /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/
    /* TODO: Assign Group\Subgroup priority in SCB_SYSPRIx Registers */
    /* TODO: Make an array for group subgroup priority for each interrupt */
    for(uint8 i = 0; i < MAX_NUMBER_OF_INTERRUPTS;i++)
    {
        remainder = interrupts[i] % 4;
        if(remainder == 0)
            NVIC_PRI_REGS->PRI[interrupts[i]/4] |= (NVIC_GROUP_SUBGROUP_PRIORITY << 5);
        else if(remainder == 1)
            NVIC_PRI_REGS->PRI[interrupts[i]/4] |= (NVIC_GROUP_SUBGROUP_PRIORITY << 13);
        else if(remainder == 2)
            NVIC_PRI_REGS->PRI[interrupts[i]/4] |= (NVIC_GROUP_SUBGROUP_PRIORITY << 21);
        else if(remainder == 3)
            NVIC_PRI_REGS->PRI[interrupts[i]/4] |= (NVIC_GROUP_SUBGROUP_PRIORITY << 29);
    }

    /*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
    /*TODO : Enable\Disable based on user configurations in SCB_Sys Registers */
    for(uint8 j =0; j < MAX_NUMBER_OF_INTERRUPTS; j++)
    {
        remainder = interrupts[j] % 32;
        NVIC_EN_REGS->EN[interrupts[j]/32] |= (1 << remainder); 
    }
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
