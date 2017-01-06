#include "program.h"

program::program(QObject *parent) : QObject(parent)
{

}

void program::tick(modelWidget *modelWidget){
    qDebug()<<"program::tick should be overridden";
}
