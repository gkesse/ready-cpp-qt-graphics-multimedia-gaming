//===============================================
#include "GUart.h"
#include "GPortDef.h"
#include <string.h>
//===============================================
void GUart_Init(uint baud) {
    uint m_PRELOAD = (256 - (uchar)((((ulong)OSC_FREQ / 100) * 3125) / ((ulong)baud * OSC_PER_INST * 1000)));
    SCON = 0x50;          
    TMOD |= 0x20;                       
    TH1 = m_PRELOAD;          
    TH1 = m_PRELOAD;          
    TI = 1;  
    ES = 0;          
    TR1 = 1;             
}
//===============================================
void GUart_Char(char d) {
	while (TI == 0);
	TI = 0;
	if(d == '\n') d = 13;
	SBUF = d;
}
//===============================================
void GUart_Str(const char* d) {
	int i;
	uchar m_length = strlen(d);
	for(i = 0; i < m_length; i++) {
        GUart_Char(d[i]);
	}
}
//===============================================

