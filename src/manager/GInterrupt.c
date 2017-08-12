//===============================================
#include "GInterrupt.h"
#include "GLed.h"
//===============================================
#define PRELOAD01 (65536 - ((OSC_FREQ * 50) / (OSC_PER_INST * 1000))) // ms
#define PRELOAD01H (PRELOAD01 / 256)
#define PRELOAD01L (PRELOAD01 % 256)
//===============================================
void GTimer_T0_Reload();
void GTimer_T1_Reload();
//===============================================
void GInterrupt_Start() {
    EA = 1;
}
//===============================================
void GTimer_T0_Reload() {
    TR0 = 0;
    TH0 = PRELOAD01H;
    TL0 = PRELOAD01L;
    TR0 = 1;
}
//===============================================
void GTimer_T1_Reload() {
    TR1 = 0;
    TH1 = PRELOAD01H;
    TL1 = PRELOAD01L;
    TR1 = 1;
}
//===============================================
void GTimer_T0_Init() {
    TMOD &= 0xF0;
    TMOD |= 0x01;
    GTimer_T0_Reload();
    ET0 = 1; 
}
//===============================================
void GTimer_T1_Init() {
    TMOD &= 0x0F;
    TMOD |= 0x10;
    GTimer_T1_Reload();
    ET1 = 1; 
}
//===============================================
void GTimer_T2_Init() {
    T2CON = 0x00; 
    TH2 = PRELOAD01H; 
    RCAP2H = PRELOAD01H; 
    TL2 = PRELOAD01L; 
    RCAP2L = PRELOAD01L;
    ET2 = 1;
    TR2 = 1;
}
//===============================================
#ifdef GSDCC /* SDCC C Compiler	*/
void GInterrupt_Timer_T0() __interrupt(INTERRUPT_TIMER_T0) 
#else /* Keil µVision C Compiler */
void GInterrupt_Timer_T0() interrupt INTERRUPT_TIMER_T0 
#endif
{
    GTimer_T0_Reload();
    GLed_Time();
}
//===============================================
#ifdef GSDCC /* SDCC C Compiler	*/
void GInterrupt_Timer_T1() __interrupt(INTERRUPT_TIMER_T1) 
#else /* Keil µVision C Compiler */
void GInterrupt_Timer_T1() interrupt INTERRUPT_TIMER_T1 
#endif
{
    GTimer_T1_Reload();
    GLed_Time();
}
//===============================================
#ifdef GSDCC /* SDCC C Compiler	*/
void GInterrupt_Timer_T2() __interrupt(INTERRUPT_TIMER_T2) 
#else /* Keil µVision C Compiler */
void GInterrupt_Timer_T2() interrupt INTERRUPT_TIMER_T2 
#endif
{
    TF2 = 0;
    GLed_Time();
}
//===============================================
