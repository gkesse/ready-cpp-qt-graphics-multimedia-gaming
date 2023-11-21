//===============================================
#include "GNote.h"
//===============================================
GNote::GNote(int _nbBlocs, QGraphicsItem* _parent)
: QGraphicsItem(_parent)
, m_currentFrame(0)
, m_nbBlocs(_nbBlocs)
, m_pixmap(":/img/notebox.png") {
    setFlag(ItemClipsToShape);
}
//===============================================
GNote::~GNote() {

}
//===============================================
void GNote::nextFrame() {
    m_currentFrame += 65;
    if(m_currentFrame >= 518 ) {
        m_currentFrame = 0;
    }
}
//===============================================
int GNote::type() const {
  return Type;
}
//===============================================
QRectF GNote::boundingRect() const {
    return QRectF(0, 0, 63 * m_nbBlocs, 63);
}
//===============================================
void GNote::paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget) {
    for(int i = 0; i < m_nbBlocs; ++i){
        _painter->drawPixmap(i * 63, 0, m_pixmap, m_currentFrame, 0, 63, 63);
    }
    setTransformOriginPoint(boundingRect().center());
}
//===============================================
