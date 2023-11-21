//===============================================
#include "GBrick.h"
//===============================================
GBrick::GBrick(int _nbBlocs, QGraphicsItem* _parent)
: QGraphicsItem(_parent)
, m_currentFrame(0)
, m_nbBlocs(_nbBlocs)
, m_pixmap(":/img/brick3.png") {
    setFlag(ItemClipsToShape);
}
//===============================================
GBrick::~GBrick() {

}
//===============================================
void GBrick::nextFrame() {
    m_currentFrame += 48;
    if (m_currentFrame >= 768 ) {
        m_currentFrame = 0;
    }
}
//===============================================
int GBrick::type() const {
  return Type;
}
//===============================================
QRectF GBrick::boundingRect() const {
    return QRectF(0, 0, 48 * m_nbBlocs, 48);
}
//===============================================
void GBrick::paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget) {
    for(int i = 0; i < m_nbBlocs; ++i){
        _painter->drawPixmap(i * 48, 0, m_pixmap, m_currentFrame, 0, 48, 48);
    }
    setTransformOriginPoint(boundingRect().center());
}
//===============================================
