#include "inputwidget.h"
#include <qdebug.h>

inputWidget::inputWidget(QWidget *parent) :
    QTabWidget(parent),
    _audioInputWidget(new audioInputWidget(this)),
    _metronomWidget(new metronomWidget(this)),
    _oscInputWidget(new oscInputWidget(this))
{
    addTab(_audioInputWidget, "audio");
    addTab(_metronomWidget, "metro");
    addTab(_oscInputWidget, "OSC");


    connect(_audioInputWidget, SIGNAL(tick()), this, SLOT(onTick()));
    connect(_metronomWidget, SIGNAL(tick()), this, SLOT(onTick()));
    connect(_oscInputWidget, SIGNAL(tick()), this, SLOT(onTick()));
    connect(_audioInputWidget, SIGNAL(started()), this, SLOT(onAudioInputStarted()));
    connect(_metronomWidget, SIGNAL(started()), this, SLOT(onMetronomStarted()));
    connect(_oscInputWidget, SIGNAL(started()), this, SLOT(onOscInputStarted()));
}

audioInputWidget *inputWidget::getAudioInputWidget(){
    return _audioInputWidget;
}

metronomWidget *inputWidget::getMetronomWidget(){
    return _metronomWidget;
}
oscInputWidget *inputWidget::getOscInputWidget(){
    return _oscInputWidget;
}

void inputWidget::onTick()
{
    emit tick();
}

void inputWidget::onAudioInputStarted()
{
    _metronomWidget->stop();
    _oscInputWidget->stop();
}
void inputWidget::onMetronomStarted()
{
    _audioInputWidget->stop();
    _oscInputWidget->stop();
}

void inputWidget::onOscInputStarted()
{
    _audioInputWidget->stop();
    _metronomWidget->stop();
}
