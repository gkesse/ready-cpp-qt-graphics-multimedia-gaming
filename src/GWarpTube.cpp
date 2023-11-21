//===============================================
#include "GWarpTube.h"
//===============================================
GWarpTube::GWarpTube(QGraphicsItem* _parent)
: QGraphicsItem(_parent)
, mCurrentFrame(0)
, mPixmap(":/img/Warp.png") {
    setFlag(ItemClipsToShape);
}
//===============================================
GWarpTube::~GWarpTube() {

}
//===============================================
void GWarpTube::nextFrame() {
    mCurrentFrame += 54;
    if (mCurrentFrame >= 862) {
        mCurrentFrame = 0;
    }
}
//===============================================
int GWarpTube::type() const {
    return Type;
}
//===============================================
QRectF GWarpTube::boundingRect() const {
    return QRectF(0, 0, 70, 100);
}
//===============================================
void GWarpTube::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, mPixmap, mCurrentFrame, 0, 70, 100);
    setTransformOriginPoint(boundingRect().center());
}
//===============================================
