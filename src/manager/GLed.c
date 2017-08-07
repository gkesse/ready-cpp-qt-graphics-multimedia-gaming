//===============================================
#include "GLed.h"
#include "GConfig.h"
//===============================================
static bit m_flashState;
//===============================================
void GLed_Init() {
	m_flashState = 0;
	LED7 = LED_OFF;
}
//===============================================
void GLed_Flash() {
	if(m_flashState == 0) {
	  	m_flashState = 1;
		LED7 = LED_ON;

	}
	else if(m_flashState == 1) {
	   	m_flashState = 0;
		LED7 = LED_OFF;
	}
}
//===============================================
