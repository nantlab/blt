#ifndef PROGRAMRANDOM_H
#define PROGRAMRANDOM_H

#include <QColorDialog>
#include <QLabel>
#include <QObject>
#include <QPushButton>
#include <QSlider>
#include "program.h"

class programRandom :
        public program
{
    Q_OBJECT
public:
    explicit programRandom(int duration, QObject *parent = 0) :
        program("random", duration, parent),
        _foregroundColor(QColor(255, 0, 0)),
        _tupelSize(2)
    {
        auto foregroundColorButton = new QPushButton("foregroundColor");
        auto tupelSizeSlider = new QSlider();
        tupelSizeSlider->setRange(1,4);
        tupelSizeSlider->setValue(2);
        tupelSizeSlider->setOrientation(Qt::Horizontal);
        connect(foregroundColorButton, SIGNAL(clicked(bool)), this, SLOT(onForegroundColorButtonChlicked()));
        connect(tupelSizeSlider, SIGNAL(valueChanged(int)), this, SLOT(onTupelSizeChanged(int)));


        ((QGridLayout*)(_controlWidget->layout()))->addWidget(foregroundColorButton, 1,0);
        //((QGridLayout*)(_controlWidget->layout()))->addWidget(new QLabel("size"), 0, 1);
        ((QGridLayout*)(_controlWidget->layout()))->addWidget(tupelSizeSlider, 2, 0);
    }
private:
    QColor _foregroundColor;
    int _tupelSize;

signals:

public slots:
    void tick(modelWidget *modelWidget)
    {
        modelWidget->clear(BAR, _backgroundColor.red(), _backgroundColor.green(), _backgroundColor.blue());
        modelWidget->clearLeftBench();
        modelWidget->getLeftBench()->setPixel(0, 1, qRgb(0,0,0));
        auto image = modelWidget->getBar();

        for(int i = 0; i < 3; i++){
            auto column = qrand() % modelWidget->getBar()->width();
            auto row = qrand() % modelWidget->getBar()->height();
            for(int i = 0; i < _tupelSize; i++){
                image->setPixel(column+i, row, _foregroundColor.rgb());
            }
        }
        modelWidget->repaint();
        emit modelWidget->modelChanged();
    }
    void onBackgroundColorButtonClicked(){
        QColor color = QColorDialog::getColor(Qt::yellow, _controlWidget);
        if( color.isValid() )
        {
            _backgroundColor = color;
        }
    }
    void onForegroundColorButtonChlicked(){
        QColor color = QColorDialog::getColor(Qt::yellow, _controlWidget);
        if( color.isValid() )
        {
            _foregroundColor = color;
        }
    }
    void onTupelSizeChanged(int size){
        _tupelSize = size;
    }

};

#endif // PROGRAMRANDOM_H
