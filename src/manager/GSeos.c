//===============================================
#include "GSeos.h"
#include "GLed.h"
#include "GPortDef.h"
//===============================================
void GSeos_Init(const uchar ms) {
    uint m_PRELOAD01 = (65536 - ((OSC_FREQ * ms) / (OSC_PER_INST * 1000)));    // ms
    uchar m_PRELOAD01H = (m_PRELOAD01 / 256);
    uchar m_PRELOAD01L = (m_PRELOAD01 % 256);
    T2CON = 0x00; 
    TH2 = m_PRELOAD01H; 
    RCAP2H = m_PRELOAD01H; 
    TL2 = m_PRELOAD01L; 
    RCAP2L = m_PRELOAD01L;
    ET2 = 1;
    TR2 = 1;
}
//===============================================
void GSeos_Start() {
    EA = 1;
}
//===============================================
void GSeos_Go_To_Sleep() {
    PCON |= 0x01;
}
//===============================================
#ifdef GSDCC /* SDCC C Compiler	*/
void GSeos_Update() __interrupt(INTERRUPT_TIMER_T2)	  
#else /* Keil µVision C Compiler	*/
void GSeos_Update() interrupt INTERRUPT_TIMER_T2 
#endif
{    
    TF2 = 0;
    GLed_Time();
}
//===============================================

