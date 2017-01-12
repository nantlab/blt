#ifndef PROGRAMROWS_H
#define PROGRAMROWS_H

#include <QObject>
#include <QPushButton>
#include "program.h"

class programRows :
        public program
{
    Q_OBJECT
public:
    explicit programRows(int duration, QObject *parent = 0) :
        program("rows", duration, parent),
        _foregroundColor(QColor(0, 255, 255)),
        _inverse(false)
    {
        auto foregroundColorButton = new QPushButton("foregroundColor");
        auto inverseButton = new QPushButton("inverse");
        inverseButton->setCheckable(true);
        inverseButton->setChecked(_inverse);
        connect(foregroundColorButton, SIGNAL(clicked(bool)), this, SLOT(onForegroundColorButtonChlicked()));
        connect(inverseButton, SIGNAL(toggled(bool)), this, SLOT(onInverseButtonClicked(bool)));
        ((QGridLayout*)(_controlWidget->layout()))->addWidget(foregroundColorButton, 1, 0);
        ((QGridLayout*)(_controlWidget->layout()))->addWidget(inverseButton, 2, 0);
    }

private:
    int _index;
    QColor _foregroundColor;
    bool _inverse;

signals:

public slots:
    void tick(modelWidget *modelWidget){
        modelWidget->clear(BAR, _backgroundColor.red(), _backgroundColor.green(), _backgroundColor.blue());
        auto image = modelWidget->getBar();
        for(int column = 0; column < modelWidget->getBar()->width(); column++){
            image->setPixel(column, _index, _foregroundColor.rgb());
        }

        modelWidget->repaint();
        emit modelWidget->modelChanged();
        if(_inverse){
            _index--;
            if(_index < 0){
                _index = modelWidget->getBar()->width() - 1;
            }
        }else{
            _index++;
        }
        _index %= modelWidget->getBar()->height();
    }

    void onForegroundColorButtonChlicked(){
        QColor color = QColorDialog::getColor(_foregroundColor, _controlWidget);
        if( color.isValid() )
        {
            _foregroundColor = color;
        }
    }
    void onInverseButtonClicked(bool value){
        _inverse = !_inverse;
    }
};


#endif // PROGRAMROWS_H
