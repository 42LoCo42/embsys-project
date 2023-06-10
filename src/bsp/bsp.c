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
* Filename      : bsp.c
* Version       : V1.01
* Programmer(s) : YS
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include  <os.h>
#include  <bsp.h>
#include  <bsp_int.h>
#include  <bsp_sys.h>
#include  <msp432p401r.h>



/*
*********************************************************************************************************
*                                             GPIO DEFINES
*********************************************************************************************************
*/

#define  BSP_GPIO_P1_PIN(x)                DEF_BIT_SET(BSP_GPIO_P1_BASE_ADDR,  x)
#define  BSP_GPIO_P2_PIN(x)                DEF_BIT_SET(BSP_GPIO_P2_BASE_ADDR,  x)
#define  BSP_GPIO_P3_PIN(x)                DEF_BIT_SET(BSP_GPIO_P3_BASE_ADDR,  x)
#define  BSP_GPIO_P4_PIN(x)                DEF_BIT_SET(BSP_GPIO_P4_BASE_ADDR,  x)
#define  BSP_GPIO_P5_PIN(x)                DEF_BIT_SET(BSP_GPIO_P5_BASE_ADDR,  x)
#define  BSP_GPIO_P6_PIN(x)                DEF_BIT_SET(BSP_GPIO_P6_BASE_ADDR,  x)
#define  BSP_GPIO_P7_PIN(x)                DEF_BIT_SET(BSP_GPIO_P7_BASE_ADDR,  x)
#define  BSP_GPIO_P8_PIN(x)                DEF_BIT_SET(BSP_GPIO_P8_BASE_ADDR,  x)
#define  BSP_GPIO_P9_PIN(x)                DEF_BIT_SET(BSP_GPIO_P9_BASE_ADDR,  x)
#define  BSP_GPIO_P10_PIN(x)               DEF_BIT_SET(BSP_GPIO_P10_BASE_ADDR, x)

/*
*********************************************************************************************************
*                                       LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                          LOCAL DATA TYPES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                      LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  void  BSP_LED_Init (void);
static  void  BSP_PB_Init  (void);


/*
*********************************************************************************************************
*                                     LOCAL CONFIGURATION ERRORS
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*********************************************************************************************************
**                                         GLOBAL FUNCTIONS
*********************************************************************************************************
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                             BSP_LowLevelInit()
*
* Description : System Low Level Init (PLLs, External Memories, Boot loaders, etc).
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : Startup Code.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_LowLevelInit (void)
{

}


/*
*********************************************************************************************************
*                                          BSP INITIALIZATION
*
* Description : Board Support package initialization.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : main()
*
* Note(s)     : (1) This function initializes all peripherals that don't require OS services or modules
*                   that need to be initialized before the OS is initialized (e.g External memories).
*
*********************************************************************************************************
*/

void  BSP_Init (void)
{
    BSP_SysInit();                                              /* -------------- CLOCK INITIALIZATION --------------- */
    BSP_IntInit();                                              /* ------------- INTERRUPT INITIALIZATION ------------ */
    BSP_LED_Init();                                             /* ---------------- LED INITIALIZATION --------------- */
    BSP_PB_Init();                                              /* ------------ PUSH BUTTON INITIALIZATION ----------- */
}


/*
*********************************************************************************************************
*                                            BSP_CPU_ClkFreq()
*
* Description : Read CPU registers to determine the CPU clock frequency of the chip.
*
* Argument(s) : none.
*
* Return(s)   : The CPU clock frequency, in Hz.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

CPU_INT32U  BSP_CPU_ClkFreq (void)
{
    CPU_INT32U  freq;

#if (OS_VERSION >= 30000u)
     freq = (CPU_INT32U)(SysTick->LOAD + 1) * (CPU_INT32U)OSCfg_TickRate_Hz;
#else
     freq = (CPU_INT32U)(SysTick->LOAD + 1) * (CPU_INT32U)OS_TICKS_PER_SEC;
#endif

    return (freq);
}


/*
*********************************************************************************************************
*                                            BSP_LED_Init()
*
* Description : Initialize the user LEDs on the board.
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

static  void  BSP_LED_Init (void)
{                                                               /* Set Direction of LED pins as outputs.                */
    BSP_GPIO_PinDirSet(BSP_GPIO_P1_BASE_ADDR, BSP_GPIO_LED1_PIN,         DEF_TRUE);
    BSP_GPIO_PinDirSet(BSP_GPIO_P2_BASE_ADDR, BSP_GPIO_RGBLED_RED_PIN,   DEF_TRUE);
    BSP_GPIO_PinDirSet(BSP_GPIO_P2_BASE_ADDR, BSP_GPIO_RGBLED_GREEN_PIN, DEF_TRUE);
    BSP_GPIO_PinDirSet(BSP_GPIO_P2_BASE_ADDR, BSP_GPIO_RGBLED_BLUE_PIN,  DEF_TRUE);
}


