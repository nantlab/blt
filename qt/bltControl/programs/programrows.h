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
        _foregroundColor(QColor(255, 255, 0))
    {
        auto foregroundColorButton = new QPushButton("foregroundColor");
        connect(foregroundColorButton, SIGNAL(clicked(bool)), this, SLOT(onForegroundColorButtonChlicked()));
        _controlWidget->layout()->addWidget(foregroundColorButton);
    }

private:
    int _index;
    QColor _foregroundColor;

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
        _index++;
        _index %= modelWidget->getBar()->height();
    }

    void onForegroundColorButtonChlicked(){
        QColor color = QColorDialog::getColor(Qt::yellow, _controlWidget);
        if( color.isValid() )
        {
            _foregroundColor = color;
        }
    }
};


#endif // PROGRAMROWS_H
