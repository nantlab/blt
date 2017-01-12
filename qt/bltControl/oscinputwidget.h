#ifndef OSCINPUTWIDGET_H
#define OSCINPUTWIDGET_H

#include <QStateMachine>
#include <QToolButton>
#include <QWidget>
#include "input.h"
#include "qoscreceiver.h"

class oscInputWidget :
        public QWidget,
        public input
{
    Q_OBJECT
public:
    explicit oscInputWidget(QWidget *parent = 0);
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

#endif // OSCINPUTWIDGET_H
