//===============================================
#ifndef _GPiranha_
#define _GPiranha_
//===============================================
#include "GObject.h"
//===============================================
class GPiranha : public QGraphicsItem {
public:
    enum { Type = UserType + PiranhaType };

public:
    explicit GPiranha(QGraphicsItem* _parent = 0);
    ~GPiranha();
    QRectF boundingRect() const;
    int type() const;

protected:
    void paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget);

public slots:
    void nextFrame();

private:
    QPixmap m_pixmap;
    int m_currentFrame;
};
//===============================================
#endif
//===============================================
