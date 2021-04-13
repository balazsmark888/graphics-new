#ifndef sidewidget_H
#define sidewidget_H

#include <QWidget>
#include "ui_SideWidget.h"

namespace cagd
{
    class SideWidget: public QWidget, public Ui::SideWidget
    {
    public:
        // special and default constructor
        SideWidget(QWidget *parent = 0);
    };
}
#endif
