#include "modelwidget.h"
#include <QPainter>

modelWidget::modelWidget(QWidget *parent) :
    QWidget(parent),
    _bar(new QImage(12, 3, QImage::Format_RGB888)),
    _leftBench(new QImage(3, 2, QImage::Format_RGB888)),
    _middleBench(new QImage(5, 2, QImage::Format_RGB888)),
    _rightBench(new QImage(3, 2, QImage::Format_RGB888))
{
    setMinimumSize(400,400);
    for(int row = 0; row < _bar->height(); row++){
        for(int column = 0; column < _bar->width(); column++){
            _bar->setPixelColor(column, row, QColor(0,0,0));
        }
    }
    for(int row = 0; row < _middleBench->height(); row++){
        for(int column = 0; column < _middleBench->width(); column++){
            _middleBench->setPixelColor(column, row, QColor(0,0,0));
        }
    }
    for(int row = 0; row < _rightBench->height(); row++){
        for(int column = 0; column < _rightBench->width(); column++){
            _rightBench->setPixelColor(column, row, QColor(0,0,0));
        }
    }

    _bar->setPixelColor(1, 1, QColor(255,255,0));
    _bar->setPixelColor(2, 1, QColor(255,255,0));

    _bar->setPixelColor(8, 0, QColor(255,255,0));
    _bar->setPixelColor(7, 0, QColor(255,255,0));
    _bar->setPixelColor(9, 2, QColor(255,255,0));
    _bar->setPixelColor(10, 2, QColor(255,255,0));

    emit modelChanged();
}

void modelWidget::paintEvent(QPaintEvent *)
{
    auto painter = new QPainter(this);
    painter->setRenderHint(QPainter::Antialiasing);
    for(int row = 0; row < _bar->height(); row++){
        for(int column = 0; column < _bar->width(); column++){
            QPainterPath path;
            path.addRect(column * 10, row * 10, 9, 9);
            QPen pen(Qt::black, 1);
            painter->setPen(pen);
            painter->fillPath(path, _bar->pixelColor(column, row));
            painter->drawPath(path);

        }
    }

    for(int row = 0; row < _leftBench->height(); row++){
        for(int column = 0; column < _leftBench->width(); column++){
            QPainterPath path;
            path.addRect(column * 10, 50+ row * 10, 9, 9);
            QPen pen(Qt::black, 1);
            painter->setPen(pen);
            painter->fillPath(path, _leftBench->pixelColor(column, row));
            painter->drawPath(path);

        }
    }
    for(int row = 0; row < _middleBench->height(); row++){
        for(int column = 0; column < _middleBench->width(); column++){
            QPainterPath path;
            path.addRect(50+column * 10, 50+ row * 10, 9, 9);
            QPen pen(Qt::black, 1);
            painter->setPen(pen);
            painter->fillPath(path, _middleBench->pixelColor(column, row));
            painter->drawPath(path);
        }
    }
    for(int row = 0; row < _rightBench->height(); row++){
        for(int column = 0; column < _rightBench->width(); column++){
            QPainterPath path;
            path.addRect(150+column * 10, 50+ row * 10, 9, 9);
            QPen pen(Qt::black, 1);
            painter->setPen(pen);
            painter->fillPath(path, _rightBench->pixelColor(column, row));
            painter->drawPath(path);
        }
    }
}

QImage *modelWidget::getBar(){
    return _bar;
}
