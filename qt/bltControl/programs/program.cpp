#include "program.h"

program::program(QString name, int duration, QObject *parent) :
    QObject(parent),
    _name(name),
    _duration(duration)
{

}

QString program::getName(){
    return _name;
}

int program::getDuration()
{
    return _duration;
}

void program::tick(modelWidget *modelWidget){
    qDebug()<<"program::tick should be overridden";
}
