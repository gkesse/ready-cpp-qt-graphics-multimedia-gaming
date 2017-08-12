//===============================================
#include "GLed.h"
#include "GPortDef.h"
#include "GDelay.h"
//===============================================
static bit Flash_State;
static bit Led_Lock;
static uint Led_Time;
//===============================================
void GLed_Init() {
	Flash_State = LED_OFF;
	Led_Lock = UNLOCKED;
	Led_Time = 0;
}
//===============================================
void GLed_Flash() {
	if(Flash_State == LED_OFF) {
	  	Flash_State = LED_ON;
		LED7 = LED_ON;

	}
	else if(Flash_State == LED_ON) {
	   	Flash_State = LED_OFF;
		LED7 = LED_OFF;
	}
}
//===============================================
void GLed_Time() {
	if(++Led_Time < 20) return;
	Led_Time = 0;
	if(Flash_State == LED_OFF) {
	  	Flash_State = LED_ON;
		LED7 = LED_ON;

	}
	else if(Flash_State == LED_ON) {
	   	Flash_State = LED_OFF;
		LED7 = LED_OFF;
	}
}
//===============================================
void GLed_Short() {
	if(Led_Lock == LOCKED) return;
	Led_Lock = LOCKED;

	if(Flash_State == LED_OFF) {
	  	Flash_State = LED_ON;
		LED0 = LED_ON;
		LED7 = LED_ON;

	}
	else if(Flash_State == LED_ON) {
	   	Flash_State = LED_OFF;
		LED0 = LED_OFF;
		LED7 = LED_OFF;
	}

	Led_Lock = UNLOCKED;
}
//===============================================
void GLed_Long() {
	uchar m_count;

	if(Led_Lock == LOCKED) return;
	Led_Lock = LOCKED;

	for(m_count = 0; m_count < 5; m_count++) {
		LED = 0xF0;
		GDelay_T0(500);
		LED = 0x0F;
		GDelay_T0(500);
	}

	Led_Lock = UNLOCKED;
}
//===============================================
