//===============================================
#include "GLed.h"
#include "GConfig.h"
//===============================================
static bit Flash_State;
static int Flash_Time;
//===============================================
void GLed_Init() {
	Flash_State = LED_OFF;
	LED7 = LED_OFF;
	Flash_Time = 0;
}
//===============================================
void GLed_Flash() {
	if(++Flash_Time <= 1000) return;
	Flash_Time = 0;
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
