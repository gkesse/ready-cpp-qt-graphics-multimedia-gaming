//===============================================
#include "GFlag.h"
//===============================================
GFlag::GFlag(QGraphicsItem* _parent)
: QGraphicsItem(_parent)
, m_currentFrame(0)
, m_pixmap(":/img/mflag.png") {
    setFlag(ItemClipsToShape);
}
//===============================================
GFlag::~GFlag() {

}
//===============================================
void GFlag::nextFrame() {
    m_currentFrame += 322;
    if (m_currentFrame >= 5439 ) {
        m_currentFrame = 0;
    }
}
//===============================================
int GFlag::type() const {
    return Type;
}
//===============================================
QRectF GFlag::boundingRect() const {
    return QRectF(0, 0, 115, 84);
}
//===============================================
void GFlag::paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget) {
    _painter->drawPixmap(0, 0, m_pixmap, m_currentFrame, 0, 115, 84);
    setTransformOriginPoint(boundingRect().center());
}
//===============================================
