#ifndef PROGRAMHEARTS_H
#define PROGRAMHEARTS_H

#include <QObject>
#include <QPushButton>
#include "program.h"

class programHearts :
        public program
{
    Q_OBJECT
public:
    explicit programHearts(int duration, QObject *parent = 0) :
        program("Hearts", duration, parent),
        _currentIndex(0),
        _random(false),
        _commulate(false)
    {
        auto randomButton = new QPushButton("random");
        randomButton->setCheckable(true);
        randomButton->setChecked(_random);
        auto commulateButton = new QPushButton("commulate");
        commulateButton->setCheckable(true);
        commulateButton->setChecked(_commulate);
        connect(randomButton, SIGNAL(toggled(bool)), this, SLOT(onRandomChanged(bool)));
        connect(commulateButton, SIGNAL(toggled(bool)), this, SLOT(onCommulateChanged(bool)));


        ((QGridLayout*)(_controlWidget->layout()))->addWidget(randomButton, 0, 1);
        ((QGridLayout*)(_controlWidget->layout()))->addWidget(commulateButton, 1, 1);
    }

private:
    int _currentIndex;
    bool _random;
    bool _commulate;
    void makeCircle(QImage *image, int column, int row, int red, int green, int blue){
        auto color = qRgb(red, green, blue);
        for(int y = row; y < row+2; y++){
            for(int x = column; x < column+3; x++){
                image->setPixel(x, y, color);
            }
        }
    }

signals:

public slots:
    void tick(modelWidget *modelWidget){
        modelWidget->clear(BAR, _backgroundColor.red(), _backgroundColor.green(), _backgroundColor.blue());
        auto image = modelWidget->getBar();
        auto color = qRgb(qrand()%255, qrand()%255, qrand()%255);
        _currentIndex++;
        _currentIndex %= 3;

        if(_commulate){
            for(int i = 0; i <= _currentIndex; i++){
                makeHeart(image, getPosition(i).x(), getPosition(i).y(), 255, 0 , 0);
            }
        }else{
            makeHeart(image, getPosition(_currentIndex).x(), getPosition(_currentIndex).y(), qrand()%255, qrand()%255, qrand()%255);
        }
        modelWidget->repaint();
        emit modelWidget->modelChanged();
    }
    QPoint getPosition(int index){
        switch(index){
        case 0:
            return QPoint(0,0);
            break;
        case 1:
            return QPoint(4,0);
            break;
        case 2:
            return QPoint(8,0);
            break;
        }
    }
    void makeHeart(QImage *image, int column, int row, int red, int green, int blue){
        auto color = qRgb(red, green, blue);
        image->setPixel(column, row, color);
        image->setPixel(column+2, row, color);
        image->setPixel(column, row+1, color);
        image->setPixel(column+1, row+1, color);
        image->setPixel(column+2, row+1, color);
        image->setPixel(column+1, row+2, color);
    }
    void onRandomChanged(bool value){
        _random = !_random;
        qDebug()<<"random changed"<<_random;
    }
    void onCommulateChanged(bool value){
        _commulate = !_commulate;
    }
};

#endif // PROGRAMHEARTS_H
