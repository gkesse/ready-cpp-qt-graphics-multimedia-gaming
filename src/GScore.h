//===============================================
#ifndef _GScore_
#define _GScore_
//===============================================
#include "GObject.h"
//===============================================
class GScore : public QGraphicsTextItem {
public:
    explicit GScore(QGraphicsItem* _parent = 0);
    ~GScore();
    void increase();
    int getCount();

private:
    int scoreCount;
};
//===============================================
#endif
//===============================================
