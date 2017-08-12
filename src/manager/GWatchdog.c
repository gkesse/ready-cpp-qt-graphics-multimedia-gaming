//===============================================
#include "GWatchdog.h"
//===============================================
void GWdog_Init() {
    // WDTCON = PS2 ; PS1 ; PS0 ; WDIDLE ; DISRTO ; HWDT ; WDTRST ; WDTEN
    // PS2 = 1 ; PS1 = 0; PS0 = 0 -> (2^5) * 16 ms = 512 ms for Watchdog Timer
    // WDIDLE = 0 -> Enable in Idle mode
    // DISRTO = 0 -> Watchdog controls reset pin
    // HWDT = 0 -> Watchdog is software mode
    // WSWRST = 1 -> Resets the Watchdog Timer
    // WDTEN = 1 -> Watchdog enabled
    // WDTCON = 10100011 = A3
    WMCON |= 0xA3;
}
//===============================================
void GWdog_Feed() {
    // WDTCON = PS2 ; PS1 ; PS0 ; WDIDLE ; DISRTO ; HWDT ; WDTRST ; WDTEN
    // WSWRST = 1 -> Resets the Watchdog Timer
    // WDTCON = 00000010 = 02
    WMCON |= 0x02;
}
//===============================================
