//===============================================
#ifndef _GCoin_
#define _GCoin_
//===============================================
#include "GObject.h"
//===============================================
class GCoin : public QGraphicsItem {
public:
    enum { Type = UserType + CoinType };

public:
    explicit GCoin(QGraphicsItem* _parent = 0);
    ~GCoin();
    void nextFrame();
    int type() const;
    QRectF boundingRect() const;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int mCurrentFrame;
    QPixmap mPixmap;
};
//===============================================
#endif
//===============================================
