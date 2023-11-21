//===============================================
#include "GCastle.h"
//===============================================
GCastle::GCastle(QGraphicsItem* _parent)
: QGraphicsPixmapItem(_parent) {
    setPixmap(QPixmap(":/img/hcastle.png"));
}
//===============================================
GCastle::~GCastle() {

}
//===============================================
int GCastle::type() const {
    return Type;
}
//===============================================
