//===============================================
#ifndef _GWall_
#define _GWall_
//===============================================
#include "GObject.h"
//===============================================
class GWall : public QGraphicsItem {
public:
    enum { Type = UserType + WallPlatformType };

public:
    explicit GWall(int _nbBlocs, QGraphicsItem* _parent = 0);
    ~GWall();
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
