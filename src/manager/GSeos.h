//===============================================
#ifndef _GSeos_
#define _GSeos_
//===============================================
#include "GTypeDef.h"
//===============================================
void GSeos_Init(const uchar ms);
void GSeos_Start();
void GSeos_Go_To_Sleep();
//===============================================
#ifdef GSDCC /* SDCC C Compiler	*/
void GSeos_Update() __interrupt(INTERRUPT_TIMER_T2);	  
#endif
//===============================================
#endif
//===============================================
