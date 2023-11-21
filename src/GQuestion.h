//===============================================
#ifndef _GQuestion_
#define _GQuestion_
//===============================================
#include "GObject.h"
//===============================================
class GQuestion : public QGraphicsItem {
public:
    enum { Type = UserType + QuestBoxType };

public:
    explicit GQuestion(int _nbBlocs, QGraphicsItem* _parent = 0);
    ~GQuestion();
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
