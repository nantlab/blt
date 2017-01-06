#include "programdiagonals.h"
#include <QDebug>

programDiagonals::programDiagonals(QObject *parent) :
    program(parent)
{

}

void programDiagonals::tick(modelWidget *modelWidget){

    for(int row = 0; row < modelWidget->getBar()->height(); row++){
        for(int column = 0; column < modelWidget->getBar()->width(); column++){
            modelWidget->getBar()->setPixelColor(column, row, QColor(0, 0, 0));
        }
    }
    _index+=2;
    _index %= modelWidget->getBar()->width();
    modelWidget->getBar()->setPixelColor(_index, 2, QColor(255, 0, 0));
    if(_index%2==0){
        modelWidget->getBar()->setPixelColor(_index+1, 2, QColor(255, 0, 0));
    }
    modelWidget->getBar()->setPixelColor(_index+1, 1, QColor(255, 0, 0));
    if(_index%2==0){
        modelWidget->getBar()->setPixelColor(_index+2, 1, QColor(255, 0, 0));
    }
    modelWidget->getBar()->setPixelColor(_index+2, 0, QColor(255, 0, 0));
    if(_index%2==0){
        modelWidget->getBar()->setPixelColor(_index+3, 0, QColor(255, 0, 0));
    }

    modelWidget->repaint();
}
