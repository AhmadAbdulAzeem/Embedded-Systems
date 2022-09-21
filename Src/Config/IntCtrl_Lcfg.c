/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl_Lcfg.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Cfg.h"
#include "IntCtrl_Types.h"
#include "Mcu_Hw.h"
#include "IntCtrl.h"

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint8 nvic_interrupts[NVIC_MAX_NUMBER_OF_INTERRUPTS] = {GPIO_Port_A, GPIO_Port_B, GPIO_Port_C, GPIO_Port_D, UART0, SSI0, CAN0};
// make sure to follow as configuration parameter NO_OF_GROUPS_AND_NO_OF_SUBGROUPS in IntCtrl_Cfg.h
// every interrupt has a priority in group_subgroup_priorites array  one to one so interupt interrupts[0] takes priority group_subgroup_priorites[0]
uint8 nvic_group_subgroup_priorites[NVIC_MAX_NUMBER_OF_INTERRUPTS] = {GROUPPRIORITY_0_SUBPRIORITY_0_XYY,
                                                                      GROUPPRIORITY_0_SUBPRIORITY_1_XYY,
                                                                      GROUPPRIORITY_0_SUBPRIORITY_2_XYY,
                                                                      GROUPPRIORITY_0_SUBPRIORITY_3_XYY,
                                                                      GROUPPRIORITY_1_SUBPRIORITY_0_XYY,
                                                                      GROUPPRIORITY_1_SUBPRIORITY_1_XYY,
                                                                      GROUPPRIORITY_1_SUBPRIORITY_2_XYY};

uint8 scb_interrupts[SCB_MAX_NUMBER_OF_INTERRUPTS] = {Memory_Management, Bus_Fault};
uint8 scb_group_subgroup_priorites[NVIC_MAX_NUMBER_OF_INTERRUPTS] = {GROUPPRIORITY_1_SUBPRIORITY_0_XYY,
                                                                     GROUPPRIORITY_1_SUBPRIORITY_1_XYY
                                                                     };

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Lcfg.c
 *********************************************************************************************************************/
