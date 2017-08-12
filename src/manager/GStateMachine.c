//===============================================
#include "GStateMachine.h"
#include "GPortDef.h"
#include "GEnum.h"
//===============================================
static GLight Light_State_L1;
static uint Light_Time_L1;
static GLight Light_State_L2;
static uint Light_Time_L2;
//===============================================
void GState_Init() {
    Light_State_L1 = RED;
    Light_Time_L1 = 0;
    Light_State_L2 = GREEN;
    Light_Time_L2 = 0;
}
//===============================================
void GState_Light_L1() {
    switch(Light_State_L1) {
        case RED: {
            LIGHT_RED_L1 = LIGHT_ON;
            LIGHT_AMBER_L1 = LIGHT_OFF;
            LIGHT_GREEN_L1 = LIGHT_OFF;
            if(++Light_Time_L1 >= LIGHT_RED_DURATION) {
                Light_State_L1 = RED_AMBER;
                Light_Time_L1 = 0;    
            } 
            break;
        }
        case RED_AMBER: {
            LIGHT_RED_L1 = LIGHT_ON;
            LIGHT_AMBER_L1 = LIGHT_OFF;
            LIGHT_GREEN_L1 = LIGHT_OFF;
            if(++Light_Time_L1 >= LIGHT_RED_AMBER_DURATION) {
                Light_State_L1 = RED_RED_1;
                Light_Time_L1 = 0;    
            } 
            break;
        }
        case RED_RED_1: {
            LIGHT_RED_L1 = LIGHT_ON;
            LIGHT_AMBER_L1 = LIGHT_OFF;
            LIGHT_GREEN_L1 = LIGHT_OFF;
            if(++Light_Time_L1 >= LIGHT_RED_RED_1_DURATION) {
                Light_State_L1 = GREEN;
                Light_Time_L1 = 0;    
            } 
            break;
        }
        case GREEN: {
            LIGHT_RED_L1 = LIGHT_OFF;
            LIGHT_AMBER_L1 = LIGHT_OFF;
            LIGHT_GREEN_L1 = LIGHT_ON;
            if(++Light_Time_L1 >= LIGHT_GREEN_DURATION) {
                Light_State_L1 = AMBER;
                Light_Time_L1 = 0;    
            } 
            break;
        }
        case AMBER: {
            LIGHT_RED_L1 = LIGHT_OFF;
            LIGHT_AMBER_L1 = LIGHT_ON;
            LIGHT_GREEN_L1 = LIGHT_OFF;
            if(++Light_Time_L1 >= LIGHT_AMBER_DURATION) {
                Light_State_L1 = RED_RED_2;
                Light_Time_L1 = 0;    
            } 
            break;
        }
        case RED_RED_2: {
            LIGHT_RED_L1 = LIGHT_ON;
            LIGHT_AMBER_L1 = LIGHT_OFF;
            LIGHT_GREEN_L1 = LIGHT_OFF;
            if(++Light_Time_L1 >= LIGHT_RED_RED_2_DURATION) {
                Light_State_L1 = RED;
                Light_Time_L1 = 0;    
            } 
            break;
        }
    }

}
//===============================================
void GState_Light_L2() {
    switch(Light_State_L2) {
        case RED: {
            LIGHT_RED_L2 = LIGHT_ON;
            LIGHT_AMBER_L2 = LIGHT_OFF;
            LIGHT_GREEN_L2 = LIGHT_OFF;
            if(++Light_Time_L2 >= LIGHT_RED_DURATION) {
                Light_State_L2 = RED_AMBER;
                Light_Time_L2 = 0;    
            } 
            break;
        }
        case RED_AMBER: {
            LIGHT_RED_L2 = LIGHT_ON;
            LIGHT_AMBER_L2 = LIGHT_OFF;
            LIGHT_GREEN_L2 = LIGHT_OFF;
            if(++Light_Time_L2 >= LIGHT_RED_AMBER_DURATION) {
                Light_State_L2 = RED_RED_1;
                Light_Time_L2 = 0;    
            } 
            break;
        }
        case RED_RED_1: {
            LIGHT_RED_L2 = LIGHT_ON;
            LIGHT_AMBER_L2 = LIGHT_OFF;
            LIGHT_GREEN_L2 = LIGHT_OFF;
            if(++Light_Time_L2 >= LIGHT_RED_RED_1_DURATION) {
                Light_State_L2 = GREEN;
                Light_Time_L2 = 0;    
            } 
            break;
        }
        case GREEN: {
            LIGHT_RED_L2 = LIGHT_OFF;
            LIGHT_AMBER_L2 = LIGHT_OFF;
            LIGHT_GREEN_L2 = LIGHT_ON;
            if(++Light_Time_L2 >= LIGHT_GREEN_DURATION) {
                Light_State_L2 = AMBER;
                Light_Time_L2 = 0;    
            } 
            break;
        }
        case AMBER: {
            LIGHT_RED_L2 = LIGHT_OFF;
            LIGHT_AMBER_L2 = LIGHT_ON;
            LIGHT_GREEN_L2 = LIGHT_OFF;
            if(++Light_Time_L2 >= LIGHT_AMBER_DURATION) {
                Light_State_L2 = RED_RED_2;
                Light_Time_L2 = 0;    
            } 
            break;
        }
        case RED_RED_2: {
            LIGHT_RED_L2 = LIGHT_ON;
            LIGHT_AMBER_L2 = LIGHT_OFF;
            LIGHT_GREEN_L2 = LIGHT_OFF;
            if(++Light_Time_L2 >= LIGHT_RED_RED_2_DURATION) {
                Light_State_L2 = RED;
                Light_Time_L2 = 0;    
            } 
            break;
        }
    }

}
//===============================================
