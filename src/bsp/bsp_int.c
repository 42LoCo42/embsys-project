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
*                                          TI MSP-EXP432P401R
*                                       LaunchPad Development Kit
*
* Filename      : bsp_int.c
* Version       : V1.01
* Programmer(s) : YS
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#define  BSP_INT_MODULE

#include  <cpu.h>
#include  <os.h>
#include  <bsp.h>
#include  <bsp_int.h>
#include  <lib_def.h>


/*
*********************************************************************************************************
*                                            LOCAL DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           LOCAL CONSTANTS
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                          LOCAL DATA TYPES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                            LOCAL TABLES
*********************************************************************************************************
*/

static CPU_FNCT_VOID BSP_IntVectTbl[BSP_INT_ID_MAX];


/*
*********************************************************************************************************
*                                       LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                      LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  void  BSP_IntHandlerDummy (void);


/*
*********************************************************************************************************
*                                     LOCAL CONFIGURATION ERRORS
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                          BSP_IntClr()
*
* Description : This function clears an interrupt
*
* Argument(s) : int_id        Interrupt to clear.
*
* Returns     : none.
*
* Caller(s)   : Application.
*
* Note(s)     : (1) An interrupt does not need to be cleared within the interrupt controller.
*********************************************************************************************************
*/

void  BSP_IntClr (CPU_INT08U  int_id)
{

}


/*
*********************************************************************************************************
*                                             BSP_IntDis()
*
* Description : This function disables an interrupt.
*
* Argument(s) : int_id        Interrupt to clear.
*
* Returns     : none.
*
* Caller(s)   : Application.
*
* Note(s)     : Disable the specified interrupt by writing a 1 to the Interrupt
*               Mask Flag Register.
*********************************************************************************************************
*/

void  BSP_IntDis (CPU_INT08U  int_id)
{
                                                                /* -------------- ARGUMENTS CHECKING ---------------- */
    if (int_id < BSP_INT_ID_MAX) {
        CPU_IntSrcDis(int_id + 16);
    }
}


/*
*********************************************************************************************************
*                                           BSP_IntDisAll()
*
* Description : Disable ALL interrupts.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_IntDisAll (void)
{
    CPU_IntDis();
}


/*
*********************************************************************************************************
*                                          BSP_IntEn()
*
* Description : This function enables an interrupt.
*
* Argument(s) : int_id        Interrupt to clear.
*
* Returns     : none.
*
* Caller(s)   : Application.
*
* Note(s)     : Enable interrupt by setting a 1 to the Interrupt Mask
*               Flag Register.
*********************************************************************************************************
*/

void  BSP_IntEn (CPU_INT08U  int_id)
{
    if (int_id < BSP_INT_ID_MAX) {
        CPU_IntSrcEn(int_id + 16);
    }
}


/*
*********************************************************************************************************
*                                            BSP_IntVectSet()
*
* Description : Assign ISR handler.
*
* Argument(s) : int_id      Interrupt for which vector will be set.
*
*               isr         Handler to assign
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_IntVectSet (CPU_INT08U     int_id,
                      CPU_FNCT_VOID  isr)
{
    CPU_SR_ALLOC();


    if (int_id < BSP_INT_ID_MAX) {
        CPU_CRITICAL_ENTER();
        BSP_IntVectTbl[int_id]   = isr;                         /* Setup interrupt specified in the vector table        */
        CPU_CRITICAL_EXIT();
    }
}


/*
*********************************************************************************************************
*********************************************************************************************************
*                                           INTERNAL FUNCTIONS
*********************************************************************************************************
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                              BSP_IntInit()
*
* Description : Initialize interrupts:
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : BSP_Init().
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_IntInit (void)
{
    CPU_INT32U  int_id;


    for (int_id = 0; int_id < BSP_INT_ID_MAX; int_id++) {       /* Initialize each interrupt with Dummy Handler         */
        BSP_IntVectSet((CPU_INT08U)int_id,
                       (CPU_FNCT_VOID)BSP_IntHandlerDummy);
    }
}


