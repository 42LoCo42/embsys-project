/*
************************************************************************************************************************
*                                                      uC/OS-III
*                                                 The Real-Time Kernel
*
*                                  (c) Copyright 2009-2016; Micrium, Inc.; Weston, FL
*                           All rights reserved.  Protected by international copyright laws.
*
*                                                  DEBUGGER CONSTANTS
*
* File    : OS_DBG.C
* By      : JJL
* Version : V3.06.01
*
* LICENSING TERMS:
* ---------------
*           uC/OS-III is provided in source form for FREE short-term evaluation, for educational use or
*           for peaceful research.  If you plan or intend to use uC/OS-III in a commercial application/
*           product then, you need to contact Micrium to properly license uC/OS-III for its use in your
*           application/product.   We provide ALL the source code for your convenience and to help you
*           experience uC/OS-III.  The fact that the source is provided does NOT mean that you can use
*           it commercially without paying a licensing fee.
*
*           Knowledge of the source code may NOT be used to develop a similar product.
*
*           Please help us continue to provide the embedded community with the finest software available.
*           Your honesty is greatly appreciated.
*
*           You can find our product's user manual, API reference, release notes and
*           more information at doc.micrium.com.
*           You can contact us at www.micrium.com.
************************************************************************************************************************
*/

#define  MICRIUM_SOURCE
#include "os.h"

#ifdef VSC_INCLUDE_SOURCE_FILE_NAMES
const  CPU_CHAR  *os_dbg__c = "$Id: $";
#endif

CPU_INT08U  const  OSDbg_DbgEn                 = OS_CFG_DBG_EN;                /* Debug constants are defined below   */

#if (OS_CFG_DBG_EN == DEF_ENABLED)

/*
************************************************************************************************************************
*                                                      DEBUG DATA
************************************************************************************************************************
*/

CPU_INT08U  const  OSDbg_ArgChkEn              = OS_CFG_ARG_CHK_EN;
CPU_INT08U  const  OSDbg_AppHooksEn            = OS_CFG_APP_HOOKS_EN;

CPU_INT32U  const  OSDbg_EndiannessTest        = 0x12345678LU;                 /* Variable to test CPU endianness     */

CPU_INT08U  const  OSDbg_CalledFromISRChkEn    = OS_CFG_CALLED_FROM_ISR_CHK_EN;

CPU_INT08U  const  OSDbg_FlagEn                = OS_CFG_FLAG_EN;
OS_FLAG_GRP const  OSDbg_FlagGrp               = { 0u };
#if (OS_CFG_FLAG_EN == DEF_ENABLED)
CPU_INT08U  const  OSDbg_FlagDelEn             = OS_CFG_FLAG_DEL_EN;
CPU_INT08U  const  OSDbg_FlagModeClrEn         = OS_CFG_FLAG_MODE_CLR_EN;
CPU_INT08U  const  OSDbg_FlagPendAbortEn       = OS_CFG_FLAG_PEND_ABORT_EN;
CPU_INT16U  const  OSDbg_FlagGrpSize           = sizeof(OS_FLAG_GRP);          /* Size in Bytes of OS_FLAG_GRP        */
CPU_INT16U  const  OSDbg_FlagWidth             = sizeof(OS_FLAGS);             /* Width (in bytes) of OS_FLAGS        */
#else
CPU_INT08U  const  OSDbg_FlagDelEn             = 0u;
CPU_INT08U  const  OSDbg_FlagModeClrEn         = 0u;
CPU_INT08U  const  OSDbg_FlagPendAbortEn       = 0u;
CPU_INT16U  const  OSDbg_FlagGrpSize           = 0u;
CPU_INT16U  const  OSDbg_FlagWidth             = 0u;
#endif

OS_MEM      const  OSDbg_Mem                   = { 0u };
CPU_INT08U  const  OSDbg_MemEn                 = OS_CFG_MEM_EN;
#if OS_CFG_MEM_EN > 0u
CPU_INT16U  const  OSDbg_MemSize               = sizeof(OS_MEM);               /* Mem. Partition header size (bytes)  */
#else
CPU_INT16U  const  OSDbg_MemSize               = 0u;
#endif


