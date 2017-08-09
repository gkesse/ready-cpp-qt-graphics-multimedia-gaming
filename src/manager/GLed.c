//===============================================
#include "GLed.h"
#include "GPortDef.h"
//===============================================
static bit Flash_State;
//===============================================
void GLed_Init() {
	Flash_State = LED_OFF;
	LED7 = LED_OFF;
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
