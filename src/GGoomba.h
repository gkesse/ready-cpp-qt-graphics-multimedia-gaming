//===============================================
#ifndef _GGoomba_
#define _GGoomba_
//===============================================
#include "GObject.h"
//===============================================
class GGoomba : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    enum { Type = UserType + GoombaType };

public:
    explicit GGoomba(QRectF _platformRect, int _direction, QGraphicsItem* _parent = 0);
    ~GGoomba();
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
