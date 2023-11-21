//===============================================
#ifndef _GAnimation_
#define _GAnimation_
//===============================================
#include "GObject.h"
//===============================================
class GAnimation : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
};
//===============================================
#endif
//===============================================
