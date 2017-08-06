//===============================================
#include "GDelay.h"
#include "GConfig.h"
//===============================================
#define PRELOAD01 (65536 - (uchar)(OSC_FREQ / (OSC_PER_INST * 1063)))
#define PRELOAD01H (PRELOAD01 / 256)
#define PRELOADO1L (PRELOAD01 % 256)
//===============================================
void GDelay_T0(uint ms) {
	uchar m_ms;
	TMOD &= 0xF0;
	TMOD |= 0x01;
	ET0 = 0;

	for(m_ms = 0; m_ms < ms; m_ms++) {
		TH0 = 
		TL0 = 
		TF0 = 0;
		TR0 = 1;
		while(1);
		TR0 = 0;
	}
}
//===============================================
