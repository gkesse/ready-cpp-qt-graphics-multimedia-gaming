//===============================================
#include "GPiranha.h"
//===============================================
GPiranha::GPiranha(QGraphicsItem* _parent)
: QGraphicsItem(_parent)
, m_currentFrame(0)
, m_pixmap(":/img/piranha.png") {
    setFlag(ItemClipsToShape);
}
//===============================================
GPiranha::~GPiranha() {

}
//===============================================
void GPiranha::nextFrame() {
    m_currentFrame += 387;
    if (m_currentFrame >= 9286 ) {
        m_currentFrame = 0;
    }
}
//===============================================
int GPiranha::type() const {
    return Type;
}
//===============================================
QRectF GPiranha::boundingRect() const {
    return QRectF(0, 0, 130, 165);
}
//===============================================
void GPiranha::paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget) {
    _painter->drawPixmap(0, 0, m_pixmap, m_currentFrame, 0, 130, 165);
    setTransformOriginPoint(boundingRect().center());
}
//===============================================
