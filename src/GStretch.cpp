//===============================================
#include "GStretch.h"
//===============================================
GStretch::GStretch(QGraphicsItem* _parent)
: QGraphicsItem(_parent)
, mCurrentFrame(0)
, mPixmap(":/img/ustretch.png") {
    setFlag(ItemClipsToShape);
}
//===============================================
GStretch::~GStretch() {

}
//===============================================
void GStretch::nextFrame() {
    mCurrentFrame += 141;
    if (mCurrentFrame >= 8180 ) {
        mCurrentFrame = 0;

    }
}
//===============================================
int GStretch::type() const {
  return Type;
}
//===============================================
QRectF GStretch::boundingRect() const {
    return QRectF(0, 0, 135, 112);
}
//===============================================
void GStretch::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0,0, mPixmap, mCurrentFrame, 0, 135, 112);
    setTransformOriginPoint(boundingRect().center());
}
//===============================================
