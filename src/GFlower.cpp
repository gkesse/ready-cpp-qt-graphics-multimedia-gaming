//===============================================
#include "GFlower.h"
//===============================================
GFlower::GFlower(int _nbBlocs, QGraphicsItem* _parent)
: QGraphicsItem(_parent)
, m_currentFrame(0)
, m_nbBlocs(_nbBlocs)
, m_pixmap(":/img/questbox.png") {
    setFlag(ItemClipsToShape);
}
//===============================================
GFlower::~GFlower() {

}
//===============================================
void GFlower::nextFrame() {
    m_currentFrame += 50;
    if (m_currentFrame >= 800 ) {
        m_currentFrame = 0;
    }
}
//===============================================
int GFlower::type() const {
  return Type;
}
//===============================================
QRectF GFlower::boundingRect() const {
    return QRectF(0, 0, 48 * m_nbBlocs, 48);
}
//===============================================
void GFlower::paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget) {
    for(int i = 0; i < m_nbBlocs; ++i){
        _painter->drawPixmap(i * 48, 0, m_pixmap, m_currentFrame, 0, 48, 48);
    }
    setTransformOriginPoint(boundingRect().center());
}
//===============================================
