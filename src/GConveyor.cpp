//===============================================
#include "GConveyor.h"
//===============================================
GConveyor::GConveyor(QGraphicsItem* _parent)
: QGraphicsItem(_parent)
, mCurrentFrame(0)
, mPixmap(":/img/conveyorR.png") {
    setFlag(ItemClipsToShape);
}
//===============================================
GConveyor::~GConveyor() {

}
//===============================================
void GConveyor::nextFrame() {
    mCurrentFrame += 141;
    if (mCurrentFrame >= 8180 ) {
        mCurrentFrame = 0;
    }
}
//===============================================
QRectF GConveyor::boundingRect() const {
    return QRectF(0, 0, 190, 56);
}
//===============================================
void GConveyor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, mPixmap, mCurrentFrame, 0, 190, 56);
    setTransformOriginPoint(boundingRect().center());
}
//===============================================