#if (OS_MSG_EN == DEF_ENABLED)
CPU_INT08U  const  OSDbg_MsgEn                 = 1u;
CPU_INT16U  const  OSDbg_MsgSize               = sizeof(OS_MSG);               /* OS_MSG size                         */
CPU_INT16U  const  OSDbg_MsgPoolSize           = sizeof(OS_MSG_POOL);
CPU_INT16U  const  OSDbg_MsgQSize              = sizeof(OS_MSG_Q);
#else
CPU_INT08U  const  OSDbg_MsgEn                 = 0u;
CPU_INT16U  const  OSDbg_MsgSize               = 0u;
CPU_INT16U  const  OSDbg_MsgPoolSize           = 0u;
CPU_INT16U  const  OSDbg_MsgQSize              = 0u;
#endif


OS_MUTEX    const  OSDbg_Mutex                 = { 0u };
CPU_INT08U  const  OSDbg_MutexEn               = OS_CFG_MUTEX_EN;
#if (OS_CFG_MUTEX_EN == DEF_ENABLED)
CPU_INT08U  const  OSDbg_MutexDelEn            = OS_CFG_MUTEX_DEL_EN;
CPU_INT08U  const  OSDbg_MutexPendAbortEn      = OS_CFG_MUTEX_PEND_ABORT_EN;
CPU_INT16U  const  OSDbg_MutexSize             = sizeof(OS_MUTEX);             /* Size in bytes of OS_MUTEX           */
#else
CPU_INT08U  const  OSDbg_MutexDelEn            = 0u;
CPU_INT08U  const  OSDbg_MutexPendAbortEn      = 0u;
CPU_INT16U  const  OSDbg_MutexSize             = 0u;
#endif

CPU_INT08U  const  OSDbg_ObjTypeChkEn          = OS_CFG_OBJ_TYPE_CHK_EN;


CPU_INT16U  const  OSDbg_PendListSize          = sizeof(OS_PEND_LIST);
CPU_INT16U  const  OSDbg_PendObjSize           = sizeof(OS_PEND_OBJ);


CPU_INT16U  const  OSDbg_PrioMax               = OS_CFG_PRIO_MAX;              /* Maximum number of priorities        */
CPU_INT16U  const  OSDbg_PrioTblSize           = sizeof(OSPrioTbl);

CPU_INT16U  const  OSDbg_PtrSize               = sizeof(void *);               /* Size in Bytes of a pointer          */


OS_Q        const  OSDbg_Q                     = { 0u };
CPU_INT08U  const  OSDbg_QEn                   = OS_CFG_Q_EN;
#if (OS_CFG_Q_EN == DEF_ENABLED)
CPU_INT08U  const  OSDbg_QDelEn                = OS_CFG_Q_DEL_EN;
CPU_INT08U  const  OSDbg_QFlushEn              = OS_CFG_Q_FLUSH_EN;
CPU_INT08U  const  OSDbg_QPendAbortEn          = OS_CFG_Q_PEND_ABORT_EN;
CPU_INT16U  const  OSDbg_QSize                 = sizeof(OS_Q);                 /* Size in bytes of OS_Q structure     */
#else
CPU_INT08U  const  OSDbg_QDelEn                = 0u;
CPU_INT08U  const  OSDbg_QFlushEn              = 0u;
CPU_INT08U  const  OSDbg_QPendAbortEn          = 0u;
CPU_INT16U  const  OSDbg_QSize                 = 0u;
#endif


CPU_INT08U  const  OSDbg_SchedRoundRobinEn     = OS_CFG_SCHED_ROUND_ROBIN_EN;


OS_SEM      const  OSDbg_Sem                   = { 0u };
CPU_INT08U  const  OSDbg_SemEn                 = OS_CFG_SEM_EN;
#if (OS_CFG_SEM_EN == DEF_ENABLED)
CPU_INT08U  const  OSDbg_SemDelEn              = OS_CFG_SEM_DEL_EN;
CPU_INT08U  const  OSDbg_SemPendAbortEn        = OS_CFG_SEM_PEND_ABORT_EN;
CPU_INT08U  const  OSDbg_SemSetEn              = OS_CFG_SEM_SET_EN;
CPU_INT16U  const  OSDbg_SemSize               = sizeof(OS_SEM);               /* Size in bytes of OS_SEM             */
#else
CPU_INT08U  const  OSDbg_SemDelEn              = 0u;
CPU_INT08U  const  OSDbg_SemPendAbortEn        = 0u;
CPU_INT08U  const  OSDbg_SemSetEn              = 0u;
CPU_INT16U  const  OSDbg_SemSize               = 0u;
#endif


