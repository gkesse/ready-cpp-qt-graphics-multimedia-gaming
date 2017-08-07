//===============================================
#include "manager/GInterrupt.h"
#include "manager/GLed.h"
//===============================================
void main() {
	GLed_Init();
	GTimer1_Init();
	GInterrupt_Start();
	while(1);
}
//===============================================
