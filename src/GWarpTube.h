//===============================================
#ifndef _GWarpTube_
#define _GWarpTube_
//===============================================
#include "GObject.h"
//===============================================
class GWarpTube : public QGraphicsItem {
public:
    enum { Type = UserType + WarpTubeType };

public:
    explicit GWarpTube(QGraphicsItem* _parent = 0);
    ~GWarpTube();
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
