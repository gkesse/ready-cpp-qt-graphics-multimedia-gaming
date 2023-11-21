//===============================================
#ifndef _GCastle_
#define _GCastle_
//===============================================
#include "GObject.h"
//===============================================
class GCastle : public QGraphicsPixmapItem {
public:
    enum { Type = UserType + CastleType };

public:
    explicit GCastle(QGraphicsItem* _parent = 0);
    ~GCastle();
    int type() const;
};
//===============================================
#endif
//===============================================
