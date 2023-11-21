//===============================================
#ifndef _GFlower_
#define _GFlower_
//===============================================
#include "GObject.h"
//===============================================
class GFlower : public QGraphicsItem {
public:
    enum { Type = UserType + FlowerQuestBoxType };

public:
    explicit GFlower(int _nbBlocs, QGraphicsItem* _parent = 0);
    ~GFlower();
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
