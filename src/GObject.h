//===============================================
#ifndef _GObject_
#define _GObject_
//===============================================
#include "GInclude.h"
//===============================================
class GObject {
public:
    explicit GObject();
    ~GObject();
    void updateStyle(QWidget* _widget, const char* _name, const QVariant& _value);
};
//===============================================
#endif
//===============================================
