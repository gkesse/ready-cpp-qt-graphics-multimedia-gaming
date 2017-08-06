//===============================================
#include "manager/GPort.h"
#include "manager/GDelay.h"
//===============================================
void main() {
	while(1) {
	    //GPort_Write_Data(0xAA);
	    GPort_Write_Bit(3, 0);
	    GPort_Write_Bit(7, GPort_Read_Bit(0));
	    //GPort_Read_Data();
    }
}
//===============================================
