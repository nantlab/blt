#include "inputwidget.h"

inputWidget::inputWidget(QWidget *parent) :
    QTabWidget(parent),
    _audioAnalyzerWidget(new audioAnalyzerWidget(this)),
    _metronomWidget(new metronomWidget(this)),
    _oscInputWidget(new oscInputWidget(this))
{
    addTab(_audioAnalyzerWidget, "audio");
    addTab(_metronomWidget, "metro");
    addTab(_oscInputWidget, "OSC");
}

metronomWidget *inputWidget::getMetronomWidget(){
    return _metronomWidget;
}
