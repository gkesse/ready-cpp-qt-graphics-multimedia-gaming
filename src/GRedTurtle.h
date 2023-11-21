//===============================================
#ifndef _GRedTurtle_
#define _GRedTurtle_
//===============================================
#include "GObject.h"
//===============================================
class GRedTurtle : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    enum { Type = UserType + RedTurtleType };

public:
    explicit GRedTurtle(QRectF _platformRect, int _direction, QGraphicsItem* _parent = 0);
    ~GRedTurtle();
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
