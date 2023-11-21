//===============================================
#include "GTimer.h"
//===============================================
GTimer::GTimer(QGraphicsItem* _parent)
: QGraphicsTextItem(_parent)
, timeCount(0) {
    int id = QFontDatabase::addApplicationFont(":font/CoinCount2.ttf");
    QFontDatabase::applicationFontFamilies(id);
    setPlainText(QString("") + QString::number(timeCount));
    setDefaultTextColor(Qt::black);
    setFont(QFont("CoinCount2", 30));
}
//===============================================
GTimer::~GTimer() {

}
//===============================================
void GTimer::increase(){
    timeCount++;
    setPlainText(QString("") + QString::number(timeCount));
}
//===============================================
int GTimer::getCount(){
    return timeCount;
}
//===============================================
