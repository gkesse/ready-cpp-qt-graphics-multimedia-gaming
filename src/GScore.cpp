//===============================================
#include "GScore.h"
//===============================================
GScore::GScore(QGraphicsItem* _parent)
: QGraphicsTextItem(_parent)
, scoreCount(0) {
    int id = QFontDatabase::addApplicationFont(":font/CoinCount2.ttf");
    QFontDatabase::applicationFontFamilies(id);
    setPlainText(QString("") + QString::number(scoreCount));
    setDefaultTextColor(Qt::black);
    setFont(QFont("CoinCount2", 30));
}
//===============================================
GScore::~GScore() {

}
//===============================================
void GScore::increase(){
    scoreCount++;
    setPlainText(QString("") + QString::number(scoreCount));
}
//===============================================
int GScore::getCount(){
    return scoreCount;
}
//===============================================
