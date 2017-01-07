#include "program.h"

program::program(QString name, int duration, QObject *parent) :
    QObject(parent),
    _name(name),
    _duration(duration),
    _playposition(0),
    _refreshTime(1000),
    _timer(new QTimer(this))
{
    connect(_timer, SIGNAL(timeout()), this, SLOT(timeOut()));
        _timer->setInterval(_refreshTime);
}

QString program::getName(){
    return _name;
}

int program::getDuration()
{
    return _duration;
}

void program::process(){
    qDebug()<<"process";
    _timer->start(1000);
    qDebug()<<"timerStarted";
    while(_playposition < _duration){
        //qDebug()<<"remaining time"<<timer->remainingTime()<<timer->isActive();
    }
    emit stopped();
}

void program::tick(modelWidget *modelWidget){
    qDebug()<<"program::tick should be overridden";
}
