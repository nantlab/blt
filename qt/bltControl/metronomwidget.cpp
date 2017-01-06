#include "metronomwidget.h"
#include <QHBoxLayout>
#include <QToolButton>
#include <QSlider>
#include <QSpinBox>

metronomWidget::metronomWidget(QWidget *parent) :
    QWidget(parent),
    _timer(new QTimer(this)),
    _timeLabel(new QLabel(QString::number(500))),
    _stateMachine(new QStateMachine(this)),
    _onState(new QState()),
    _offState(new QState())
{
    auto mainLayout = new QHBoxLayout(this);
    auto timeSlider = new QSlider(this);
    timeSlider->setRange(100, 10000);
    timeSlider->setValue(500);
    timeSlider->setOrientation(Qt::Horizontal);
    auto startButton = new QToolButton();
    mainLayout->addWidget(startButton);
    mainLayout->addWidget(timeSlider);
    mainLayout->addWidget(_timeLabel);

    _timer->setInterval(500);

    connect(timeSlider, SIGNAL(valueChanged(int)), this, SLOT(onIntervalChanged(int)));
    connect(_onState, SIGNAL(entered()), this, SLOT(onStarted()));
    connect(_offState, SIGNAL(entered()), this, SLOT(onStopped()));

    _onState->addTransition(startButton, SIGNAL(clicked(bool)), _offState);
    _offState->addTransition(startButton, SIGNAL(clicked(bool)), _onState);
    _stateMachine->addState(_onState);
    _stateMachine->addState(_offState);
    _stateMachine->setInitialState(_offState);
    _stateMachine->start();

}

QTimer *metronomWidget::getTimer(){
    return _timer;
}

void metronomWidget::onStarted(){
    _timer->start();
}

void metronomWidget::onStopped(){
    _timer->stop();
}

void metronomWidget::onIntervalChanged(int value)
{
    _timer->setInterval(value);
    _timeLabel->setText(QString::number(value)+" ms");
}
