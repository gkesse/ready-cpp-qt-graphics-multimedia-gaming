//===============================================
#include "GDs1232.h"
#include "GConfig.h"
//===============================================
static bit Wdog_State;
//===============================================
void GWdog_Init() {
	Wdog_State = WDOG_OFF;
	WDOG_PIN = WDOG_OFF;
}
//===============================================
void GWdog_Feed() {
	if(Wdog_State == WDOG_OFF) {
	  	Wdog_State = WDOG_ON;
		WDOG_PIN = WDOG_ON;

	}
	else if(Wdog_State == WDOG_ON) {
	  	Wdog_State = WDOG_OFF;
		WDOG_PIN = WDOG_OFF;
	}
}
//===============================================