CPU_INT16U  const  OSDbg_RdyList               = sizeof(OS_RDY_LIST);
CPU_INT32U  const  OSDbg_RdyListSize           = sizeof(OSRdyList);            /* Number of bytes in the ready table  */

CPU_INT08U  const  OSDbg_StkWidth              = sizeof(CPU_STK);

CPU_INT08U  const  OSDbg_StatTaskEn            = OS_CFG_STAT_TASK_EN;
CPU_INT08U  const  OSDbg_StatTaskStkChkEn      = OS_CFG_STAT_TASK_STK_CHK_EN;

CPU_INT08U  const  OSDbg_TaskChangePrioEn      = OS_CFG_TASK_CHANGE_PRIO_EN;
CPU_INT08U  const  OSDbg_TaskDelEn             = OS_CFG_TASK_DEL_EN;
CPU_INT08U  const  OSDbg_TaskQEn               = OS_CFG_TASK_Q_EN;
CPU_INT08U  const  OSDbg_TaskQPendAbortEn      = OS_CFG_TASK_Q_PEND_ABORT_EN;
CPU_INT08U  const  OSDbg_TaskProfileEn         = OS_CFG_TASK_PROFILE_EN;
CPU_INT16U  const  OSDbg_TaskRegTblSize        = OS_CFG_TASK_REG_TBL_SIZE;
CPU_INT08U  const  OSDbg_TaskSemPendAbortEn    = OS_CFG_TASK_SEM_PEND_ABORT_EN;
CPU_INT08U  const  OSDbg_TaskSuspendEn         = OS_CFG_TASK_SUSPEND_EN;


CPU_INT16U  const  OSDbg_TCBSize               = sizeof(OS_TCB);               /* Size in Bytes of OS_TCB             */

CPU_INT16U  const  OSDbg_TickListSize          = sizeof(OS_TICK_LIST);

CPU_INT08U  const  OSDbg_TimeDlyHMSMEn         = OS_CFG_TIME_DLY_HMSM_EN;
CPU_INT08U  const  OSDbg_TimeDlyResumeEn       = OS_CFG_TIME_DLY_RESUME_EN;

#if defined(OS_CFG_TLS_TBL_SIZE) && (OS_CFG_TLS_TBL_SIZE > 0u)
CPU_INT16U  const  OSDbg_TLS_TblSize           = OS_CFG_TLS_TBL_SIZE * sizeof(OS_TLS);
#else
CPU_INT16U  const  OSDbg_TLS_TblSize           = 0u;
#endif


OS_TMR      const  OSDbg_Tmr                   = { 0u };
CPU_INT08U  const  OSDbg_TmrEn                 = OS_CFG_TMR_EN;
#if (OS_CFG_TMR_EN == DEF_ENABLED)
CPU_INT08U  const  OSDbg_TmrDelEn              = OS_CFG_TMR_DEL_EN;
CPU_INT16U  const  OSDbg_TmrSize               = sizeof(OS_TMR);
#else
CPU_INT08U  const  OSDbg_TmrDelEn              = 0u;
CPU_INT16U  const  OSDbg_TmrSize               = 0u;
#endif

CPU_INT16U  const  OSDbg_VersionNbr            = OS_VERSION;


/*
************************************************************************************************************************
*                                                      DEBUG DATA
*                                     TOTAL DATA SPACE (i.e. RAM) USED BY uC/OS-III
************************************************************************************************************************
*/

CPU_INT32U  const  OSDbg_DataSize = sizeof(OSIntNestingCtr)

#if (OS_CFG_APP_HOOKS_EN == DEF_ENABLED)
#if (OS_CFG_TASK_STK_REDZONE_EN == DEF_ENABLED)
                                  + sizeof(OS_AppRedzoneHitHookPtr)
#endif
                                  + sizeof(OS_AppTaskCreateHookPtr)
                                  + sizeof(OS_AppTaskDelHookPtr)
                                  + sizeof(OS_AppTaskReturnHookPtr)

                                  + sizeof(OS_AppIdleTaskHookPtr)
                                  + sizeof(OS_AppStatTaskHookPtr)
                                  + sizeof(OS_AppTaskSwHookPtr)
                                  + sizeof(OS_AppTimeTickHookPtr)
