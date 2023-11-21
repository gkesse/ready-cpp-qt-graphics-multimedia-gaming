//===============================================
#include "GBackground.h"
//===============================================
GBackground::GBackground(const QPixmap& _pixmap, QGraphicsItem* _parent)
: QGraphicsPixmapItem(_pixmap, _parent) {

}
//===============================================
GBackground::~GBackground() {

}
//===============================================
QPainterPath GBackground::shape() const {
    return QPainterPath();
}
//===============================================
