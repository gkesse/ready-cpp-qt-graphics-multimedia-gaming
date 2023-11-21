//===============================================
#include "GSpiny.h"
//===============================================
GSpiny::GSpiny(QRectF _platformRect, int _direction, QGraphicsItem* _parent)
: QGraphicsItem(_parent)
, m_platformRect(_platformRect)
, m_direction(-1)
, m_currentFrame(0)
, m_pixmap(":/img/spiny.png") {
    setFlag(ItemClipsToShape);
}
//===============================================
GSpiny::~GSpiny() {

}
//===============================================
void GSpiny::nextFrame() {
    m_currentFrame += 238;
    if (m_currentFrame >= 3569 ) {
        m_currentFrame = 0;
    }

    if(pos().x() < m_platformRect.x() || pos().x() > m_platformRect.x()+ m_platformRect.width()) {
        m_direction = -m_direction;
        setTransform(QTransform(-m_direction, 0, 0, 1, boundingRect().width(), 0));
    }

    setPos(pos().x() + (m_direction*7), pos().y());
}
//===============================================
int GSpiny::type() const {
    return Type;
}
//===============================================
QRectF GSpiny::boundingRect() const {
    return QRectF(0, 0, 120, 93);
}
//===============================================
void GSpiny::paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget) {
    _painter->drawPixmap(0, 0, m_pixmap, m_currentFrame, 0, 120, 93);
    setTransformOriginPoint(boundingRect().center());
}
//===============================================
