//===============================================
#ifndef _GConveyor_
#define _GConveyor_
//===============================================
#include "GObject.h"
//===============================================
class GConveyor : public QGraphicsItem {
public:
    explicit GConveyor(QGraphicsItem* _parent = 0);
    ~GConveyor();
    void nextFrame();
    QRectF boundingRect() const;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int mCurrentFrame;
    QPixmap mPixmap;
};
//===============================================
#endif
//===============================================
