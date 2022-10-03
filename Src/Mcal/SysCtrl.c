/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SysCtrl.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SysCtrl.h"
#include "Mcu_Hw.h"
#include "Common_Macros.h"

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
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void SysCtrl_Reset(void)
{
    if(SysCtrlreset_Config.softare_reset == SYSTEM_RESET)
    {
        SCB_REGS->APINT = 0x05FA0000;
        SET_BIT((SCB_REGS->APINT), 2);
        return;
    }
    else if(SysCtrlreset_Config.softare_reset == CORE_ONLY_RESET)
    {
        SCB_REGS->APINT = 0x05FA0000;
        SET_BIT((SCB_REGS->APINT), 0);
        return;
    }
    else /* peripheral reset */
    {
        /* set reset bit */
        SYS_CTRL_REGS->SYS_CTRL_RESET_REGs[SysCtrlreset_Config.peripheral] |= 1 << SysCtrlreset_Config.module;
        /* clear reset bit */
        SYS_CTRL_REGS->SYS_CTRL_RESET_REGs[SysCtrlreset_Config.peripheral] &= ~(1 << SysCtrlreset_Config.module);
        /* wait untill the peripheral is ready */
        while((SYS_CTRL_REGS->SYS_CTRL_PERIPHERAL_READY_REGs[SysCtrlreset_Config.peripheral] >> SysCtrlreset_Config.module  & 1) == 0);
    }
}

void SysCtrl_ClockInit(void)
{
    #if OSCILLATOR_SOURCE == MOSC
        /* enable the main oscillator */
        SYS_CTRL_RCC_REG->bit.MOSCDIS = 0;
        SYS_CTRL_RCC_REG->bit.OSCSRC = OSCILLATOR_SOURCE;
        SYS_CTRL_RCC_REG->bit.XTAL = CRYSTAL_VALUE;
        /* MOSC monitor circuit enable */
        SYS_CTRL_MOSCCTL_REG |= 1;
        /* indecate a crystall connected to the OSC1_OSC2   */
        SYS_CTRL_MOSCCTL_REG &= ~(1<<2);
    #else
        SYS_CTRL_RCC_REG->bit.OSCSRC = OSCILLATOR_SOURCE;
    #endif
    
    #if(PLL_STATE == ENABLED)
    {
        SYS_CTRL_RCC_REG->bit.PWRDN = 0;
        SYS_CTRL_RCC_REG->bit.BYPASS = 0;
    }
    #else
    {
        SYS_CTRL_RCC_REG->bit.BYPASS = 1;
        SYS_CTRL_RCC_REG->bit.BYPASS = 0;
        // while(BIT_IS_CLEAR(SYS_CTRL_PLL_STAT,0));
    }
    #endif

    /*disable / enable SYSDIV*/
    SYS_CTRL_RCC_REG->bit.USESYSDIV = DIVIDER_STATE;
    SYS_CTRL_RCC_REG->bit.SYSDIV = SSDIV_DIVISOR;  

    /* TODO: Enable and disable divisor for PWM */
    
    /*choose sleep mode control*/
    SYS_CTRL_RCC_REG->bit.ACG = SLEEP_MODE_CONTROL;  
}

/**********************************************************************************************************************
 *  END OF FILE: SysCtrl.c
 *********************************************************************************************************************/
