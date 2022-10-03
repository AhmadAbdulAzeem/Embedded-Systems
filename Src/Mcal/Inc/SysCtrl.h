/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SysCtrl.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef SYSCTRL_H
#define SYSCTRL_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "SysCtrl_Types.h"
#include "SysCtrl_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
extern SysCtrl_ConfigType SysCtrlreset_Config;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
void SysCtrl_Reset(void);
void SysCtrl_ClockInit(void);
void SysCtrl_EnableClockRunMode(SysCtrl_PeripheralType peripheral, SysCtrl_ModuleType peripheral_module);
void SysCtrl_DisableClockRunMode(SysCtrl_PeripheralType peripheral, SysCtrl_ModuleType peripheral_module);
void SysCtrl_EnableClockSleepMode(SysCtrl_PeripheralType peripheral, SysCtrl_ModuleType peripheral_module);
void SysCtrl_DisableClockSleepMode(SysCtrl_PeripheralType peripheral, SysCtrl_ModuleType peripheral_module);
void SysCtrl_EnableClockDeepSleepMode(SysCtrl_PeripheralType peripheral, SysCtrl_ModuleType peripheral_module);
void SysCtrl_DisableClockDeepSleepMode(SysCtrl_PeripheralType peripheral, SysCtrl_ModuleType peripheral_module);
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

 
#endif  /* SYSCTRL_H */

/**********************************************************************************************************************
 *  END OF FILE: SysCtrl.h
 *********************************************************************************************************************/
