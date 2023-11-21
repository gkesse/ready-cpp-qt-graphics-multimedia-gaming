//===============================================
#ifndef _GTimer_
#define _GTimer_
//===============================================
#include "GObject.h"
//===============================================
class GTimer : public QGraphicsTextItem {
public:
    explicit GTimer(QGraphicsItem* _parent = 0);
    ~GTimer();
    void increase();
    int getCount();

private:
    int timeCount;
};
//===============================================
#endif
//===============================================
