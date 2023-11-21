//===============================================
#ifndef _GCounter_
#define _GCounter_
//===============================================
#include "GObject.h"
//===============================================
class GCounter : public QGraphicsTextItem {
public:
    explicit GCounter(QGraphicsItem* _parent = 0);
    ~GCounter();
    void increase();
    int getCount();

private:
    int coinCount;
};
//===============================================
#endif
//===============================================
