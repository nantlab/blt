#include "programrandom.h"

programRandom::programRandom(int duration, QObject *parent) :
    program("random", duration, parent)
{

}

void programRandom::tick(modelWidget *modelWidget)
{
    modelWidget->clearBar();
    auto image = modelWidget->getBar();

    for(int i = 0; i < 4; i++){
        auto column = qrand() % modelWidget->getBar()->width();
        auto row = qrand() % modelWidget->getBar()->height();
        image->setPixel(column, row, qRgb(255,0,127));
        if(qrand() % 2 == 0){

        }else{

        }
    }
    modelWidget->repaint();
}
