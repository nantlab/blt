#ifndef PROGRAMDIAGONALS_H
#define PROGRAMDIAGONALS_H

#include <QObject>
#include <QPushButton>
#include "program.h"

class programDiagonals :
        public program
{
    Q_OBJECT
public:
    explicit programDiagonals(int duration, QObject *parent = 0) :
        program("diagonals", duration, parent),
        _foregroundColor(QColor(0, 255, 255))
    {
        auto foregroundColorButton = new QPushButton("foregroundColor");
        connect(foregroundColorButton, SIGNAL(clicked(bool)), this, SLOT(onForegroundColorButtonChlicked()));
        ((QGridLayout*)(_controlWidget->layout()))->addWidget(foregroundColorButton, 1, 0);
    }

private:
    int _index;
    QColor _foregroundColor;

signals:

public slots:
    void tick(modelWidget *modelWidget){
        modelWidget->clear(BAR, _backgroundColor.red(), _backgroundColor.green(), _backgroundColor.blue());
        auto image = modelWidget->getBar();

        _index+=2;
        _index %= modelWidget->getBar()->width();
        image->setPixel(_index, 2, _foregroundColor.rgb());
        if(_index%2==0){
            image->setPixel(_index+1, 2, _foregroundColor.rgb());
        }
        image->setPixel(_index+1, 1, _foregroundColor.rgb());
        if(_index%2==0){
            image->setPixel(_index+2, 1, _foregroundColor.rgb());
        }
        image->setPixel(_index+2, 0, _foregroundColor.rgb());
        if(_index%2==0){
            image->setPixel(_index+3, 0, _foregroundColor.rgb());
        }

        modelWidget->repaint();
        emit modelWidget->modelChanged();
    }

    void onForegroundColorButtonChlicked(){
        QColor color = QColorDialog::getColor(_foregroundColor, _controlWidget);
        if( color.isValid() )
        {
            _foregroundColor = color;
        }
    }
};


#endif // PROGRAMDIAGONALS_H
