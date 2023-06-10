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
*
* Filename      : bsp_sys.c
* Version       : V1.01
* Programmer(s) : YS
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                             INCLUDES
*********************************************************************************************************
*/

#include  <lib_def.h>
#include  <msp432.h>
#include  <msp432p401r.h>
#include  <bsp_sys.h>
#include  <cpu.h>

/*
*********************************************************************************************************
*                                           LOCAL DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                         BSP SYSTEM INITIALIZATION
*
* Description: This function should be called early in the BSP initialization process.
*
* Argument(s): none.
*
* Return(s)  : none.
*
* Caller(s)  : BSP_Init().
*
* Note(s)    : none.
*********************************************************************************************************
*/

void  BSP_SysInit (void)
{   
    SYSCTL->SRAM_BANKEN = SYSCTL_SRAM_BANKEN_BNK7_EN;            /* Enable all SRAM banks                               */
                                                                 /* - Configure FLASH Wait States for BANK0 and BANK1 - */
    while(DEF_BIT_IS_SET(PCM->CTL1, PCM_CTL1_PMR_BUSY));         /* Make sure we can read the clock system registers.   */

    PCM->CTL0 = PCM_CTL0_KEY_VAL | PCM_CTL0_AMR_1;               /* Change the core voltage setting to LDO VCORE1.      */
                                                                 /* This step is a requirement for 48MHz clk operation. */
    while(DEF_BIT_IS_SET(PCM->CTL1, PCM_CTL1_PMR_BUSY));
                                                                 /* Cfg banks to 1 FLASH wait state for read operations.*/
    DEF_BIT_CLR(FLCTL->BANK0_RDCTL, FLCTL_BANK0_RDCTL_WAIT_MASK);
    DEF_BIT_SET(FLCTL->BANK0_RDCTL, FLCTL_BANK0_RDCTL_WAIT_1);

    DEF_BIT_CLR(FLCTL->BANK1_RDCTL, FLCTL_BANK1_RDCTL_WAIT_MASK);
    DEF_BIT_SET(FLCTL->BANK1_RDCTL, FLCTL_BANK1_RDCTL_WAIT_1);
    
                                                                /* - Configure DCO to 48MHz. Make MCLK use the DCO.   - */
    
    CS->KEY  = CS_KEY_VAL;                                      /* Unlock CS module for register access.                */
    CS->CTL0 = 0u;                                              /* Reset tuning parameters.                             */

                                                                /* Enable buffering of BANK0 & BANK1 data reads and ... */
                                                                /* ... instruction fetches.                             */
    DEF_BIT_SET(FLCTL->BANK0_RDCTL, (FLCTL_BANK0_RDCTL_BUFD | FLCTL_BANK0_RDCTL_BUFI));
    DEF_BIT_SET(FLCTL->BANK1_RDCTL, (FLCTL_BANK1_RDCTL_BUFD | FLCTL_BANK1_RDCTL_BUFI));


    CS->CTL0 = CS_CTL0_DCORSEL_5;                               /* Set DCO to 48MHz operation.                          */
    DEF_BIT_SET(CS->CTL0, CS_CTL0_DCOEN);                       /* Enable DCO (digitally controlled oscillator).        */

                                                                /* Select DCO as the MCLK with no divider.              */
    DEF_BIT_CLR(CS->CTL1, (CS_CTL1_SELM_MASK | CS_CTL1_DIVM_MASK));
    DEF_BIT_SET(CS->CTL1, CS_CTL1_SELM__DCOCLK);
    CS->KEY = 0u;                                               /* Lock CS module to protect it from inadvertent access.*/

                                                                /* Enable SysTick Module                                */
    DEF_BIT_SET(BSP_SYS_REG_SCS_STCSR,
                SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk);

                                                                /* Set SysTick period to 1/48000                        */
    if (((CS->CTL0 & CS_CTL0_DCORSEL_MASK) >> 16u) == 5u) {
        CPU_REG_NVIC_ST_RELOAD = 48000u - 1u;
    }


    CPU_IntEn();                                                /* Enable Interrupts.                                   */
}
