//===============================================
#include "GDelay.h"
//===============================================
#define PRELOAD01 (65536 - ((OSC_FREQ * 1) / (OSC_PER_INST * 1000))) // ms
#define PRELOAD01H (PRELOAD01 / 256)
#define PRELOAD01L (PRELOAD01 % 256)
//===============================================
void GDelay_T0(uint ms) {
    uint m_ms;
    TMOD &= 0xF0;
    TMOD |= 0x01; 
    ET0 = 0;

    for(m_ms = 0; m_ms < ms; m_ms++) {
        TH0 = PRELOAD01H;
        TL0 = PRELOAD01L;
        TF0 = 0; 
        TR0 = 1; 
        while(TF0 == 0);
        TR0 = 0; 
    }
}
//===============================================
void GDelay_T1(uint ms) {
    uint m_ms;
    TMOD &= 0x0F;
    TMOD |= 0x10; 
    ET1 = 0;

    for(m_ms = 0; m_ms < ms; m_ms++) {
        TH1 = PRELOAD01H;
        TL1 = PRELOAD01L;
        TF1 = 0; 
        TR1 = 1; 
        while(TF1 == 0);
        TR1 = 0; 
    }
}
//===============================================
void GDelay_ms(uint ms) {
	uint m_msX;
	uint m_msY;
	for (m_msX = 0; m_msX < ms; m_msX++) {
	    for (m_msY = 0; m_msY < 123; m_msY++);
	}
}
//===============================================
