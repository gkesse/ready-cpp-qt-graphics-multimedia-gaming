//===============================================
#include "GGoomba.h"
//===============================================
GGoomba::GGoomba(QRectF _platformRect, int _direction, QGraphicsItem* _parent)
: QGraphicsItem(_parent)
, m_platformRect(_platformRect)
, m_direction(-1)
, m_currentFrame(0)
, m_pixmap(":/img/goombas.png") {
    setFlag(ItemClipsToShape);

    QTimer *lTimer = new QTimer(this);
    connect(lTimer, &QTimer::timeout, this, &GGoomba::nextFrame);
    lTimer->start(100);
}
//===============================================
GGoomba::~GGoomba() {

}
//===============================================
void GGoomba::nextFrame() {
    m_currentFrame += 54;
    if (m_currentFrame >= 862) {
        m_currentFrame = 0;
    }

    if(pos().x() < m_platformRect.x() || pos().x() > m_platformRect.x() + m_platformRect.width()) {
        m_direction = -m_direction;
        setTransform(QTransform(-m_direction, 0, 0, 1, boundingRect().width(), 0));
    }

    setPos(pos().x() + (m_direction*7), pos().y());
}
//===============================================
int GGoomba::type() const {
    return Type;
}
//===============================================
QRectF GGoomba::boundingRect() const {
    return QRectF(0, 0, 52, 50);
}
//===============================================
void GGoomba::paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget) {
    _painter->drawPixmap(0, 0, m_pixmap, m_currentFrame, 0, 52, 50);
    setTransformOriginPoint(boundingRect().center());
}
//===============================================
