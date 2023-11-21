//===============================================
#ifndef _GSpiny_
#define _GSpiny_
//===============================================
#include "GObject.h"
//===============================================
class GSpiny : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    enum { Type = UserType + SpinyType };

public:
    explicit GSpiny(QRectF _platformRect, int _direction, QGraphicsItem* _parent = 0);
    ~GSpiny();
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
