//===============================================
#include "GGiantGoomba.h"
//===============================================
GGiantGoomba::GGiantGoomba(QGraphicsItem* _parent)
: QGraphicsItem(_parent)
, mCurrentFrame(0)
, mPixmap(":/img/goomba.png") {
    setFlag(ItemClipsToShape);
}
//===============================================
GGiantGoomba::~GGiantGoomba() {

}
//===============================================
void GGiantGoomba::nextFrame() {
    mCurrentFrame += 121;
    if (mCurrentFrame >= 1899 ) {
        mCurrentFrame = 0;
    }
}
//===============================================
int GGiantGoomba::type() const {
    return Type;
}
//===============================================
QRectF GGiantGoomba::boundingRect() const {
    return QRectF(0, 0, 110, 97);
}
//===============================================
void GGiantGoomba::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, mPixmap, mCurrentFrame, 0, 110, 97);
    setTransformOriginPoint(boundingRect().center());
}
//===============================================
