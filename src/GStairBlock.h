//===============================================
#ifndef _GStairBlock_
#define _GStairBlock_
//===============================================
#include "GObject.h"
//===============================================
class GStairBlock : public QGraphicsItem {
public:
    enum { Type = UserType + StairBlockType };

public:
    explicit GStairBlock(int _length, QGraphicsItem* _parent = 0);
    ~GStairBlock();
    void nextFrame();
    QRectF boundingRect() const;
    int type() const;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int mCurrentFrame;
    QPixmap mPixmap;
    int mLength;
};
//===============================================
#endif
//===============================================
