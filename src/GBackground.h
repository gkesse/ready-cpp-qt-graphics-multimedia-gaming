//===============================================
#ifndef _GBackground_
#define _GBackground_
//===============================================
#include "GObject.h"
//===============================================
class GBackground : public QGraphicsPixmapItem {
public:
    explicit GBackground(const QPixmap& _pixmap, QGraphicsItem* _parent = 0);
    ~GBackground();

public:
    QPainterPath shape() const;
};
//===============================================
#endif
//===============================================
