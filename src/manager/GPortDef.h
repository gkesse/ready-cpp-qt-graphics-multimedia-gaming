//===============================================
#ifndef _GPortDef_
#define _GPortDef_
//===============================================
#define PORT P1
sbit PIN0 = PORT^0;
sbit PIN1 = PORT^1;
sbit PIN2 = PORT^2;
sbit PIN3 = PORT^3;
sbit PIN4 = PORT^4;
sbit PIN5 = PORT^5;
sbit PIN6 = PORT^6;
sbit PIN7 = PORT^7;
//===============================================
#define OUTPUT P2
//===============================================
#define LED P1
sbit LED0 = LED^0;
sbit LED1 = LED^1;
sbit LED2 = LED^2;
sbit LED3 = LED^3;
sbit LED4 = LED^4;
sbit LED5 = LED^5;
sbit LED6 = LED^6;
sbit LED7 = LED^7;
//===============================================
#define WDOG P1
sbit WDOG_PIN = WDOG^7;
//===============================================
#define LIGHT P1
sbit LIGHT_RED_L1 = LIGHT^0;
sbit LIGHT_AMBER_L1 = LIGHT^1;
sbit LIGHT_GREEN_L1 = LIGHT^2;
sbit LIGHT_RED_L2 = LIGHT^5;
sbit LIGHT_AMBER_L2 = LIGHT^6;
sbit LIGHT_GREEN_L2 = LIGHT^7;
//===============================================
#endif
//===============================================