/*
*********************************************************************************************************
*                                            BSP_CPU_ClkFreq()
*
* Description : Initialize the push buttons on the board.
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

static  void  BSP_PB_Init  (void)
{
                                                                /* Clr Function Select Reg's for default GPIO function. */
    DEF_BIT_CLR(BSP_GPIO_REG_SEL0(BSP_GPIO_P1_BASE_ADDR),
                BSP_GPIO_SW2_PIN | BSP_GPIO_SW1_PIN);

    DEF_BIT_CLR(BSP_GPIO_REG_SEL1(BSP_GPIO_P1_BASE_ADDR),
                BSP_GPIO_SW2_PIN | BSP_GPIO_SW1_PIN);
                                                                /* Set the Direction of the Push Buttons as Input.      */
    DEF_BIT_CLR(BSP_GPIO_REG_DIR(BSP_GPIO_P1_BASE_ADDR),
                BSP_GPIO_SW2_PIN | BSP_GPIO_SW1_PIN);
                                                                /* Set Interrupt Edge Select Register. Falling Edge.    */
    DEF_BIT_SET(BSP_GPIO_REG_IES(BSP_GPIO_P1_BASE_ADDR),
                BSP_GPIO_SW2_PIN | BSP_GPIO_SW1_PIN);

    DEF_BIT_SET(BSP_GPIO_REG_REN(BSP_GPIO_P1_BASE_ADDR),        /* Resistor Enable.                                     */
                BSP_GPIO_SW2_PIN | BSP_GPIO_SW1_PIN);

    DEF_BIT_SET(BSP_GPIO_REG_OUT(BSP_GPIO_P1_BASE_ADDR),        /* Enable Pullup Resistor.                              */
                BSP_GPIO_SW2_PIN | BSP_GPIO_SW1_PIN);

    BSP_GPIO_REG_IFG(BSP_GPIO_P1_BASE_ADDR) = (CPU_REG08)0u;    /* Clear Interrupt Flag.                                */

    DEF_BIT_SET(BSP_GPIO_REG_IE(BSP_GPIO_P1_BASE_ADDR),         /* Enable GPIO Interrupt for S1 (P1.1).                 */
                BSP_GPIO_SW1_PIN);

    DEF_BIT_SET(BSP_GPIO_REG_IE(BSP_GPIO_P1_BASE_ADDR),         /* Enable GPIO Interrupt for S2 (P1.4).                 */
                BSP_GPIO_SW2_PIN);

    BSP_IntVectSet(BSP_INT_ID_PORT1,                            /* Set the ISR for the PORT 1 interrupt.                */
   		           App_Port1_ISR);

    BSP_IntEn(BSP_INT_ID_PORT1);                                /* Enable PORT 1 interrupt.                             */
}



