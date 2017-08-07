//===============================================
#include "manager/GDelay.h"
#include "manager/GWatchdog.h"
//===============================================
void main() {
	GWdog_Init();
	while(1) {
		GDelay_T0(1000);
		GWdog_Feed();
    }
}
//===============================================
