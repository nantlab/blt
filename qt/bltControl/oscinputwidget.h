#ifndef OSCINPUTWIDGET_H
#define OSCINPUTWIDGET_H

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

signals:
    void tick();

public slots:
    void onOscMessage(QOSCMessage *message);
};

#endif // OSCINPUTWIDGET_H
