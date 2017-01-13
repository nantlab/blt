#include "audioanalyzerwidget.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>

audioInputWidget::audioInputWidget(QWidget *parent) :
    QWidget(parent),
    _receiver(new QOSCReceiver(8001, this)),
    _stateMachine(new QStateMachine(this)),
    _onState(new QState()),
    _offState(new QState()),
    _startButton(new QToolButton()),
    _port(8001)
{
    auto mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(_startButton);

    connect(_receiver, SIGNAL(messageReceived(QOSCMessage*)), this, SLOT(onOscMessage(QOSCMessage*)));
    _receiver->start();

    connect(_onState, SIGNAL(entered()), this, SLOT(start()));
    connect(_offState, SIGNAL(entered()), this, SLOT(stop()));

    _onState->addTransition(_startButton, SIGNAL(clicked(bool)), _offState);
    _offState->addTransition(_startButton, SIGNAL(clicked(bool)), _onState);
    _stateMachine->addState(_onState);
    _stateMachine->addState(_offState);
    _stateMachine->setInitialState(_offState);
    _stateMachine->start();
}

void audioInputWidget::onOscMessage(QOSCMessage *message)
{
    if(_stateMachine->configuration().contains(_onState)){
        emit tick();
    }
}

void audioInputWidget::start()
{
    _startButton->setIcon(QIcon(":icons/font-awesome_4-7-0_pause_256_0_d35400_none.png"));
    _receiver->stop();
    //setPort
    _receiver->start();
    emit started();
}

void audioInputWidget::stop()
{
    _startButton->setIcon(QIcon(":icons/font-awesome_4-7-0_play_256_0_d35400_none.png"));
    _receiver->stop();
}
