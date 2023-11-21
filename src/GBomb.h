//===============================================
#ifndef _GBomb_
#define _GBomb_
//===============================================
#include "GObject.h"
//===============================================
class GBomb : public QGraphicsItem {
public:
    enum { Type = UserType + BombType };

public:
    explicit GBomb(QRectF _platformRect, int _direction, QGraphicsItem* _parent = 0);
    ~GBomb();
    QRectF boundingRect() const;
    int type() const;

protected:
    void paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget);

public slots:
    void nextFrame();

private:
    QPixmap m_pixmap;
    int m_currentFrame;
    int m_direction;
    QRectF m_platformRect;
};
//===============================================
#endif
//===============================================
