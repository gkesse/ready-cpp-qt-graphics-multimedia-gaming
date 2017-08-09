//===============================================
#include "manager/GSch.h"
#include "manager/GLed.h"
//===============================================
void main() {
	GSch_Init();
	GLed_Init();
	GSch_Add_Task(GLed_Flash, 0, 1000);
	GSch_Start();
	while(1) {
		GSch_Dispatch_Tasks();
	}
}
//===============================================