#endif

#if (OS_CFG_DBG_EN == DEF_ENABLED)
                                  + sizeof(OSIdleTaskCtr)
#endif
#if (OS_CFG_TASK_IDLE_EN == DEF_ENABLED)
                                  + sizeof(OSIdleTaskTCB)
#endif

#ifdef CPU_CFG_INT_DIS_MEAS_EN
                                  + sizeof(OSIntDisTimeMax)
#endif

                                  + sizeof(OSRunning)
                                  + sizeof(OSInitialized)

#ifdef OS_SAFETY_CRITICAL_IEC61508
                                  + sizeof(OSSafetyCriticalStartFlag)
#endif

#if (OS_CFG_FLAG_EN == DEF_ENABLED)
#if (OS_CFG_DBG_EN == DEF_ENABLED)
                                  + sizeof(OSFlagDbgListPtr)
                                  + sizeof(OSFlagQty)
#endif
#endif

#if (OS_CFG_MON_EN == DEF_ENABLED)
#if (OS_CFG_DBG_EN == DEF_ENABLED)
                                  + sizeof(OSMonDbgListPtr)
                                  + sizeof(OSMonQty)
#endif
#endif

#if (OS_CFG_MEM_EN == DEF_ENABLED)
#if (OS_CFG_DBG_EN == DEF_ENABLED)
                                  + sizeof(OSMemDbgListPtr)
                                  + sizeof(OSMemQty)
#endif
#endif

#if (OS_MSG_EN == DEF_ENABLED)
                                  + sizeof(OSMsgPool)
#endif

#if (OS_CFG_MUTEX_EN == DEF_ENABLED)
#if (OS_CFG_DBG_EN == DEF_ENABLED)
                                  + sizeof(OSMutexDbgListPtr)
                                  + sizeof(OSMutexQty)
#endif
#endif

                                  + sizeof(OSPrioCur)
                                  + sizeof(OSPrioHighRdy)
                                  + sizeof(OSPrioTbl)

#if (OS_CFG_Q_EN == DEF_ENABLED)
#if (OS_CFG_DBG_EN == DEF_ENABLED)
                                  + sizeof(OSQDbgListPtr)
                                  + sizeof(OSQQty)
#endif
#endif

                                  + sizeof(OSRdyList)

                                  + sizeof(OSSchedLockNestingCtr)

#if (OS_CFG_SCHED_LOCK_TIME_MEAS_EN == DEF_ENABLED)
                                  + sizeof(OSSchedLockTimeBegin)
                                  + sizeof(OSSchedLockTimeMax)
                                  + sizeof(OSSchedLockTimeMaxCur)
#endif

#if (OS_CFG_SCHED_ROUND_ROBIN_EN == DEF_ENABLED)
                                  + sizeof(OSSchedRoundRobinDfltTimeQuanta)
                                  + sizeof(OSSchedRoundRobinEn)
#endif

#if (OS_CFG_SEM_EN == DEF_ENABLED)
#if (OS_CFG_DBG_EN == DEF_ENABLED)
                                  + sizeof(OSSemDbgListPtr)
#endif
                                  + sizeof(OSSemQty)
#endif
#if ((OS_CFG_TASK_PROFILE_EN == DEF_ENABLED) || (OS_CFG_DBG_EN == DEF_ENABLED))
                                  + sizeof(OSTaskCtxSwCtr)
#if (OS_CFG_DBG_EN == DEF_ENABLED)
                                  + sizeof(OSTaskDbgListPtr)
#endif
#endif

                                  + sizeof(OSTaskQty)


#if (OS_CFG_STAT_TASK_EN == DEF_ENABLED)
                                  + sizeof(OSStatResetFlag)
                                  + sizeof(OSStatTaskCPUUsage)
                                  + sizeof(OSStatTaskCPUUsageMax)
                                  + sizeof(OSStatTaskCtr)
                                  + sizeof(OSStatTaskCtrMax)
                                  + sizeof(OSStatTaskCtrRun)
                                  + sizeof(OSStatTaskRdy)
                                  + sizeof(OSStatTaskTCB)
