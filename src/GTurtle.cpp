//===============================================
#include "GTurtle.h"
//===============================================
GTurtle::GTurtle(QRectF _platformRect, int _direction, QGraphicsItem* _parent)
: QGraphicsItem(_parent)
, m_platformRect(_platformRect)
, m_direction(-1)
, m_currentFrame(0)
, m_pixmap(":/img/turtle.png") {
    setFlag(ItemClipsToShape);
}
//===============================================
GTurtle::~GTurtle() {

}
//===============================================
void GTurtle::nextFrame() {
    m_currentFrame += 72;
    if (m_currentFrame >= 1420 ) {
        m_currentFrame = 0;
    }

    if(pos().x() < m_platformRect.x() || pos().x() > m_platformRect.x()+ m_platformRect.width()) {
        m_direction = -m_direction;
        setTransform(QTransform(-m_direction, 0, 0, 1, boundingRect().width(), 0));
    }
    setPos(pos().x() + (m_direction*7), pos().y());

}
//===============================================
int GTurtle::type() const {
    return Type;
}
//===============================================
QRectF GTurtle::boundingRect() const {
    return QRectF(0, 0, 68, 60);
}
//===============================================
void GTurtle::paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget) {
    _painter->drawPixmap(0, 0, m_pixmap, m_currentFrame, 0, 68, 60);
    setTransformOriginPoint(boundingRect().center());
}
//===============================================
