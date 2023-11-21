//===============================================
#ifndef _GFlag_
#define _GFlag_
//===============================================
#include "GObject.h"
//===============================================
class GFlag : public QGraphicsItem {
public:
    enum { Type = UserType + FlagType };

public:
    explicit GFlag(QGraphicsItem* _parent = 0);
    ~GFlag();
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
