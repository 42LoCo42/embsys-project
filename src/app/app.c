#include <app_cfg.h>
#include <bsp.h>
#include <bsp_int.h>
#include <lib_math.h>
#include <os.h>

static OS_TCB AppTaskStartTCB;
static CPU_STK AppTaskStartStk[APP_CFG_TASK_START_STK_SIZE];

static void AppTaskStart(void* p_arg);

void main(void) {
	OS_ERR err;

	Mem_Init();   // initialize memory management module
	CPU_IntDis(); // disable all interrupts
	OSInit(&err); // init the OS

	// clang-format off
	OSTaskCreate(
		(OS_TCB*     ) &AppTaskStartTCB,                 // control block
		(CPU_CHAR*   ) "App Task Start",                 // name
		(OS_TASK_PTR ) AppTaskStart,                     // main function
		(void*       ) 0,                                // parameter
		(OS_PRIO     ) APP_CFG_TASK_START_PRIO,          // priority
		(CPU_STK*    ) &AppTaskStartStk[0],              // stack base address
		(CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE / 10, // stack min empty size
		(CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE,      // stack total size
		(OS_MSG_QTY  ) 0,
		(OS_TICK     ) 0,
		(void*       ) 0,

		// check stack at runtime, clear stack on task creation
		(OS_OPT) (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),

		(OS_ERR*) &err
	);
	// clang-format on

	OSStart(&err); // give control to OS
}

static void AppTaskStart(void* p_arg) {
	OS_ERR err;

	BSP_Init();      // initialize the board support package
	BSP_Tick_Init(); // initialize BSP ticks

	// Board_Init();
	Math_Init();

	BSP_LED_Off(BSP_GPIO_LED_ALL);

	for(;;) {
		BSP_LED_Toggle(BSP_GPIO_LED1);
		OSTimeDlyHMSM(
			(CPU_INT16U) 0, // hours
			(CPU_INT16U) 0, // minutes
			(CPU_INT16U) 1, // seconds
			(CPU_INT32U) 0, // milliseconds
			(OS_OPT) OS_OPT_TIME_HMSM_STRICT, (OS_ERR*) &err
		);
	}
}

void App_Port1_ISR(void) {
	// clear interrupt flag
	BSP_GPIO_REG_IV(BSP_GPIO_P1_BASE_ADDR);
}
