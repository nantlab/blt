#include "oscinputwidget.h"
#include <QDebug>

oscInputWidget::oscInputWidget(QWidget *parent) :
    QWidget(parent),
    _receiver(new QOSCReceiver(8000, this))
{
    connect(_receiver, SIGNAL(messageReceived(QOSCMessage*)), this, SLOT(onOscMessage(QOSCMessage*)));
    _receiver->start();
}

void oscInputWidget::onOscMessage(QOSCMessage *message)
{
    qDebug()<<"new message"<<message->getAddress();
    emit tick();

}
