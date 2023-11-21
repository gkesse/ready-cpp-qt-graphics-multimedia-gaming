//===============================================
#include "GWall.h"
//===============================================
GWall::GWall(int _nbBlocs, QGraphicsItem* _parent)
: QGraphicsItem(_parent)
, m_currentFrame(0)
, m_nbBlocs(_nbBlocs)
, m_pixmap(":/img/wallplatform.png") {
    setFlag(ItemClipsToShape);
}
//===============================================
GWall::~GWall() {

}
//===============================================
void GWall::nextFrame() {
    m_currentFrame += 48;
    if(m_currentFrame >= 768 ) {
        m_currentFrame = 0;
    }
}
//===============================================
int GWall::type() const {
  return Type;
}
//===============================================
QRectF GWall::boundingRect() const {
    return QRectF(0, 0, 48 * m_nbBlocs, 48);
}
//===============================================
void GWall::paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget) {
    for(int i = 0; i < m_nbBlocs; ++i){
        _painter->drawPixmap(i * 48, 0, m_pixmap, m_currentFrame, 0, 48, 48);
    }
    setTransformOriginPoint(boundingRect().center());
}
//===============================================
