#include "programdiagonals.h"
#include <QDebug>

programDiagonals::programDiagonals(QObject *parent) :
    program(parent)
{

}

void programDiagonals::tick(modelWidget *modelWidget){
    modelWidget->clearBar();
    auto image = modelWidget->getBar();


    _index+=2;
    _index %= modelWidget->getBar()->width();
    image->setPixel(_index, 2, qRgb(255,0,0));
    if(_index%2==0){
        image->setPixel(_index+1, 2, qRgb(255,0,0));
    }
    image->setPixel(_index+1, 1, qRgb(255,0,0));
    if(_index%2==0){
        image->setPixel(_index+2, 1, qRgb(255,0,0));
    }
    image->setPixel(_index+2, 0, qRgb(255,0,0));
    if(_index%2==0){
        image->setPixel(_index+3, 0, qRgb(255,0,0));
    }

    modelWidget->repaint();
}
