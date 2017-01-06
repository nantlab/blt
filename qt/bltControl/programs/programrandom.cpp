#include "programrandom.h"

programRandom::programRandom(QObject *parent) :
    program(parent)
{

}

void programRandom::tick(modelWidget *modelWidget)
{
    for(int row = 0; row < modelWidget->getBar()->height(); row++){
        for(int column = 0; column < modelWidget->getBar()->width(); column++){
            modelWidget->getBar()->setPixelColor(column, row, QColor(0, 0, 0));
        }
    }
    for(int i = 0; i < 4; i++){
        auto column = qrand() % modelWidget->getBar()->width();
        auto row = qrand() % modelWidget->getBar()->height();
        modelWidget->getBar()->setPixelColor(column, row, QColor(255, 0, 127));
        modelWidget->getBar()->setPixelColor(++column, row, QColor(255, 0, 127));
        if(qrand() % 2 == 0){

        }else{

        }
    }
    modelWidget->repaint();
}
