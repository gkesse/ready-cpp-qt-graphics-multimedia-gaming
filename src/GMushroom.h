//===============================================
#ifndef _GMushroom_
#define _GMushroom_
//===============================================
#include "GObject.h"
//===============================================
class GMushroom : public QGraphicsItem {
public:
    enum { Type = UserType + MushroomQuestBoxType };

public:
    explicit GMushroom(int _nbBlocs, QGraphicsItem* _parent = 0);
    ~GMushroom();
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
