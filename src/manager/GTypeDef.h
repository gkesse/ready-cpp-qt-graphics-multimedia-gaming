//===============================================
#ifndef _GTypeDef_
#define _GTypeDef_
//===============================================
//#include <reg52.h>
#include <at89s53.h>
//===============================================
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
//===============================================
#define OSC_FREQ (11059200)
#define OSC_PER_INST (12)
//===============================================
#define FALSE (0)
#define TRUE (!FALSE)
//===============================================
#define LOCKED (1)
#define UNLOCKED (!LOCKED)
//===============================================
#define LED_OFF (1)
#define LED_ON (!LED_OFF)
//===============================================
#define WDOG_OFF (0)
#define WDOG_ON (!WDOG_OFF)
//===============================================
#define INTERRUPT_TIMER_0 1
#define INTERRUPT_TIMER_1 3
#define INTERRUPT_TIMER_2 5
//===============================================
#define LIGHT_OFF (1)
#define LIGHT_ON (!LIGHT_OFF)
#define LIGHT_GREEN_DURATION (30)
#define LIGHT_AMBER_DURATION (20)
#define LIGHT_RED_DURATION (LIGHT_GREEN_DURATION)
#define LIGHT_RED_AMBER_DURATION (LIGHT_AMBER_DURATION)
//===============================================
#endif
//===============================================
