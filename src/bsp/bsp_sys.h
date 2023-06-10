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
*                                    MICRIUM BOARD SUPPORT PACKAGE
*
*                                      Texas Instruments MSP432
*                                               on the
*
*                                        TI MSP-EXP432P401R
*                                     LaunchPad Development Kit
*
* Filename      : bsp_sys.h
* Version       : V1.01
* Programmer(s) : YS
*********************************************************************************************************
*/

#include  <cpu.h>


/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/

#define  MHZ                     1000000u


#define  BSP_CGU_LOCK_TIMEOUT     0xFFFFu


/*
*********************************************************************************************************
*                                             REGISTERS
*********************************************************************************************************
*/

                                                                /* -                SCS REGISTER DEFINES              - */
#define  BSP_SYS_SCS_BASE_ADDR                    0xE000E000u
#define  BSP_SYS_CGU_BASE_ADDR                    0x40016000u
#define  BSP_SYS_PORTB_BASE                       0x40005080u
#define  BSP_SYS_PORTC_BASE                       0x40005100u
#define  BSP_SYS_PORTE_BASE                       0x40005200u
#define  BSP_SYS_DPM_BASE_ADDR                    0x40017000u


#define  BSP_SYS_REG_SCS_ICTR                     (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0x004u))
#define  BSP_SYS_REG_SCS_ACTLR                    (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0x008u))
#define  BSP_SYS_REG_SCS_STCSR                    (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0x010u))
#define  BSP_SYS_REG_SCS_STRVR                    (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0x014u))
#define  BSP_SYS_REG_SCS_CPUID                    (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD00u))
#define  BSP_SYS_REG_SCS_ICSR                     (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD04u))
#define  BSP_SYS_REG_SCS_VTOR                     (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD08u))
#define  BSP_SYS_REG_SCS_AIRCR                    (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD0Cu))
#define  BSP_SYS_REG_SCS_SCR                      (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD10u))
#define  BSP_SYS_REG_SCS_CCR                      (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD14u))
#define  BSP_SYS_REG_SCS_SHPR1                    (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD18u))
#define  BSP_SYS_REG_SCS_SHPR2                    (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD1Cu))
#define  BSP_SYS_REG_SCS_SHPR3                    (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD20u))
#define  BSP_SYS_REG_SCS_SHCSR                    (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD24u))
#define  BSP_SYS_REG_SCS_CFSR                     (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD28u))
#define  BSP_SYS_REG_SCS_HFSR                     (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD2Cu))
#define  BSP_SYS_REG_SCS_DFSR                     (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD30u))
#define  BSP_SYS_REG_SCS_MMFAR                    (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD34u))
#define  BSP_SYS_REG_SCS_BFAR                     (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD38u))
#define  BSP_SYS_REG_SCS_AFSR                     (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD3Cu))
#define  BSP_SYS_REG_SCS_ID_PFR0                  (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD40u))
#define  BSP_SYS_REG_SCS_ID_PFR1                  (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD44u))
#define  BSP_SYS_REG_SCS_ID_DFR0                  (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD48u))
#define  BSP_SYS_REG_SCS_ID_AFR0                  (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD4Cu))
#define  BSP_SYS_REG_SCS_ID_MMFR0                 (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD50u))
#define  BSP_SYS_REG_SCS_ID_MMFR1                 (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD54u))
#define  BSP_SYS_REG_SCS_ID_MMFR2                 (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD58u))
#define  BSP_SYS_REG_SCS_ID_MMFR3                 (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD5Cu))
#define  BSP_SYS_REG_SCS_ISAR0                    (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD60u))
#define  BSP_SYS_REG_SCS_ID_ISAR1                 (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD64u))
#define  BSP_SYS_REG_SCS_ID_ISAR2                 (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD68u))
#define  BSP_SYS_REG_SCS_ID_ISAR3                 (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD6Cu))
#define  BSP_SYS_REG_SCS_ID_ISAR4                 (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xD70u))
#define  BSP_SYS_REG_SCS_ID_DHCSR                 (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xDF0u))
#define  BSP_SYS_REG_SCS_STIR                     (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xF00u))

#define  BSP_SYS_REG_SCS_PID4                     (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xFD0u))
#define  BSP_SYS_REG_SCS_PID5                     (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xFD4u))
#define  BSP_SYS_REG_SCS_PID6                     (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xFD8u))
#define  BSP_SYS_REG_SCS_PID7                     (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xFDCu))
#define  BSP_SYS_REG_SCS_PID0                     (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xFE0u))
#define  BSP_SYS_REG_SCS_PID1                     (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xFE4u))
#define  BSP_SYS_REG_SCS_PID2                     (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xFE8u))
#define  BSP_SYS_REG_SCS_PID3                     (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xFECu))
#define  BSP_SYS_REG_SCS_CID0                     (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xFF0u))
#define  BSP_SYS_REG_SCS_CID1                     (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xFF4u))
#define  BSP_SYS_REG_SCS_CID2                     (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xFF8u))
#define  BSP_SYS_REG_SCS_CID3                     (*(CPU_REG32 *)(BSP_SYS_SCS_BASE_ADDR + 0xFFCu))

