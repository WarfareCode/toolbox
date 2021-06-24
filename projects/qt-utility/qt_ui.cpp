
/*******************************************************************************
** Toolbox-qt-utility                                                         **
** MIT License                                                                **
** Copyright (c) [2018] [Florian Lance]                                       **
**                                                                            **
** Permission is hereby granted, free of charge, to any person obtaining a    **
** copy of this software and associated documentation files (the "Software"), **
** to deal in the Software without restriction, including without limitation  **
** the rights to use, copy, modify, merge, publish, distribute, sublicense,   **
** and/or sell copies of the Software, and to permit persons to whom the      **
** Software is furnished to do so, subject to the following conditions:       **
**                                                                            **
** The above copyright notice and this permission notice shall be included in **
** all copies or substantial portions of the Software.                        **
**                                                                            **
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR **
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   **
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    **
** THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER **
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING    **
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER        **
** DEALINGS IN THE SOFTWARE.                                                  **
**                                                                            **
********************************************************************************/

#include "qt_ui.hpp"

using namespace tool;
using namespace tool::ui;

void style::generate_tab_widget_style(QTabWidget *tab, QString id, int widthBorder, QTabWidget::TabPosition position){

    Q_UNUSED(position)
    QString tabWidgetObjectName = id;
    QString tabBarObjectName = id + "_bar";

    tab->setObjectName(tabWidgetObjectName);
    tab->tabBar()->setObjectName(tabBarObjectName);

    QString lB = QString::number(widthBorder);

    QString style =
    "QTabWidget::tab-bar#"+ tabWidgetObjectName +
    "{"
    "   alignment: left;"
    "}"
    "QTabWidget::pane#"+ tabWidgetObjectName +
    "{"
    "   border: "+lB+"px solid rgb(0,0,0);"
    "   border-radius: 0px;"
    "   border-top-left-radius: 0px;"
    "}"
    "QTabBar::tab#"+ tabBarObjectName +
    "{"
    "   background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde);"
    "   border: "+lB+"px solid rgb(0,0,0);"
    "   border-right: 0px;"
    "   border-radius: 0px;"
    "   min-width:30px;"
    "   padding: 2px;"
    "}"
    "QTabBar::tab#"+ tabBarObjectName + ":selected"
    "{"
    "   color : rgb(0,106,255);"
    "   font: bold 11pt Calibri;"
    "   background-color:  rgb(220,220,220);"
    "}"
    "QTabBar::tab#"+ tabBarObjectName + ":!selected"
    "{"
    "   color : rgb(127,180,255);"
    "   font: bold 11pt Calibri;"
    "   background-color:  rgb(220,220,220);"
    "   background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde);"
    "}"
    "QTabBar::tab#" + tabBarObjectName + ":hover"
    "{"
    "   color : rgb(0,106,255);"
    "   font: bold 11pt Calibri;"
    "   background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);"
    "}"
    "QTabBar::tab#" + tabBarObjectName + ":first"
    "{"
    "   border: "+lB+"px solid rgb(0,0,0);"
    "   border-right: 0px;"
    "   border-bottom: 0px;"
    "   min-height:200px;"
    "}"
    "QTabBar::tab#" + tabBarObjectName + ":last"
    "{"
    "   border: "+lB+"px solid rgb(0,0,0);"
    "   border-right: 0px;"
    "   border-top: 4px solid rgb(0,0,0);"
    "   min-height:150px;"
    "}";

    tab->setStyleSheet(style);
}


QDoubleSpinBox *W::init(QDoubleSpinBox *dsb, MinV<qreal> min, V<qreal> value, MaxV<qreal> max, StepV<qreal> singleStep, int decimals, bool enabled){
    dsb->blockSignals(true);
    dsb->setDecimals(decimals);
    dsb->setMinimum(min.v);
    dsb->setMaximum(max.v);
    dsb->setValue(value.v);
    dsb->setSingleStep(singleStep.v);
    dsb->setEnabled(enabled);
    dsb->blockSignals(false);
    return dsb;
}
