/*
*********************************************************************************************************
*                                            EXAMPLE CODE
*
*               This file is provided as an example on how to use Micrium products.
*
*               Please feel free to use any application code labeled as 'EXAMPLE CODE' in
*               your application products.  Example code may be used as is, in whole or in
*               part, or may be used as a reference only. This file can be modified as
*               required to meet the end-product requirements.
*
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*
*               You can find our product's user manual, API reference, release notes and
*               more information at https://doc.micrium.com.
*               You can contact us at www.micrium.com.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                    MICRIUM BOARD SUPPORT PACKAGE
*
*                                      Texas Instruments MSP432
*                                               on the
*
*                                        TI MSP-EXP432P401R
*                                     LaunchPad Development Kit
*
*
* Filename      : bsp.h
* Version       : V1.00
* Programmer(s) : YS
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                                 MODULE
*
* Note(s) : (1) This header file is protected from multiple pre-processor inclusion through use of the
*               BSP present pre-processor macro definition.
*********************************************************************************************************
*/

#ifndef  BSP_PRESENT
#define  BSP_PRESENT


/*
*********************************************************************************************************
*                                            INCLUDE FILES
*********************************************************************************************************
*/

#include  <cpu.h>
#include  <cpu_core.h>

#include  <lib_def.h>
#include  <lib_ascii.h>


/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/


#ifdef   BSP_MODULE
#define  BSP_EXT
#else
#define  BSP_EXT  extern
#endif


/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/
                                                                /* -                   GPIO REGISTERS                 - */

#define  BSP_GPIO_PORTA_BASE_ADDR       (*(CPU_REG16 *)0x40004C00u)
#define  BSP_GPIO_PORTB_BASE_ADDR       (*(CPU_REG16 *)0x40004C20u)
#define  BSP_GPIO_PORTC_BASE_ADDR       (*(CPU_REG16 *)0x40004C40u)
#define  BSP_GPIO_PORTD_BASE_ADDR       (*(CPU_REG16 *)0x40004C60u)
#define  BSP_GPIO_PORTE_BASE_ADDR       (*(CPU_REG16 *)0x40004C80u)
#define  BSP_GPIO_PORTJ_BASE_ADDR       (*(CPU_REG16 *)0x40004D20u)

#define  BSP_GPIO_P1_BASE_ADDR          0x40004C00u
#define  BSP_GPIO_P2_BASE_ADDR          0x40004C01u
#define  BSP_GPIO_P3_BASE_ADDR          0x40004C20u
#define  BSP_GPIO_P4_BASE_ADDR          0x40004C21u
#define  BSP_GPIO_P5_BASE_ADDR          0x40004C40u
#define  BSP_GPIO_P6_BASE_ADDR          0x40004C41u
#define  BSP_GPIO_P7_BASE_ADDR          0x40004C60u
#define  BSP_GPIO_P8_BASE_ADDR          0x40004C61u
#define  BSP_GPIO_P9_BASE_ADDR          0x40004C80u
#define  BSP_GPIO_P10_BASE_ADDR         0x40004C81u
                                                                /* Px Register OFFSETS                                  */
#define  BSP_GPIO_REG_IN(port_nbr)      (*(CPU_REG08 *)(port_nbr + 0x0u))
#define  BSP_GPIO_REG_OUT(port_nbr)     (*(CPU_REG08 *)(port_nbr + 0x2u))
#define  BSP_GPIO_REG_DIR(port_nbr)     (*(CPU_REG08 *)(port_nbr + 0x4u))
#define  BSP_GPIO_REG_REN(port_nbr)     (*(CPU_REG08 *)(port_nbr + 0x6u))
#define  BSP_GPIO_REG_DS(port_nbr)      (*(CPU_REG08 *)(port_nbr + 0x8u))
#define  BSP_GPIO_REG_SEL0(port_nbr)    (*(CPU_REG08 *)(port_nbr + 0xAu))
#define  BSP_GPIO_REG_SEL1(port_nbr)    (*(CPU_REG08 *)(port_nbr + 0xCu))
#define  BSP_GPIO_REG_IV(port_nbr)      (*(CPU_REG08 *)(port_nbr + 0xEu))
#define  BSP_GPIO_REG_SELC(port_nbr)    (*(CPU_REG08 *)(port_nbr + 0x16u))
#define  BSP_GPIO_REG_IES(port_nbr)     (*(CPU_REG08 *)(port_nbr + 0x18u))
#define  BSP_GPIO_REG_IE(port_nbr)      (*(CPU_REG08 *)(port_nbr + 0x1Au))
#define  BSP_GPIO_REG_IFG(port_nbr)     (*(CPU_REG08 *)(port_nbr + 0x1Cu))

#define  BSP_GPIO_BIT_PIN0              DEF_BIT_00
#define  BSP_GPIO_BIT_PIN1              DEF_BIT_01
#define  BSP_GPIO_BIT_PIN2              DEF_BIT_02
#define  BSP_GPIO_BIT_PIN3              DEF_BIT_03
#define  BSP_GPIO_BIT_PIN4              DEF_BIT_04
#define  BSP_GPIO_BIT_PIN5              DEF_BIT_05
#define  BSP_GPIO_BIT_PIN6              DEF_BIT_06
#define  BSP_GPIO_BIT_PIN7              DEF_BIT_07

#define  BSP_GPIO_LED_ALL               0u
#define  BSP_GPIO_LED1                  1u
#define  BSP_GPIO_LED2_RED              2u
#define  BSP_GPIO_LED2_GREEN            3u
#define  BSP_GPIO_LED2_BLUE             4u
#define  BSP_GPIO_SW1                   1u
#define  BSP_GPIO_SW2                   2u

#define  BSP_GPIO_LED1_PIN              BSP_GPIO_BIT_PIN0
#define  BSP_GPIO_RGBLED_RED_PIN        BSP_GPIO_BIT_PIN0
#define  BSP_GPIO_RGBLED_GREEN_PIN      BSP_GPIO_BIT_PIN1
#define  BSP_GPIO_RGBLED_BLUE_PIN       BSP_GPIO_BIT_PIN2
#define  BSP_GPIO_SW1_PIN               BSP_GPIO_BIT_PIN1
#define  BSP_GPIO_SW2_PIN               BSP_GPIO_BIT_PIN4




/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void         BSP_Init           (void);

void         BSP_LowLevelInit   (void);

void         BSP_Tick_Init      (void);

void         BSP_LED_Toggle     (CPU_INT08U  led);

void         BSP_LED_On         (CPU_INT08U  led);

void         BSP_LED_Off        (CPU_INT08U  led);

void         BSP_GPIO_PinDirSet (CPU_INT32U  port, 
                                 CPU_INT08U  pin,
                                 CPU_BOOLEAN dir);

CPU_BOOLEAN  BSP_PB_StatusGet   (CPU_INT08U  pb );

CPU_INT32U   BSP_CPU_ClkFreq    (void);


/*
*********************************************************************************************************
*                                          CONFIGURATION ERRORS
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                              MODULE END
*********************************************************************************************************
*/

#endif                                                          /* End of module include.                               */
