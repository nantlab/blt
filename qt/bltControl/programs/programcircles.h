#ifndef PROGRAMCIRCLES_H
#define PROGRAMCIRCLES_H

#include <QObject>
#include <QPushButton>
#include "program.h"

class programCircles :
        public program
{
    Q_OBJECT
public:
    explicit programCircles(int duration, QObject *parent = 0) :
        program("Circles", duration, parent),
        _currentIndex(0),
        _random(false),
        _commulate(false),
        _firstColor(QColor(0, 255, 255)),
        _secondColor(QColor(0, 255, 255))
    {
        auto firstColorButton = new QPushButton("firstColor");
        auto secondColorButton = new QPushButton("secondColor");
        auto randomButton = new QPushButton("random");
        randomButton->setCheckable(true);
        randomButton->setChecked(_random);
        auto commulateButton = new QPushButton("commulate");
        commulateButton->setCheckable(true);
        commulateButton->setChecked(_commulate);
        connect(randomButton, SIGNAL(toggled(bool)), this, SLOT(onRandomChanged(bool)));
        connect(commulateButton, SIGNAL(toggled(bool)), this, SLOT(onCommulateChanged(bool)));
        connect(firstColorButton, SIGNAL(clicked(bool)), this, SLOT(onFirstColorButtonClicked(bool)));
        connect(secondColorButton, SIGNAL(clicked(bool)), this, SLOT(onSecondColorButtonClicked(bool)));


         ((QGridLayout*)(_controlWidget->layout()))->addWidget(firstColorButton, 1,0);
         ((QGridLayout*)(_controlWidget->layout()))->addWidget(secondColorButton, 2,0);
         ((QGridLayout*)(_controlWidget->layout()))->addWidget(randomButton, 0,1);
         ((QGridLayout*)(_controlWidget->layout()))->addWidget(commulateButton, 1,1);
    }

private:
    int _currentIndex;
    bool _random;
    bool _commulate;
    QColor _firstColor;
    QColor _secondColor;
    void makeCircle(QImage *image, int column, int row, int red, int green, int blue){
        auto color = qRgb(red, green, blue);
        for(int y = row; y < row+2; y++){
            for(int x = column; x < column+3; x++){
                image->setPixel(x, y, color);
            }
        }
    }
    QPoint getPosition(int circleIndex){
        switch(circleIndex){
        case 0:
            return QPoint(0,0);
            break;
        case 1:
            return QPoint(3,1);
            break;
        case 2:
            return QPoint(6,0);
            break;
        case 3:
            return QPoint(9,1);
            break;
        }
    }

signals:

public slots:
    void tick(modelWidget *modelWidget){
        modelWidget->clear(BAR, _backgroundColor.red(), _backgroundColor.green(), _backgroundColor.blue());
        auto image = modelWidget->getBar();
        if(_random){
            _currentIndex = qrand();
            _currentIndex %= 4;
        }

        if(_commulate){
            for(int i = 0; i <= _currentIndex; i++){
                makeCircle(image, getPosition(i).x(), getPosition(i).y(), _firstColor.red(), _firstColor.green(), _firstColor.blue());
            }
        }else{
            if(_currentIndex%2 == 0){
                makeCircle(image, getPosition(_currentIndex).x(), getPosition(_currentIndex).y(), _firstColor.red(), _firstColor.green(), _firstColor.blue());
            }else{
                makeCircle(image, getPosition(_currentIndex).x(), getPosition(_currentIndex).y(), _secondColor.red(), _secondColor.green(), _secondColor.blue());
            }
        }
        _currentIndex++;
        _currentIndex %= 4;
        modelWidget->repaint();
        emit modelWidget->modelChanged();
    }
    void onFirstColorButtonClicked(bool value){
        QColor color = QColorDialog::getColor(_firstColor, _controlWidget);
        if( color.isValid() )
        {
            _firstColor = color;
        }
    }

    void onSecondColorButtonClicked(bool value){
        QColor color = QColorDialog::getColor(_secondColor, _controlWidget);
        if( color.isValid() )
        {
            _secondColor = color;
        }
    }

    void onRandomChanged(bool value){
        _random = !_random;
    }
    void onCommulateChanged(bool value){
        _commulate = !_commulate;
    }
};

#endif // PROGRAMCIRCLES_H