/*
*********************************************************************************************************
*                                        BSP_IntHandler####()
*
* Description : Handle an interrupt.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : This is an ISR.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_IntHandlerPSS                   (void)  { BSP_IntHandler(BSP_INT_ID_PSS);                 }
void  BSP_IntHandlerCS                    (void)  { BSP_IntHandler(BSP_INT_ID_CS);                  }
void  BSP_IntHandlerPCM                   (void)  { BSP_IntHandler(BSP_INT_ID_PCM);                 }
void  BSP_IntHandlerWTD                   (void)  { BSP_IntHandler(BSP_INT_ID_WTD);                 }
void  BSP_IntHandlerFPU                   (void)  { BSP_IntHandler(BSP_INT_ID_FPU);                 }
void  BSP_IntHandlerFLCTL                 (void)  { BSP_IntHandler(BSP_INT_ID_FTCTL);               }
void  BSP_IntHandlerCOMP0                 (void)  { BSP_IntHandler(BSP_INT_ID_COMP0);               }
void  BSP_IntHandlerCOMP1                 (void)  { BSP_IntHandler(BSP_INT_ID_COMP1);               }
void  BSP_IntHandlerTA0_0                 (void)  { BSP_IntHandler(BSP_INT_ID_TA0_0);               }
void  BSP_IntHandlerTA0_N                 (void)  { BSP_IntHandler(BSP_INT_ID_TA0_0);               }
void  BSP_IntHandlerTA1_0                 (void)  { BSP_IntHandler(BSP_INT_ID_TA1_0);               }
void  BSP_IntHandlerTA1_N                 (void)  { BSP_IntHandler(BSP_INT_ID_TA1_N);               }
void  BSP_IntHandlerTA2_0                 (void)  { BSP_IntHandler(BSP_INT_ID_TA2_0);               }
void  BSP_IntHandlerTA2_N                 (void)  { BSP_IntHandler(BSP_INT_ID_TA2_N);               }
void  BSP_IntHandlerTA3_0                 (void)  { BSP_IntHandler(BSP_INT_ID_TA3_0);               }
void  BSP_IntHandlerTA3_N                 (void)  { BSP_IntHandler(BSP_INT_ID_TA3_N);               }
void  BSP_IntHandlerEUSCIA0               (void)  { BSP_IntHandler(BSP_INT_ID_EUSCIA0);             }
void  BSP_IntHandlerEUSCIA1               (void)  { BSP_IntHandler(BSP_INT_ID_EUSCIA1);             }
void  BSP_IntHandlerEUSCIA2               (void)  { BSP_IntHandler(BSP_INT_ID_EUSCIA2);             }
void  BSP_IntHandlerEUSCIA3               (void)  { BSP_IntHandler(BSP_INT_ID_EUSCIA3);             }
void  BSP_IntHandlerEUSCIB0               (void)  { BSP_IntHandler(BSP_INT_ID_EUSCIB0);             }
void  BSP_IntHandlerEUSCIB1               (void)  { BSP_IntHandler(BSP_INT_ID_EUSCIB1);             }
void  BSP_IntHandlerEUSCIB2               (void)  { BSP_IntHandler(BSP_INT_ID_EUSCIB2);             }
void  BSP_IntHandlerEUSCIB3               (void)  { BSP_IntHandler(BSP_INT_ID_EUSCIB3);             }
void  BSP_IntHandlerADC14                 (void)  { BSP_IntHandler(BSP_INT_ID_ADC);                 }
void  BSP_IntHandlerT32_INT1              (void)  { BSP_IntHandler(BSP_INT_ID_INT1);                }
void  BSP_IntHandlerT32_INT2              (void)  { BSP_IntHandler(BSP_INT_ID_INT2);                }
void  BSP_IntHandlerT32_INTC              (void)  { BSP_IntHandler(BSP_INT_ID_INTC);                }
void  BSP_IntHandlerAES                   (void)  { BSP_IntHandler(BSP_INT_ID_AES);                 }
void  BSP_IntHandlerRTC                   (void)  { BSP_IntHandler(BSP_INT_ID_RTC);                 }
void  BSP_IntHandlerDMA_ERR               (void)  { BSP_IntHandler(BSP_INT_ID_DMA_ERR);             }
void  BSP_IntHandlerDMA_INT3              (void)  { BSP_IntHandler(BSP_INT_ID_DMA_INT3);            }
void  BSP_IntHandlerDMA_INT2              (void)  { BSP_IntHandler(BSP_INT_ID_DMA_INT2);            }
void  BSP_IntHandlerDMA_INT1              (void)  { BSP_IntHandler(BSP_INT_ID_DMA_INT1);            }
void  BSP_IntHandlerDMA_INT0              (void)  { BSP_IntHandler(BSP_INT_ID_DMA_INT0);            }
void  BSP_IntHandlerPORT1                 (void)  { BSP_IntHandler(BSP_INT_ID_PORT1);               }
void  BSP_IntHandlerPORT2                 (void)  { BSP_IntHandler(BSP_INT_ID_PORT2);               }
void  BSP_IntHandlerPORT3                 (void)  { BSP_IntHandler(BSP_INT_ID_PORT3);               }
void  BSP_IntHandlerPORT4                 (void)  { BSP_IntHandler(BSP_INT_ID_PORT4);               }
void  BSP_IntHandlerPORT5                 (void)  { BSP_IntHandler(BSP_INT_ID_PORT5);               }
void  BSP_IntHandlerPORT6                 (void)  { BSP_IntHandler(BSP_INT_ID_PORT6);               }


/*
*********************************************************************************************************
*********************************************************************************************************
*                                           LOCAL FUNCTIONS
*********************************************************************************************************
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                        BSP_IntHandlerDummy()
*
* Description : Dummy interrupt handler.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : BSP_IntHandler().
*
* Note(s)     : none.
*********************************************************************************************************
*/

static void  BSP_IntHandlerDummy (void)
{
    while (DEF_TRUE) {
        ;
    }
}


/*
*********************************************************************************************************
*                                        BSP_IntHandler()
*
* Description : General Maskable Interrupt handler.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : CPU_IntHandler().
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_IntHandler (CPU_INT16U  src_nbr)
{
    CPU_FNCT_VOID  isr;
    CPU_SR_ALLOC();

    CPU_CRITICAL_ENTER();                                       /* Tell the OS that we are starting an ISR            */
    OSIntEnter();
    CPU_CRITICAL_EXIT();

    if (src_nbr < BSP_INT_ID_MAX) {
        isr = BSP_IntVectTbl[src_nbr];
        if (isr != (CPU_FNCT_VOID)0) {
            isr();
        }
    }

    OSIntExit();                                                /* Tell the OS that we are leaving the ISR            */
}

