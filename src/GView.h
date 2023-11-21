//===============================================
#ifndef _GView_
#define _GView_
//===============================================
#include "GObject.h"
//===============================================
class GView : public QGraphicsView {
    Q_OBJECT

public:
    explicit GView(QWidget* _parent = 0);
    ~GView();

private:
    QMediaPlaylist* m_bgm;
};
//===============================================
#endif
//===============================================
