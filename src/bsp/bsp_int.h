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
*                                         BOARD SUPPORT PACKAGE
*
*                                           TI MSP-EXP432P401R
*                                       LaunchPad Development Kit
*
* Filename      : bsp_int.h
* Version       : V1.01
* Programmer(s) : YS
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                                 MODULE
*
* Note(s) : (1) This header file is protected from multiple pre-processor inclusion through use of the
*               BSP_INT present pre-processor macro definition.
*********************************************************************************************************
*/

#ifndef  BSP_INT_PRESENT
#define  BSP_INT_PRESENT


/*
*********************************************************************************************************
*                                              INCLUDE FILES
*********************************************************************************************************
*/

#include  <lib_def.h>


/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/


#ifdef   BSP_INT_MODULE
#define  BSP_INT_EXT
#else
#define  BSP_INT_EXT  extern
#endif

/*
*********************************************************************************************************
*                                        DEFAULT CONFIGURATION
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           INTERRUPT DEFINES
*********************************************************************************************************
*/

#define  BSP_INT_ID_PSS                               0u
#define  BSP_INT_ID_CS                                1u
#define  BSP_INT_ID_PCM                               2u
#define  BSP_INT_ID_WTD                               3u
#define  BSP_INT_ID_FPU                               4u
#define  BSP_INT_ID_FTCTL                             5u
#define  BSP_INT_ID_COMP0                             6u
#define  BSP_INT_ID_COMP1                             7u
#define  BSP_INT_ID_TA0_0                             8u
#define  BSP_INT_ID_TA0_N                             9u
#define  BSP_INT_ID_TA1_0                            10u
#define  BSP_INT_ID_TA1_N                            11u
#define  BSP_INT_ID_TA2_0                            12u
#define  BSP_INT_ID_TA2_N                            13u
#define  BSP_INT_ID_TA3_0                            14u
#define  BSP_INT_ID_TA3_N                            15u
#define  BSP_INT_ID_EUSCIA0                          16u
#define  BSP_INT_ID_EUSCIA1                          17u
#define  BSP_INT_ID_EUSCIA2                          18u
#define  BSP_INT_ID_EUSCIA3                          19u
#define  BSP_INT_ID_EUSCIB0                          20u
#define  BSP_INT_ID_EUSCIB1                          21u
#define  BSP_INT_ID_EUSCIB2                          22u
#define  BSP_INT_ID_EUSCIB3                          23u
#define  BSP_INT_ID_ADC                              24u
#define  BSP_INT_ID_INT1                             25u
#define  BSP_INT_ID_INT2                             26u
#define  BSP_INT_ID_INTC                             27u
#define  BSP_INT_ID_AES                              28u
#define  BSP_INT_ID_RTC                              29u
#define  BSP_INT_ID_DMA_ERR                          30u
#define  BSP_INT_ID_DMA_INT3                         31u
#define  BSP_INT_ID_DMA_INT2                         32u
#define  BSP_INT_ID_DMA_INT1                         33u
#define  BSP_INT_ID_DMA_INT0                         34u
#define  BSP_INT_ID_PORT1                            35u
#define  BSP_INT_ID_PORT2                            36u
#define  BSP_INT_ID_PORT3                            37u
#define  BSP_INT_ID_PORT4                            38u
#define  BSP_INT_ID_PORT5                            39u
#define  BSP_INT_ID_PORT6                            40u

#define  BSP_INT_ID_MAX                              41u


/*
*********************************************************************************************************
*                                             PERIPH DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               MACRO'S
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                         INTERRUPT SERVICES
*********************************************************************************************************
*/

void  App_Port1_ISR                        (void);

void  BSP_IntClr                           (CPU_INT08U     int_id);

void  BSP_IntDis                           (CPU_INT08U     int_id);

void  BSP_IntDisAll                        (void);

void  BSP_IntEn                            (CPU_INT08U     int_id);

void  BSP_IntInit                          (void);

void  BSP_IntVectSet                       (CPU_INT08U     int_id,
                                            CPU_FNCT_VOID  isr_fnct);

void  BSP_IntHandler                       (CPU_INT16U     src_nbr);

void  BSP_IntHandlerPSS                    (void);
void  BSP_IntHandlerCS                     (void);
void  BSP_IntHandlerPCM                    (void);
void  BSP_IntHandlerWTD                    (void);
void  BSP_IntHandlerFPU                    (void);
void  BSP_IntHandlerFLCTL                  (void);
void  BSP_IntHandlerCOMP0                  (void);
void  BSP_IntHandlerCOMP1                  (void);
void  BSP_IntHandlerTA0_0                  (void);
void  BSP_IntHandlerTA0_N                  (void);
void  BSP_IntHandlerTA1_0                  (void);
void  BSP_IntHandlerTA1_N                  (void);
void  BSP_IntHandlerTA2_0                  (void);
void  BSP_IntHandlerTA2_N                  (void);
void  BSP_IntHandlerTA3_0                  (void);
void  BSP_IntHandlerTA3_N                  (void);
void  BSP_IntHandlerEUSCIA0                (void);
void  BSP_IntHandlerEUSCIA1                (void);
void  BSP_IntHandlerEUSCIA2                (void);
void  BSP_IntHandlerEUSCIA3                (void);
void  BSP_IntHandlerEUSCIB0                (void);
void  BSP_IntHandlerEUSCIB1                (void);
void  BSP_IntHandlerEUSCIB2                (void);
void  BSP_IntHandlerEUSCIB3                (void);
void  BSP_IntHandlerADC14                  (void);
void  BSP_IntHandlerT32_INT1               (void);
void  BSP_IntHandlerT32_INT2               (void);
void  BSP_IntHandlerT32_INTC               (void);
void  BSP_IntHandlerAES                    (void);
void  BSP_IntHandlerRTC                    (void);
void  BSP_IntHandlerDMA_ERR                (void);
void  BSP_IntHandlerDMA_INT3               (void);
void  BSP_IntHandlerDMA_INT2               (void);
void  BSP_IntHandlerDMA_INT1               (void);
void  BSP_IntHandlerDMA_INT0               (void);
void  BSP_IntHandlerPORT1                  (void);
void  BSP_IntHandlerPORT2                  (void);
void  BSP_IntHandlerPORT3                  (void);
void  BSP_IntHandlerPORT4                  (void);
void  BSP_IntHandlerPORT5                  (void);
void  BSP_IntHandlerPORT6                  (void);

#endif
