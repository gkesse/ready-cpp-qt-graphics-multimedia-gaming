//===============================================
#ifndef _GGiantGoomba_
#define _GGiantGoomba_
//===============================================
#include "GObject.h"
//===============================================
class GGiantGoomba : public QGraphicsItem {
public:
    enum { Type = UserType + GiantGoombaType };

public:
    explicit GGiantGoomba(QGraphicsItem* _parent = 0);
    ~GGiantGoomba();
    void nextFrame();
    QRectF boundingRect() const;
    int type() const;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int mCurrentFrame;
    QPixmap mPixmap;
};
//===============================================
#endif
//===============================================
