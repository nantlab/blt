#include "metronomwidget.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

metronomWidget::metronomWidget(QWidget *parent) :
    QWidget(parent),
    _startButton(new QToolButton()),
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
    mainLayout->addWidget(_startButton);
    mainLayout->addWidget(timeSlider);
    mainLayout->addWidget(_timeLabel);

    _timer->setInterval(500);
    connect(_timer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
    connect(timeSlider, SIGNAL(valueChanged(int)), this, SLOT(onIntervalChanged(int)));
    connect(_onState, SIGNAL(entered()), this, SLOT(start()));
    connect(_offState, SIGNAL(entered()), this, SLOT(stop()));

    _onState->addTransition(_startButton, SIGNAL(clicked(bool)), _offState);
    _offState->addTransition(_startButton, SIGNAL(clicked(bool)), _onState);
    _stateMachine->addState(_onState);
    _stateMachine->addState(_offState);
    _stateMachine->setInitialState(_offState);
    _stateMachine->start();

}

QTimer *metronomWidget::getTimer(){
    return _timer;
}

void metronomWidget::start(){
    _startButton->setIcon(QIcon(":icons/font-awesome_4-7-0_pause_256_0_d35400_none.png"));
    _timer->start();
    emit started();
}

void metronomWidget::stop(){
    _startButton->setIcon(QIcon(":icons/font-awesome_4-7-0_play_256_0_d35400_none.png"));
    _timer->stop();
}

void metronomWidget::onTimeOut(){
    qDebug()<<"metro tick";
    emit tick();
}

void metronomWidget::onIntervalChanged(int value)
{
    _timer->setInterval(value);
    _timeLabel->setText(QString::number(value)+" ms");
}
