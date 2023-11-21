//===============================================
#include "GCounter.h"
//===============================================
GCounter::GCounter(QGraphicsItem* _parent)
: QGraphicsTextItem(_parent)
, coinCount(0) {
    int id = QFontDatabase::addApplicationFont(":/font/CoinCount2.ttf");
    QFontDatabase::applicationFontFamilies(id);
    setPlainText(QString("") + QString::number(coinCount));
    setDefaultTextColor(Qt::black);
    setFont(QFont("CoinCount2", 40));
}
//===============================================
GCounter::~GCounter() {

}
//===============================================
void GCounter::increase(){
    coinCount++;
    setPlainText(QString("") + QString::number(coinCount));
}
//===============================================
int GCounter::getCount(){
    return coinCount;
}
//===============================================
