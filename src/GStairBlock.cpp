//===============================================
#include "GStairBlock.h"
//===============================================
GStairBlock::GStairBlock(int _length, QGraphicsItem* _parent)
: QGraphicsItem(_parent)
, mLength(_length)
, mCurrentFrame(0)
, mPixmap(":/img/stairblock.png") {
    setFlag(ItemClipsToShape);
}
//===============================================
GStairBlock::~GStairBlock() {

}
//===============================================
void GStairBlock::nextFrame() {
    mCurrentFrame += 48;
    if (mCurrentFrame >= 768 ) {
        mCurrentFrame = 0;
    }
}
//===============================================
int GStairBlock::type() const {
    return Type;
}
//===============================================
QRectF GStairBlock::boundingRect() const {
    return QRectF(0, 0, 48*mLength, 48);
}
//===============================================
void GStairBlock::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    for(int i = 0; i < mLength; ++i) {
        painter->drawPixmap(i*48, 0, mPixmap, mCurrentFrame, 0, 48, 48);
    }
    setTransformOriginPoint(boundingRect().center());
}
//===============================================