#define  BSP_SYS_REG_WDTCTL                       (*(CPU_REG16 *)(0x4000480C)


#define  BSP_SYS_REG_CGU_CTL                      (*(CPU_REG32 *)(BSP_SYS_CGU_BASE_ADDR + 0x00u))
#define  BSP_SYS_REG_CGU_STAT                     (*(CPU_REG32 *)(BSP_SYS_CGU_BASE_ADDR + 0x04u))
#define  BSP_SYS_REG_CGU_DIV                      (*(CPU_REG32 *)(BSP_SYS_CGU_BASE_ADDR + 0x08u))
#define  BSP_SYS_REG_CGU_CLKOUTSEL                (*(CPU_REG32 *)(BSP_SYS_CGU_BASE_ADDR + 0x0Cu))
#define  BSP_SYS_REG_CGU_OSCWDCTL                 (*(CPU_REG32 *)(BSP_SYS_CGU_BASE_ADDR + 0x10u))
#define  BSP_SYS_REG_CGU_TSCTL                    (*(CPU_REG32 *)(BSP_SYS_CGU_BASE_ADDR + 0x14u))
#define  BSP_SYS_REG_CGU_TSVALUE0                 (*(CPU_REG32 *)(BSP_SYS_CGU_BASE_ADDR + 0x18u))
#define  BSP_SYS_REG_CGU_TSVALUE1                 (*(CPU_REG32 *)(BSP_SYS_CGU_BASE_ADDR + 0x1Cu))
#define  BSP_SYS_REG_CGU_TSCOUNT0                 (*(CPU_REG32 *)(BSP_SYS_CGU_BASE_ADDR + 0x20u))
#define  BSP_SYS_REG_CGU_TSCOUNT1                 (*(CPU_REG32 *)(BSP_SYS_CGU_BASE_ADDR + 0x24u))

#define  BSP_SYS_REG_PORTB_FER                    (*(CPU_REG16 *)(BSP_SYS_PORTB_BASE    + 0x00u))
#define  BSP_SYS_REG_PORTB_MUX                    (*(CPU_REG16 *)(BSP_SYS_PORTB_BASE    + 0x30u))

#define  BSP_SYS_REG_PORTC_FER                    (*(CPU_REG16 *)(BSP_SYS_PORTC_BASE    + 0x00u))
#define  BSP_SYS_REG_PORTC_MUX                    (*(CPU_REG16 *)(BSP_SYS_PORTC_BASE    + 0x30u))

#define  BSP_SYS_REG_PORTE_FER                    (*(CPU_REG16 *)(BSP_SYS_PORTE_BASE    + 0x00u))
#define  BSP_SYS_REG_PORTE_DATA                   (*(CPU_REG16 *)(BSP_SYS_PORTE_BASE    + 0x0Cu))
#define  BSP_SYS_REG_PORTE_DIR                    (*(CPU_REG16 *)(BSP_SYS_PORTE_BASE    + 0x18u))
#define  BSP_SYS_REG_PORTE_DIRSET                 (*(CPU_REG16 *)(BSP_SYS_PORTE_BASE    + 0x1Cu))

#define  BSP_SYS_REG_DPM_CTL                      (*(CPU_REG32 *)(BSP_SYS_DPM_BASE_ADDR + 0x0u))
#define  BSP_SYS_REG_DPM_STAT                     (*(CPU_REG32 *)(BSP_SYS_DPM_BASE_ADDR + 0x4u))


/*
*********************************************************************************************************
*                                            REGISTER BITS
*********************************************************************************************************
*/

#define  BSP_SYS_DPM_STAT_CURMODE                      DEF_BIT_FIELD(4u, 0u)
#define  BSP_SYS_DPM_STAT_CURMODE_FULL_ON              DEF_BIT_MASK(0x1u, 0u)
#define  BSP_SYS_DPM_STAT_CURMODE_ACTIVE               DEF_BIT_MASK(0x2u, 0u)
#define  BSP_SYS_DPM_STAT_CURMODE_ACTIVE_PLL_DIS       DEF_BIT_MASK(0x3u, 0u)

#define  BSP_SYS_CGU_CTL_DF                            DEF_BIT_00
#define  BSP_SYS_CGU_CTL_MSEL                          DEF_BIT_FIELD(7u, 8u)
#define  BSP_SYS_CGU_CTL_WFI                           DEF_BIT_30
#define  BSP_SYS_CGU_CTL_LOCK                          DEF_BIT_31

