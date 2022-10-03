/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SysCtrl_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef SYSCTRL_CFG_H
#define SYSCTRL_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "SysCtrl_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*
 * MOSC: Main oscillator 
 * PIOSC: Precision internal oscillator 
 * PIOSC_DIVIDED_BY_4: Precision internal oscillator / 4 
 * LFIOSC = 0X3: Low-frequency internal oscillator 
 */
#define OSCILLATOR_SOURCE MOSC

/*
    CRYSTAL_VALUE_4_MHz  
    CRYSTAL_VALUE_4_096_MHz  
    CRYSTAL_VALUE_4_9152_MHz 
    CRYSTAL_VALUE_5_MHz_USB
    CRYSTAL_VALUE_5_12_MHz 
    CRYSTAL_VALUE_6_MHz_USB 
    CRYSTAL_VALUE_6_144_MHz 
    CRYSTAL_VALUE_7_3728_MHz
    CRYSTAL_VALUE_8_MHz_USB 
    CRYSTAL_VALUE_8_192_MHz 
    CRYSTAL_VALUE_10_MHz_USB
    CRYSTAL_VALUE_12_MHz_USB
    CRYSTAL_VALUE_12_288_MHz
    CRYSTAL_VALUE_13_56_MHz
    CRYSTAL_VALUE_14_31818_MHz
    CRYSTAL_VALUE_16_MHz_USB
    CRYSTAL_VALUE_16_384_MHz
    CRYSTAL_VALUE_18_MHz_USB
    CRYSTAL_VALUE_20_MHz_USB
    CRYSTAL_VALUE_24_MHz_USB
    CRYSTAL_VALUE_25_MHz_USB
*/
#define CRYSTAL_VALUE CRYSTAL_VALUE_16_MHz_USB

/*
    -ENABLED
    -DISABLED
*/
#define PLL_STATE      ENABLED

/*
    -ENABLED
    -DISABLED
*/
#define DIVIDER_STATE   ENABLED


/*
    SYSDIV_DIVISOR1__RESERVED,
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
*/
#define SSDIV_DIVISOR   SYSDIV_DIVISOR12_16_O_67MHZ

/*
    -RUN_MODE_CLOCK_CONTROL
    -DEEP_SLEEP_MODE_CONTROL
*/
#define SLEEP_MODE_CONTROL   RUN_MODE_CLOCK_CONTROL

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

 
#endif  /* SYSCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: SysCtrl_Cfg.h
 *********************************************************************************************************************/
