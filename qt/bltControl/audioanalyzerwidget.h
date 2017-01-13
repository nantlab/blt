#ifndef AUDIOANALYZERWIDGET_H
#define AUDIOANALYZERWIDGET_H

#include <QStateMachine>
#include <QToolButton>
#include <QWidget>
#include "input.h"
#include "qoscreceiver.h"

class audioInputWidget :
        public QWidget,
        public input
{
    Q_OBJECT
public:
    explicit audioInputWidget(QWidget *parent = 0);
private:
    QOSCReceiver *_receiver;
    QStateMachine *_stateMachine;
    QState *_onState;
    QState *_offState;
    QToolButton *_startButton;
    int _port;

signals:
    void tick();
    void started();

public slots:
    void onOscMessage(QOSCMessage *message);
    void start();
    void stop();
};

#endif // AUDIOANALYZERWIDGET_H