#define  BSP_SYS_CGU_STAT_PLLEN                        DEF_BIT_00
#define  BSP_SYS_CGU_STAT_PLLBP                        DEF_BIT_01
#define  BSP_SYS_CGU_STAT_PLOCK                        DEF_BIT_02
#define  BSP_SYS_CGU_STAT_CLKALGN                      DEF_BIT_03
#define  BSP_SYS_CGU_STAT_CCBF0                        DEF_BIT_04
#define  BSP_SYS_CGU_STAT_DCBF                         DEF_BIT_08
#define  BSP_SYS_CGU_STAT_OCBF                         DEF_BIT_09
#define  BSP_SYS_CGU_STAT_ADDRERR                      DEF_BIT_16
#define  BSP_SYS_CGU_STAT_LWERR                        DEF_BIT_17
#define  BSP_SYS_CGU_STAT_DIVERR                       DEF_BIT_18
#define  BSP_SYS_CGU_STAT_WDFMSERR                     DEF_BIT_19
#define  BSP_SYS_CGU_STAT_WDIVERR                      DEF_BIT_20

#define  BSP_SYS_CGU_DIV_CSEL                          DEF_BIT_FIELD(5u, 0u)
#define  BSP_SYS_CGU_DIV_S0SEL                         DEF_BIT_FIELD(3u, 5u)
#define  BSP_SYS_CGU_DIV_SYSSEL                        DEF_BIT_FIELD(5u, 8u)
#define  BSP_SYS_CGU_DIV_S1SEL                         DEF_BIT_FIELD(3u, 13u)
#define  BSP_SYS_CGU_DIV_DSEL                          DEF_BIT_FIELD(5u, 16u)
#define  BSP_SYS_CGU_DIV_OSEL                          DEF_BIT_FIELD(7u, 22u)
#define  BSP_SYS_CGU_DIV_ALGN                          DEF_BIT_29
#define  BSP_SYS_CGU_DIV_UPDT                          DEF_BIT_30
#define  BSP_SYS_CGU_DIV_LOCK                          DEF_BIT_31

#define  BSP_SYS_CGU_CLKOUTSEL_CLKOUTSEL               DEF_BIT_FIELD(5u, 0u)
#define  BSP_SYS_CGU_CLKOUTSEL_USBCLKSEL               DEF_BIT_FIELD(6u, 16u)
#define  BSP_SYS_CGU_CLKOUTSEL_LOCK                    DEF_BIT_31

#define  BSP_SYS_CGU_OSCWDCTL_HODF                     DEF_BIT_FIELD(6u, 0u)
#define  BSP_SYS_CGU_OSCWDCTL_HODEN                    DEF_BIT_06
#define  BSP_SYS_CGU_OSCWDCTL_CNGEN                    DEF_BIT_07
#define  BSP_SYS_CGU_OSCWDCTL_BOUF                     DEF_BIT_FIELD(5u, 8u)
#define  BSP_SYS_CGU_OSCWDCTL_BOUEN                    DEF_BIT_13
#define  BSP_SYS_CGU_OSCWDCTL_FAULTEN                  DEF_BIT_14
#define  BSP_SYS_CGU_OSCWDCTL_MONDIS                   DEF_BIT_15
#define  BSP_SYS_CGU_OSCWDCTL_FAULTINDIS               DEF_BIT_23
#define  BSP_SYS_CGU_OSCWDCTL_LOCK                     DEF_BIT_31

#define  BSP_SYS_CGU_TSCTL_EN                          DEF_BIT_00
#define  BSP_SYS_CGU_TSCTL_LOAD                        DEF_BIT_01
#define  BSP_SYS_CGU_TSCTL_TSDIV                       DEF_BIT_FIELD(4u, 4u)
#define  BSP_SYS_CGU_TSCTL_LOCK                        DEF_BIT_31

#define  BSP_SYS_CGU_TSVALUE0_VALUE                    DEF_BIT_FIELD(32u, 0u)
#define  BSP_SYS_CGU_TSVALUE1_VALUE                    DEF_BIT_FIELD(32u, 0u)

#define  BSP_SYS_CGU_TSCOUNT0_VALUE                    DEF_BIT_FIELD(32u, 0u)
#define  BSP_SYS_CGU_TSCOUNT1_VALUE                    DEF_BIT_FIELD(32u, 0u)

#define  BSP_SYS_BIT_PORTB_FER_PORT_10                 DEF_BIT_10
#define  BSP_SYS_BIT_PORTB_FER_PORT_11                 DEF_BIT_11
#define  BSP_SYS_BIT_PORTB_FER_PORT_12                 DEF_BIT_12
#define  BSP_SYS_BIT_PORTB_FER_PORT_13                 DEF_BIT_13
#define  BSP_SYS_BIT_PORTB_FER_PORT_14                 DEF_BIT_14

#define  BSP_SYS_BIT_PORTC_FER_PORT_7                  DEF_BIT_07


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void         BSP_SysInit      (void);
CPU_INT32U   BSP_SysClkFreqGet(void);
CPU_BOOLEAN  BSP_SysClkLock   (void);
