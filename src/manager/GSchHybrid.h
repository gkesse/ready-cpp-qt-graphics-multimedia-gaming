//===============================================
#ifndef _GSchHybrid_
#define _GSchHybrid_
//===============================================
#include "GTypeDef.h"
//===============================================
typedef struct {
	void (*pTask)();
	uint delay;
	uint period;
	uchar runMe;
	uchar coop;
} GTask;
//===============================================
void GSch_Init();
void GSch_Start();
void GSch_Dispatch_Tasks();
void GSch_Add_Task(void (*pTask)(), const uint delay, const uint period, const GBit coop);
//===============================================
#ifdef GSDCC /* SDCC C Compiler	*/
void GSch_Update() __interrupt(INTERRUPT_TIMER_T2); 
#endif
//===============================================
#endif
//===============================================