/*
*********************************************************************************************************
*                                            BSP_GPIO_PinDirSet()
*
* Description : Set the direction of any GPIO pin on the specified port
*
* Argument(s) : port    GPIO port to address
*               pin     Pin within that port
*               dir     Direction to set that pin to. DEF_FALSE for input and DEF_TRUE for output
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_GPIO_PinDirSet (CPU_INT32U port, CPU_INT08U pin, CPU_BOOLEAN dir)
{
    if (dir == DEF_TRUE) {
        DEF_BIT_SET(BSP_GPIO_REG_DIR(port), pin);
    } else {
        DEF_BIT_CLR(BSP_GPIO_REG_DIR(port), pin);
    }
}


/*
*********************************************************************************************************
*                                                 BSP_LED_Off()
*
* Description : Turn OFF any or all the LEDs on the board.
*
* Argument(s) : led     The ID of the LED to control:
*                           0    turn OFF all LEDs on the board.
*                           1    turn OFF LED1 on the board.
*                           2    turn OFF Red   Component of LED2 on the board.
*                           3    turn OFF Green Component of LED2 on the board.
*                           4    turn OFF Blue  Component of LED2 on the board.
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_LED_Off (CPU_INT08U  led)
{
    switch (led) {
        case BSP_GPIO_LED_ALL:
             DEF_BIT_CLR(BSP_GPIO_REG_OUT(BSP_GPIO_P1_BASE_ADDR),
                         BSP_GPIO_LED1_PIN);

             DEF_BIT_CLR(BSP_GPIO_REG_OUT(BSP_GPIO_P2_BASE_ADDR),
                        (BSP_GPIO_RGBLED_RED_PIN   |
                         BSP_GPIO_RGBLED_GREEN_PIN |
                         BSP_GPIO_RGBLED_BLUE_PIN));
             break;


        case BSP_GPIO_LED1:
             DEF_BIT_CLR(BSP_GPIO_REG_OUT(BSP_GPIO_P1_BASE_ADDR),
                         BSP_GPIO_LED1_PIN);
             break;


        case BSP_GPIO_LED2_RED:
             DEF_BIT_CLR(BSP_GPIO_REG_OUT(BSP_GPIO_P2_BASE_ADDR),
                         BSP_GPIO_RGBLED_RED_PIN);
             break;


        case BSP_GPIO_LED2_GREEN:
             DEF_BIT_CLR(BSP_GPIO_REG_OUT(BSP_GPIO_P2_BASE_ADDR),
                         BSP_GPIO_RGBLED_GREEN_PIN);
             break;


        case BSP_GPIO_LED2_BLUE:
             DEF_BIT_CLR(BSP_GPIO_REG_OUT(BSP_GPIO_P2_BASE_ADDR),
                         BSP_GPIO_RGBLED_BLUE_PIN);
             break;


        default:
             break;
    }
}


/*
*********************************************************************************************************
*                                                 BSP_LED_On()
*
* Description : Turn ON any or all the LEDs on the board.
*
* Argument(s) : led     The ID of the LED to control:
*                           0    turn ON all LEDs on the board.
*                           1    turn ON LED1 on the board.
*                           2    turn ON Red   Component of LED2 on the board.
*                           3    turn ON Green Component of LED2 on the board.
*                           4    turn ON Blue  Component of LED2 on the board.
*
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_LED_On (CPU_INT08U  led)
{
    switch (led) {
        case BSP_GPIO_LED_ALL:
             DEF_BIT_SET(BSP_GPIO_REG_OUT(BSP_GPIO_P1_BASE_ADDR),
                          BSP_GPIO_LED1_PIN);

             DEF_BIT_SET(BSP_GPIO_REG_OUT(BSP_GPIO_P2_BASE_ADDR),
                        (BSP_GPIO_RGBLED_RED_PIN   |
                         BSP_GPIO_RGBLED_GREEN_PIN |
                         BSP_GPIO_RGBLED_BLUE_PIN));
             break;


        case BSP_GPIO_LED1:
             DEF_BIT_SET(BSP_GPIO_REG_OUT(BSP_GPIO_P1_BASE_ADDR),
                         BSP_GPIO_LED1_PIN);
             break;


        case BSP_GPIO_LED2_RED:
             DEF_BIT_SET(BSP_GPIO_REG_OUT(BSP_GPIO_P2_BASE_ADDR),
                         BSP_GPIO_RGBLED_RED_PIN);
             break;


        case BSP_GPIO_LED2_GREEN:
             DEF_BIT_SET(BSP_GPIO_REG_OUT(BSP_GPIO_P2_BASE_ADDR),
                         BSP_GPIO_RGBLED_GREEN_PIN);
             break;


        case BSP_GPIO_LED2_BLUE:
             DEF_BIT_SET(BSP_GPIO_REG_OUT(BSP_GPIO_P2_BASE_ADDR),
                         BSP_GPIO_RGBLED_BLUE_PIN);
             break;


        default:
             break;
    }
}


/*
*********************************************************************************************************
*                                                 BSP_LED_Toggle()
*
* Description : Toggles any or all the LEDs on the board.
*
* Argument(s) : led     The ID of the LED to control:
*                           0    Toggle all LEDs on the board.
*                           1    Toggle LED1 on the board.
*                           2    Toggle Red   Component of LED2 on the board.
*                           3    Toggle Green Component of LED2 on the board.
*                           4    Toggle Blue  Component of LED2 on the board.
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_LED_Toggle (CPU_INT08U  led)
{
    switch (led) {
        case BSP_GPIO_LED_ALL:
             DEF_BIT_TOGGLE(BSP_GPIO_REG_OUT(BSP_GPIO_P1_BASE_ADDR),
                            BSP_GPIO_LED1_PIN);

             DEF_BIT_TOGGLE(BSP_GPIO_REG_OUT(BSP_GPIO_P2_BASE_ADDR),
                           (BSP_GPIO_RGBLED_RED_PIN   |
                            BSP_GPIO_RGBLED_GREEN_PIN |
                            BSP_GPIO_RGBLED_BLUE_PIN));
             break;


        case BSP_GPIO_LED1:
             DEF_BIT_TOGGLE(BSP_GPIO_REG_OUT(BSP_GPIO_P1_BASE_ADDR),
                            BSP_GPIO_LED1_PIN);
             break;


        case BSP_GPIO_LED2_RED:
             DEF_BIT_TOGGLE(BSP_GPIO_REG_OUT(BSP_GPIO_P2_BASE_ADDR),
                            BSP_GPIO_RGBLED_RED_PIN);
             break;


        case BSP_GPIO_LED2_GREEN:
             DEF_BIT_TOGGLE(BSP_GPIO_REG_OUT(BSP_GPIO_P2_BASE_ADDR),
                            BSP_GPIO_RGBLED_GREEN_PIN);
             break;


        case BSP_GPIO_LED2_BLUE:
             DEF_BIT_TOGGLE(BSP_GPIO_REG_OUT(BSP_GPIO_P2_BASE_ADDR),
                            BSP_GPIO_RGBLED_BLUE_PIN);
             break;


        default:
             break;
    }
}

/*
*********************************************************************************************************
*                                           BSP_PB_StatusGet()
*
* Description : Get the state of the on-board push buttons.
*
* Argument(s) : pb      The logical value of the push buttons labeled S1 and S2 on the board.
*
* Return(s)   : DEF_ON  if the button is pressed.
*               DEF_OFF if the button is released.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

CPU_BOOLEAN  BSP_PB_StatusGet (CPU_INT08U  pb)
{
	CPU_BOOLEAN  state;


	state = DEF_OFF;
    switch (pb) {
       case BSP_GPIO_SW1:
       	    state = DEF_BIT_IS_SET(BSP_GPIO_REG_IN(BSP_GPIO_P1_BASE_ADDR),
       	    		               BSP_GPIO_SW1_PIN);
    	    break;


       case BSP_GPIO_SW2:
    	    state = DEF_BIT_IS_SET(BSP_GPIO_REG_IN(BSP_GPIO_P1_BASE_ADDR),
    	    		               BSP_GPIO_SW2_PIN);
    	    break;


       default:
    	     break;
    }
    return state;
}


/*
*********************************************************************************************************
*                                            BSP_Tick_Init()
*
* Description : Initialize all the peripherals that required OS Tick services (OS initialized)
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

void BSP_Tick_Init (void)
{
    CPU_INT32U  cpu_clk_freq;
    CPU_INT32U  cnts;

    cpu_clk_freq = BSP_CPU_ClkFreq();                           /* Determine SysTick reference freq.                    */

#if (OS_VERSION >= 30000u)
    cnts  = cpu_clk_freq / (CPU_INT32U)OSCfg_TickRate_Hz;       /* Determine nbr SysTick increments.                    */
#else
    cnts  = cpu_clk_freq / (CPU_INT32U)OS_TICKS_PER_SEC;        /* Determine nbr SysTick increments.                    */
#endif

    OS_CPU_SysTickInit(cnts);                                   /* Init uC/OS periodic time src (SysTick).              */
}


