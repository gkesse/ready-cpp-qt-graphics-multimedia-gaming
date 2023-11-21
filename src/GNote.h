//===============================================
#ifndef _GNote_
#define _GNote_
//===============================================
#include "GObject.h"
//===============================================
class GNote : public QGraphicsItem {
public:
    enum { Type = UserType + NoteBoxType };

public:
    explicit GNote(int _nbBlocs, QGraphicsItem* _parent = 0);
    ~GNote();
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