#if (OS_CFG_TS_EN == DEF_ENABLED)
                                  + sizeof(OSStatTaskTimeMax)
#endif
#endif

#if (OS_CFG_TASK_TICK_EN == DEF_ENABLED)
                                  + sizeof(OSTickCtr)
                                  + sizeof(OSTickTaskTCB)
#if (OS_CFG_TS_EN == DEF_ENABLED)
                                  + sizeof(OSTickTaskTimeMax)
#endif
                                  + sizeof(OSTickListDly)
                                  + sizeof(OSTickListTimeout)
#endif

#if (OS_CFG_TMR_EN == DEF_ENABLED)
#if (OS_CFG_DBG_EN == DEF_ENABLED)
                                  + sizeof(OSTmrDbgListPtr)
                                  + sizeof(OSTmrListEntries)
#endif
                                  + sizeof(OSTmrListPtr)
#if (OS_CFG_MUTEX_EN == DEF_ENABLED)
                                  + sizeof(OSTmrMutex)
#endif
#if (OS_CFG_DBG_EN == DEF_ENABLED)
                                  + sizeof(OSTmrQty)
#endif
                                  + sizeof(OSTmrTaskTCB)
#if (OS_CFG_TS_EN == DEF_ENABLED)
                                  + sizeof(OSTmrTaskTimeMax)
#endif
                                  + sizeof(OSTmrTickCtr)
                                  + sizeof(OSTmrUpdateCnt)
                                  + sizeof(OSTmrUpdateCtr)
#endif

#if (OS_CFG_TASK_REG_TBL_SIZE > 0u)
                                  + sizeof(OSTaskRegNextAvailID)
#endif

                                  + sizeof(OSTCBCurPtr)
                                  + sizeof(OSTCBHighRdyPtr);


