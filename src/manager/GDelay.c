//===============================================
#include "GDelay.h"
#include "GConfig.h"
//===============================================
#define PRELOAD01 (65536 - (OSC_FREQ / (OSC_PER_INST * 1000)))
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
