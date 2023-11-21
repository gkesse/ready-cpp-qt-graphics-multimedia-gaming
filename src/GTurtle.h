//===============================================
#ifndef _GTurtle_
#define _GTurtle_
//===============================================
#include "GObject.h"
//===============================================
class GTurtle : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    enum { Type = UserType + TurtleType };

public:
    explicit GTurtle(QRectF _platformRect, int _direction, QGraphicsItem* _parent = 0);
    ~GTurtle();
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
