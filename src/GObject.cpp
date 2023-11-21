//===============================================
#include "GObject.h"
//===============================================
GObject::GObject() {

}
//===============================================
GObject::~GObject() {

}
//===============================================
void GObject::updateStyle(QWidget* _widget, const char* _name, const QVariant& _value) {
    _widget->setProperty(_name, _value);
    _widget->style()->unpolish(_widget);
    _widget->style()->polish(_widget);
    _widget->update();
}
//===============================================
