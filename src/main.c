//===============================================
#include "GSch.h"
#include "GStateMachine.h"
//===============================================
void main() {
    GSch_Init();
    GState_Init();
    GSch_Add_Task(GState_Light_L1, 0, 1000);
    GSch_Add_Task(GState_Light_L2, 1, 1000);
    GSch_Start();
    while(1) {
        GSch_Dispatch_Tasks();
    }
} 
//===============================================
   