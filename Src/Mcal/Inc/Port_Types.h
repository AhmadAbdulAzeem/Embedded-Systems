/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    PA0 = 0,
    PA1,
    PA2,
    PA3,
    PA4,
    PA5,
    PA6,
    PA7,

    PB0,
    PB1,
    PB2,
    PB3,
    PB4,
    PB5,
    PB6,
    PB7,

    PC0,
    PC1,
    PC2,
    PC3,
    PC4,
    PC5,
    PC6,
    PC7,

    PD0,
    PD1,
    PD2,
    PD3,
    PD4,
    PD5,
    PD6,
    PD7,

    PE0,
    PE1,
    PE2,
    PE3,
    PE4,
    PE5,
    PE6,
    PE7,

    PF0,
    PF1,
    PF2,
    PF3,
    PF4,
    PF5,
    PF6,
    PF7
} Port_PinType;

typedef enum
{
    INPUT = 0,
    OUTPUT
} Port_PinDirectionType;

typedef enum
{
    DIO,
    EXTERNAL_INTERRUPT,
    U0Rx = 1,
    U0Tx = 1,
    CAN1Rx = 8,
    CAN1Tx = 8,
    SSI0Clk = 2,
    SSI0Fss = 2,
    SSI0Rx = 2,
    SSI0Tx = 2,
    I2C1SCL = 3,
    I2C1SDA = 3,
    M1PWM2 = 5,
    M1PWM3 = 5,
    I2C0SCL = 3,
    I2C0SDA = 3,
    T3CCP0 = 7,
    T3CCP1 = 7,
    SSI2Rx = 2,
    SSI2Tx = 2,
    M0PWM0 = 4,
    M0PWM1 = 4,
    T0CCP0 = 7,
    T0CCP1 = 7,
    TCK_SWCLK = 1,
    TMS_SWDIO = 1,
    TDI = 1,
    TDO_SWO = 1,
    T4CCP0 = 7,
    T4CCP1 = 7,
    T5CCP0 = 7,
    T5CCP1 = 7,
    U2Rx = 1,
    U2Tx = 1,
    M0FAULT0 = 4,
    PhA0 = 6,
    PhB0 = 6,
    WT5CCP0 = 7,
    WT5CCP1 = 7,
    NMI = 8,
    U1RTS = 1,
    U1CTS = 1,
    SSI1Rx = 2,
    SSI1Tx = 2,
    SSI1Clk = 2,
    SSI1Fss = 2,
    CAN0Rx = 3,
    CAN0Tx = 3,
    M1PWM4 = 5,
    M1PWM5 = 5,
    M1PWM6 = 5,
    M1PWM7 = 5,
    M1FAULT0 = 5,
    IDX0 = 6,
    T1CCP0 = 7,
    T1CCP1 = 7,
    T2CCP0 = 7,
    USB0EPEN = 8,
    C0o = 9,
    C1o = 9,
    TRD1 = 14,
    TRD0 = 14,
    TRCLK = 14,
} Port_PinModeType;

typedef enum
{
    PULL_UP = 0,
    PULL_DOWN
} Port_PinInternalAttachType;

typedef enum
{
    OUT_PUT_CURRENT_STREGNTH_2MA = 0,
    OUT_PUT_CURRENT_STREGNTH_4MA,
    OUT_PUT_CURRENT_STREGNTH_8MA
} Port_PinOutputCurrentType;

typedef enum{
    LOW = 0,
    HIGH
}Port_PinLevelValueType;

typedef struct 
{
    Port_PinType PinNumber;
    Port_PinModeType PortPinMode;
    Port_PinLevelValueType PortPinLevelValue;
    Port_PinDirectionType PortPinDirection;
    Port_PinInternalAttachType PortPinInternalAttach;
    Port_PinOutputCurrentType PortPinOutputCurrent;
}Port_ConfigType;

typedef uint8 Dio_PortLevelType;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* PORT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/
