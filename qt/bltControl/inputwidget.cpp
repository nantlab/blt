#include "inputwidget.h"
#include <qdebug.h>

inputWidget::inputWidget(QWidget *parent) :
    QTabWidget(parent),
    _audioAnalyzerWidget(new audioAnalyzerWidget(this)),
    _metronomWidget(new metronomWidget(this)),
    _oscInputWidget(new oscInputWidget(this))
{
    addTab(_audioAnalyzerWidget, "audio");
    addTab(_metronomWidget, "metro");
    addTab(_oscInputWidget, "OSC");


    connect(_metronomWidget, SIGNAL(tick()), this, SLOT(onTick()));
    connect(_oscInputWidget, SIGNAL(tick()), this, SLOT(onTick()));
    connect(_metronomWidget, SIGNAL(started()), this, SLOT(onMetronomStarted()));
    connect(_oscInputWidget, SIGNAL(started()), this, SLOT(onOscInputStarted()));
}

metronomWidget *inputWidget::getMetronomWidget(){
    return _metronomWidget;
}
oscInputWidget *inputWidget::getOscInputWidget(){
    return _oscInputWidget;
}

void inputWidget::onTick()
{
    qDebug()<<"inputWidget"<<"tick";
    emit tick();
}

void inputWidget::onMetronomStarted()
{
    _oscInputWidget->stop();
}

void inputWidget::onOscInputStarted()
{
    _metronomWidget->stop();
}
