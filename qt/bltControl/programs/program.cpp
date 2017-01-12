#include "program.h"

program::program(QString name, int duration, QObject *parent) :
    QObject(parent),
    _name(name),
    _duration(duration),
    _playposition(0),
    _refreshTime(1000),
    _timer(new QTimer(this)),
    _controlWidget(new QWidget)
{
    connect(_timer, SIGNAL(timeout()), this, SLOT(timeOut()));
    _timer->setInterval(_refreshTime);
    _controlWidget->setLayout(new QGridLayout());
    _controlWidget->setVisible(false);

    auto backgroundColorButton = new QPushButton("foregroundColor");
    ((QGridLayout*)(_controlWidget->layout()))->addWidget(backgroundColorButton, 0, 0);

    connect(backgroundColorButton, SIGNAL(clicked(bool)), this, SLOT(onBackgroundColorButtonClicked()));
}

QString program::getName(){
    return _name;
}

int program::getDuration()
{
    return _duration;
}

QWidget *program::getControlWidget(){
    return _controlWidget;
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
