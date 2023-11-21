//===============================================
#include "GSmallMario.h"
//===============================================
GSmallMario::GSmallMario(QGraphicsItem* _parent)
: QGraphicsItem(_parent)
, m_direction(0)
, mCurrentFrame()
, m_StandingDirection()
, mState(Standing) {
    setFlag(ItemClipsToShape);

    mWalkPixmap = QPixmap(":/img/shrink.png");
    mStandingPixmap = QPixmap(":/img/smallMarioStop.png");
    mJumpPixmap = QPixmap(":/img/mario_jump.png");
    standShootPixmap = QPixmap(":/img/smallMarioStop.png");
    mShrinkPixmap = QPixmap(":/img/shrink.png");
    mPixmap = mWalkPixmap;
}
//===============================================
GSmallMario::~GSmallMario() {

}
//===============================================
void GSmallMario::nextFrame() {
    mCurrentFrame += 57;
    if (mCurrentFrame >= 1191 ) {
        mCurrentFrame = 0;
    }
}
//===============================================
QRectF GSmallMario::boundingRect() const {
    return QRectF(0, 0, 45, 45);
}
//===============================================
void GSmallMario::paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget) {
    _painter->drawPixmap(0, 0, mPixmap, mCurrentFrame, 0, 45, 45);
    setTransformOriginPoint(boundingRect().center());
}
//===============================================
