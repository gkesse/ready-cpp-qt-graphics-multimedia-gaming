//===============================================
#ifndef _GPort_
#define _GPort_
//===============================================
#include "GTypeDef.h"
//===============================================
void GPort_Write_Data(uchar d);
void GPort_Write_Bit(uchar pin, bit d);
uchar GPort_Read_Data();
bit GPort_Read_Bit(uchar pin);
//===============================================
#endif
//===============================================
