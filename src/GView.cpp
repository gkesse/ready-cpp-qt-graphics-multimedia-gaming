//===============================================
#include "GView.h"
//===============================================
GView::GView(QWidget* _parent)
: QGraphicsView(_parent) {
    m_bgm = new QMediaPlaylist;
    setFixedSize(QSize(1280, 720));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
//===============================================
GView::~GView() {

}
//===============================================
