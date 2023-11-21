//===============================================
#ifndef _GSmallMario_
#define _GSmallMario_
//===============================================
#include "GObject.h"
//===============================================
class GSmallMario : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    enum eGState {
         Standing = 0,
         StandShoot,
         Walking,
         Jumping,
         Falling
    };

public:
    explicit GSmallMario(QGraphicsItem* _parent = 0);
    ~GSmallMario();
    QRectF boundingRect() const;
    void nextFrame();

protected:
    void paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget);

private:
    int m_direction;
    int mCurrentFrame;
    int m_StandingDirection;
    eGState mState;

    QPixmap mPixmap;
    QPixmap mWalkPixmap;
    QPixmap mStandingPixmap;
    QPixmap mJumpPixmap;
    QPixmap standShootPixmap;
    QPixmap mShrinkPixmap;
};
//===============================================
#endif
//===============================================
