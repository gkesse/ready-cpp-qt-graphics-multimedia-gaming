//===============================================
#include "GRedTurtle.h"
//===============================================
GRedTurtle::GRedTurtle(QRectF _platformRect, int _direction, QGraphicsItem* _parent)
: QGraphicsItem(_parent)
, m_platformRect(_platformRect)
, m_direction(-1)
, m_currentFrame(0)
, m_pixmap(":/img/redt.png") {
    setFlag(ItemClipsToShape);
}
//===============================================
GRedTurtle::~GRedTurtle() {

}
//===============================================
void GRedTurtle::nextFrame() {
    m_currentFrame += 179;
    if (m_currentFrame >= 3521 ) {
        m_currentFrame = 0;
    }

    if(pos().x() < m_platformRect.x() || pos().x() > m_platformRect.x()+ m_platformRect.width()) {
        m_direction = -m_direction;
        setTransform(QTransform(-m_direction, 0, 0, 1, boundingRect().width(), 0));
    }

    setPos(pos().x() + (m_direction*7), pos().y());
}
//===============================================
int GRedTurtle::type() const {
    return Type;
}
//===============================================
QRectF GRedTurtle::boundingRect() const {
    return QRectF(0, 0, 130, 146);
}
//===============================================
void GRedTurtle::paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget) {
    _painter->drawPixmap(0, 0, m_pixmap, m_currentFrame, 0, 130, 146);
    setTransformOriginPoint(boundingRect().center());
}
//===============================================
