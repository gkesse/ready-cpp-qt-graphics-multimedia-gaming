//===============================================
#include "GCoin.h"
//===============================================
GCoin::GCoin(QGraphicsItem* _parent)
: QGraphicsItem(_parent)
, mCurrentFrame(0)
, mPixmap(":/img/coin.png") {
    setFlag(ItemClipsToShape);
}
//===============================================
GCoin::~GCoin() {

}
//===============================================
void GCoin::nextFrame() {
    mCurrentFrame += 38;
    if(mCurrentFrame >= 300) {
        mCurrentFrame = 0;
    }
}
//===============================================
int GCoin::type() const {
  return Type;
}
//===============================================
QRectF GCoin::boundingRect() const {
    return QRectF(0, 0, 39, 41);
}
//===============================================
void GCoin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0,0, mPixmap, mCurrentFrame, 0,39, 41);
    setTransformOriginPoint(boundingRect().center());
}
//===============================================
