//===============================================
#ifndef _GStretch_
#define _GStretch_
//===============================================
#include "GObject.h"
//===============================================
class GStretch : public QGraphicsItem {
public:
    enum { Type = UserType + StretchType };

public:
    explicit GStretch(QGraphicsItem* _parent = 0);
    ~GStretch();
    void nextFrame();
    int type() const;
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
