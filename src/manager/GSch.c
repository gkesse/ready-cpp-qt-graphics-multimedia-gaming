//===============================================
#include "GSch.h"
//===============================================
#define PRELOAD01 (65536 - ((OSC_FREQ * 1) / (OSC_PER_INST * 1000))) // ms
#define PRELOAD01H (PRELOAD01 / 256)
#define PRELOAD01L (PRELOAD01 % 256)
//===============================================
#define SCH_MAX_TASKS (2)
//===============================================
GTask Sch_Tasks_Map[SCH_MAX_TASKS];
//===============================================
void GSch_Go_To_Sleep();
void GSch_Delete_Task(const uchar index);
//===============================================
void GSch_Init() {
    uchar index;
    for(index = 0; index < SCH_MAX_TASKS; index++) {
        GSch_Delete_Task(index);
    }
    T2CON = 0x00; 
    TH2 = PRELOAD01H; 
    RCAP2H = PRELOAD01H; 
    TL2 = PRELOAD01L; 
    RCAP2L = PRELOAD01L;
    ET2 = 1;
    TR2 = 1;
}
//===============================================
void GSch_Start() {
    EA = 1;
}
//===============================================
void GSch_Go_To_Sleep() {
    PCON |= 0x01;
}
//===============================================
void GSch_Dispatch_Tasks() {
    uchar index;
    for(index = 0; index < SCH_MAX_TASKS; index++) {
        if(Sch_Tasks_Map[index].runMe > 0) {
            (*Sch_Tasks_Map[index].pTask)();
            Sch_Tasks_Map[index].runMe -= 1;
            if(Sch_Tasks_Map[index].period == 0) {
                GSch_Delete_Task(index);
            }
        }
    }
    GSch_Go_To_Sleep();
}
//===============================================
void GSch_Add_Task(void (*pTask)(), const uint delay, const uint period) {
    uchar index = 0;
    while((Sch_Tasks_Map[index].pTask != 0) && (index < SCH_MAX_TASKS)) index++;
    if(index == SCH_MAX_TASKS) return;
    Sch_Tasks_Map[index].pTask = pTask;
    Sch_Tasks_Map[index].delay = delay;
    Sch_Tasks_Map[index].period = period;
    Sch_Tasks_Map[index].runMe = 0;
}
//===============================================
void GSch_Delete_Task(const uchar index) {
    Sch_Tasks_Map[index].pTask = 0x0000;
    Sch_Tasks_Map[index].delay = 0;
    Sch_Tasks_Map[index].period = 0;
    Sch_Tasks_Map[index].runMe = 0;
}
//===============================================
#ifdef GSDCC /* SDCC C Compiler	*/
void GSch_Update() __interrupt(INTERRUPT_TIMER_T2) 
#else /* Keil µVision C Compiler */
void GSch_Update() interrupt INTERRUPT_TIMER_T2 
#endif
{
    uchar index;
    TF2 = 0;
    for(index = 0; index < SCH_MAX_TASKS; index++) {
        if(Sch_Tasks_Map[index].pTask != 0) {
            if(Sch_Tasks_Map[index].delay == 0) {
                Sch_Tasks_Map[index].runMe += 1;
                if(Sch_Tasks_Map[index].period != 0) {
                    Sch_Tasks_Map[index].delay = Sch_Tasks_Map[index].period;
                }
            }
            else {
                Sch_Tasks_Map[index].delay -= 1;
            }
        }
    }
}
//===============================================
