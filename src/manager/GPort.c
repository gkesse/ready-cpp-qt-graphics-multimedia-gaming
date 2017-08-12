//===============================================
#include "GPort.h"
#include "GPortDef.h"
//===============================================
void GPort_Write_Data(uchar d) {
    PORT = d;
}
//===============================================
void GPort_Write_Bit(uchar pin, bit d) {
    uchar m_pin = 1;
    m_pin <<= pin;
    if(d == true) {
        PORT |= m_pin;
        return;
    }
    m_pin = ~m_pin;
    PORT &= m_pin;
}
//===============================================
uchar GPort_Read_Data() {
    PORT = 0xFF;
    return PORT;
}
//===============================================
bit GPort_Read_Bit(uchar pin) {
    uchar m_pin = 1;
    bit m_data;
    m_pin <<= pin;
    GPort_Write_Bit(m_pin, 1);
    m_data = PORT & m_pin;
    return m_data;
}
//===============================================
