#ifndef PROGRAMCIRCLES_H
#define PROGRAMCIRCLES_H

#include <QObject>
#include "program.h"

class programCircles :
        public program
{
    Q_OBJECT
public:
    explicit programCircles(int duration, QObject *parent = 0) :
        program("Circles", duration, parent)
    {

    }

signals:

public slots:
    void tick(modelWidget *modelWidget){
        modelWidget->clearBar();
        auto image = modelWidget->getBar();
        for(int i = 0; i < 2; i++){
            int row = qrand() % image->height()-1;
            int column = qrand() % image->width()-1;
            if((row % 2 == 0 && column % 2 == 1) || (row == 1 && column % 2 == 0)){
                column++;
            }

            auto color = qRgb(qrand()%255, qrand()%255, qrand()%255);
            for(int i = row; i < row+2; i++){
                for(int j = column; j < column+3; j++){
                    image->setPixel(j, i, color);
                }
            }
        }

        modelWidget->repaint();
    }
};

#endif // PROGRAMCIRCLES_H
