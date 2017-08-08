//===============================================
#include "GUart.h"
#include "GConfig.h"
//===============================================
void GUart_Init(uint baud) {
	uint m_PRELOAD = (256 - (uchar)((((ulong)OSC_FREQ / 100) * 3125) 
	/ ((ulong)baud * OSC_PER_INST * 1000)));
	SCON = 0x50;          
	TMOD |= 0x20;         			  
	TH1   = m_PRELOAD;          
	TH1   = m_PRELOAD;          
	TI    = 1;  
	ES = 0;          
	TR1   = 1;             
}
//===============================================