/*
************************************************************************************************************************
*                                               OS DEBUG INITIALIZATION
*
* Description: This function is used to make sure that debug variables that are unused in the application are not
*              optimized away.  This function might not be necessary for all compilers.  In this case, you should simply
*              DELETE the code in this function while still leaving the declaration of the function itself.
*
* Arguments  : none
*
* Returns    : none
*
* Note(s)    : (1) This code doesn't do anything, it simply prevents the compiler from optimizing out the 'const'
*                  variables which are used by this file.
*              (2) You may decide to 'compile out' the code (by using #if 0/#endif) INSIDE the function if your compiler
*                  DOES NOT optimize out the 'const' variables above.
************************************************************************************************************************
*/
void  OS_Dbg_Init (void)
{
    volatile static CPU_INT32U u32Trash = 0;

    u32Trash += (CPU_INT32U) &OSDbg_DbgEn;
    u32Trash += (CPU_INT32U) &OSDbg_DataSize;

    u32Trash += (CPU_INT32U) &OSDbg_ArgChkEn;
    u32Trash += (CPU_INT32U) &OSDbg_AppHooksEn;

    u32Trash += (CPU_INT32U) &OSDbg_EndiannessTest;

    u32Trash += (CPU_INT32U) &OSDbg_CalledFromISRChkEn;

    u32Trash += (CPU_INT32U) &OSDbg_FlagGrp;
    u32Trash += (CPU_INT32U) &OSDbg_FlagEn;
#if (OS_CFG_FLAG_EN == DEF_ENABLED)
    u32Trash += (CPU_INT32U) &OSDbg_FlagDelEn;
    u32Trash += (CPU_INT32U) &OSDbg_FlagModeClrEn;
    u32Trash += (CPU_INT32U) &OSDbg_FlagPendAbortEn;
    u32Trash += (CPU_INT32U) &OSDbg_FlagGrpSize;
    u32Trash += (CPU_INT32U) &OSDbg_FlagWidth;
#endif

    u32Trash += (CPU_INT32U) &OSDbg_Mem;
    u32Trash += (CPU_INT32U) &OSDbg_MemEn;
#if (OS_CFG_MEM_EN == DEF_ENABLED)
    u32Trash += (CPU_INT32U) &OSDbg_MemSize;
#endif

    u32Trash += (CPU_INT32U) &OSDbg_MsgEn;
#if (OS_MSG_EN == DEF_ENABLED)
    u32Trash += (CPU_INT32U) &OSDbg_MsgSize;
    u32Trash += (CPU_INT32U) &OSDbg_MsgPoolSize;
    u32Trash += (CPU_INT32U) &OSDbg_MsgQSize;
#endif

    u32Trash += (CPU_INT32U) &OSDbg_Mutex;
    u32Trash += (CPU_INT32U) &OSDbg_MutexEn;
#if (OS_CFG_MUTEX_EN == DEF_ENABLED)
    u32Trash += (CPU_INT32U) &OSDbg_MutexDelEn;
    u32Trash += (CPU_INT32U) &OSDbg_MutexPendAbortEn;
    u32Trash += (CPU_INT32U) &OSDbg_MutexSize;
#endif

    u32Trash += (CPU_INT32U) &OSDbg_ObjTypeChkEn;

    u32Trash += (CPU_INT32U) &OSDbg_PendListSize;
    u32Trash += (CPU_INT32U) &OSDbg_PendObjSize;

    u32Trash += (CPU_INT32U) &OSDbg_PrioMax;
    u32Trash += (CPU_INT32U) &OSDbg_PrioTblSize;

    u32Trash += (CPU_INT32U) &OSDbg_PtrSize;

    u32Trash += (CPU_INT32U) &OSDbg_Q;
    u32Trash += (CPU_INT32U) &OSDbg_QEn;
#if (OS_CFG_Q_EN == DEF_ENABLED)
    u32Trash += (CPU_INT32U) &OSDbg_QDelEn;
    u32Trash += (CPU_INT32U) &OSDbg_QFlushEn;
    u32Trash += (CPU_INT32U) &OSDbg_QPendAbortEn;
    u32Trash += (CPU_INT32U) &OSDbg_QSize;
#endif

    u32Trash += (CPU_INT32U) &OSDbg_SchedRoundRobinEn;

    u32Trash += (CPU_INT32U) &OSDbg_Sem;
    u32Trash += (CPU_INT32U) &OSDbg_SemEn;
#if (OS_CFG_SEM_EN == DEF_ENABLED)
    u32Trash += (CPU_INT32U) &OSDbg_SemDelEn;
    u32Trash += (CPU_INT32U) &OSDbg_SemPendAbortEn;
    u32Trash += (CPU_INT32U) &OSDbg_SemSetEn;
    u32Trash += (CPU_INT32U) &OSDbg_SemSize;
#endif

    u32Trash += (CPU_INT32U) &OSDbg_RdyList;
    u32Trash += (CPU_INT32U) &OSDbg_RdyListSize;

    u32Trash += (CPU_INT32U) &OSDbg_StkWidth;

    u32Trash += (CPU_INT32U) &OSDbg_StatTaskEn;
    u32Trash += (CPU_INT32U) &OSDbg_StatTaskStkChkEn;

    u32Trash += (CPU_INT32U) &OSDbg_TaskChangePrioEn;
    u32Trash += (CPU_INT32U) &OSDbg_TaskDelEn;
    u32Trash += (CPU_INT32U) &OSDbg_TaskQEn;
    u32Trash += (CPU_INT32U) &OSDbg_TaskQPendAbortEn;
    u32Trash += (CPU_INT32U) &OSDbg_TaskProfileEn;
    u32Trash += (CPU_INT32U) &OSDbg_TaskRegTblSize;
    u32Trash += (CPU_INT32U) &OSDbg_TaskSemPendAbortEn;
    u32Trash += (CPU_INT32U) &OSDbg_TaskSuspendEn;

    u32Trash += (CPU_INT32U) &OSDbg_TCBSize;

    u32Trash += (CPU_INT32U) &OSDbg_TickListSize;

    u32Trash += (CPU_INT32U) &OSDbg_TimeDlyHMSMEn;
    u32Trash += (CPU_INT32U) &OSDbg_TimeDlyResumeEn;

    u32Trash += (CPU_INT32U) &OSDbg_TLS_TblSize;

    u32Trash += (CPU_INT32U) &OSDbg_Tmr;
    u32Trash += (CPU_INT32U) &OSDbg_TmrEn;
#if (OS_CFG_TMR_EN == DEF_ENABLED)
    u32Trash += (CPU_INT32U) &OSDbg_TmrDelEn;
    u32Trash += (CPU_INT32U) &OSDbg_TmrSize;
#endif

    u32Trash += (CPU_INT32U) &OSDbg_VersionNbr;
}
#endif
