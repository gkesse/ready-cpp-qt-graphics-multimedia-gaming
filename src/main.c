//===============================================
#include "GUart.h"
//===============================================
void main() {
    GUart_Init(9600);
	GUart_Str("Hello World!\n");
	GUart_Str("Hello World!\n");
	GUart_Str("Hello World!\n");
	GUart_Str("Hello World!\n");
    while(1);
}
//===============================================
