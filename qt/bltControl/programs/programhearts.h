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
        _commulate(false),
        _firstColor(QColor(0,255,255)),
        _secondColor(QColor(0,255,255))
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

signals:

public slots:
    void tick(modelWidget *modelWidget){
        modelWidget->clear(BAR, _backgroundColor.red(), _backgroundColor.green(), _backgroundColor.blue());
        auto image = modelWidget->getBar();
        _currentIndex++;
        _currentIndex %= 3;
        if(_random){
            _currentIndex = qrand();
            _currentIndex %= 3;
        }

        if(_commulate){
            for(int i = 0; i <= _currentIndex; i++){
                makeHeart(image, getPosition(i).x(), getPosition(i).y(), _firstColor.red(), _firstColor.green(), _firstColor.blue());
            }
        }else{
            if(_currentIndex%2 == 0){
                makeHeart(image, getPosition(_currentIndex).x(), getPosition(_currentIndex).y(), _firstColor.red(), _firstColor.green(), _firstColor.blue());
            }else{
                makeHeart(image, getPosition(_currentIndex).x(), getPosition(_currentIndex).y(), _secondColor.red(), _secondColor.green(), _secondColor.blue());
            }
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

#endif // PROGRAMHEARTS_H
