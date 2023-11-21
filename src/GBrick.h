//===============================================
#ifndef _GBrick_
#define _GBrick_
//===============================================
#include "GObject.h"
//===============================================
class GBrick : public QGraphicsItem {
public:
    enum { Type = UserType + BrickPlatformType };

public:
    explicit GBrick(int _nbBlocs, QGraphicsItem* _parent = 0);
    ~GBrick();
    void nextFrame();
    int type() const;
    QRectF boundingRect() const;

protected:
    void paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget);

private:
    QPixmap m_pixmap;
    int m_currentFrame;
    int m_nbBlocs;
};
//===============================================
#endif
//===============================================
