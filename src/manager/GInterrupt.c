//===============================================
#include "GInterrupt.h"
#include "GLed.h"
//===============================================
#define PRELOAD01 (65536 - ((OSC_FREQ * 1) / (OSC_PER_INST * 1000))) // ms
#define PRELOAD01H (PRELOAD01 / 256)
#define PRELOAD01L (PRELOAD01 % 256)
//===============================================
void GInterrupt_Start() {
    EA = 1;
}
//===============================================
void GTimer0_Reload() {
    TR0 = 0;
    TH0 = PRELOAD01H;
    TL0 = PRELOAD01L;
    TR0 = 1;
}
//===============================================
void GTimer1_Reload() {
    TR1 = 0;
    TH1 = PRELOAD01H;
    TL1 = PRELOAD01L;
    TR1 = 1;
}
//===============================================
void GTimer0_Init() {
    TMOD &= 0xF0;
    TMOD |= 0x01;
    GTimer0_Reload();
    ET0 = 1; 
}
//===============================================
void GTimer1_Init() {
    TMOD &= 0x0F;
    TMOD |= 0x10;
    GTimer1_Reload();
    ET1 = 1; 
}
//===============================================
void GTimer2_Init() {
    T2CON = 0x00; 
    TH2 = PRELOAD01H; 
    RCAP2H = PRELOAD01H; 
    TL2 = PRELOAD01L; 
    RCAP2L = PRELOAD01L;
    ET2 = 1;
    TR2 = 1;
}
//===============================================
void GInterrupt_Timer_0() interrupt INTERRUPT_TIMER_0 {
    GTimer0_Reload();
    GLed_Flash();
}
//===============================================
void GInterrupt_Timer_1() interrupt INTERRUPT_TIMER_1 {
    GTimer1_Reload();
    GLed_Flash();
}
//===============================================
void GInterrupt_Timer_2() interrupt INTERRUPT_TIMER_2 {
    TF2 = 0;
    GLed_Flash();
}
//===============================================
