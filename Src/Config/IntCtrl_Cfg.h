/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_CFG_H
#define INTCTRL_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*
 * This configuration parameter to choose number of groups and subgroups
 * Choose one of the following options
 * NO_OF_GROUPS_8_NO_OF_SUBGROUPS_1 
 * NO_OF_GROUPS_4_NO_OF_SUBGROUPS_2
 * NO_OF_GROUPS_2_NO_OF_SUBGROUPS_4
 * NO_OF_GROUPS_1_NO_OF_SUBGROUPS_8
 */

#define NO_OF_GROUPS_AND_NO_OF_SUBGROUPS NO_OF_GROUPS_2_NO_OF_SUBGROUPS_4
#define NVIC_GROUP_SUBGROUP_PRIORITY GROUPPRIORITY_0_SUBPRIORITY_1_XYY
#define MAX_NUMBER_OF_INTERRUPTS 7

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


 
#endif  /* INTCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
