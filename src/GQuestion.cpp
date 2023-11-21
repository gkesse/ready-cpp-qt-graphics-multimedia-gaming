//===============================================
#include "GQuestion.h"
//===============================================
GQuestion::GQuestion(int _nbBlocs, QGraphicsItem* _parent)
: QGraphicsItem(_parent)
, m_currentFrame(0)
, m_nbBlocs(_nbBlocs)
, m_pixmap(":/img/questbox.png") {
    setFlag(ItemClipsToShape);
}
//===============================================
GQuestion::~GQuestion() {

}
//===============================================
void GQuestion::nextFrame() {
    m_currentFrame += 50;
    if (m_currentFrame >= 800 ) {
        m_currentFrame = 0;
    }
}
//===============================================
int GQuestion::type() const {
  return Type;
}
//===============================================
QRectF GQuestion::boundingRect() const {
    return QRectF(0, 0, 48 * m_nbBlocs, 48);
}
//===============================================
void GQuestion::paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget) {
    for(int i = 0; i < m_nbBlocs; ++i){
        _painter->drawPixmap(i * 48, 0, m_pixmap, m_currentFrame, 0, 48, 48);
    }
    setTransformOriginPoint(boundingRect().center());
}
//===============================================
