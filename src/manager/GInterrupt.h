//===============================================
#ifndef _GInterrupt_
#define _GInterrupt_
//===============================================
#include "GTypeDef.h"
//===============================================
void GInterrupt_Start();
//===============================================
void GTimer_T0_Init();
void GTimer_T1_Init();
void GTimer_T2_Init();
//===============================================
#ifdef GSDCC /* SDCC C Compiler	*/
void GInterrupt_Timer_T0() __interrupt(INTERRUPT_TIMER_T0); 
void GInterrupt_Timer_T1() __interrupt(INTERRUPT_TIMER_T1); 
void GInterrupt_Timer_T2() __interrupt(INTERRUPT_TIMER_T2); 
#endif
//===============================================
#endif
//===============================================
