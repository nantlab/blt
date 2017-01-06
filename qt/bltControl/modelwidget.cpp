#include "modelwidget.h"
#include <QtMath>
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


    _leftBench->setPixelColor(0,0, QColor(255,0,255));
    _middleBench->setPixelColor(2,0, QColor(0,255,255));
    _rightBench->setPixelColor(2,0, QColor(0,255,255));

    emit modelChanged();
}

void modelWidget::paintEvent(QPaintEvent *)
{
    auto painter = new QPainter(this);
    painter->setRenderHint(QPainter::Antialiasing);

    float length = width()/_bar->width();
    float height = length/2 * sqrt(3);

    float y = height;
    float x = 0;
    for(int column = 0; column < _bar->width()-1; column++){
        QPainterPath path;
        if(column%2==0){
        path.moveTo(x, y);
        path.lineTo(x+length, y);
        path.lineTo(x+length/2, y-height);
        path.lineTo(x, y);
        }else{
            path.moveTo(x, y-height);
            path.lineTo(x+length, y-height);
            path.lineTo(x+length/2, y);
            path.lineTo(x, y-height);
        }
        QPen pen(Qt::white, 1);
        painter->setPen(pen);
        painter->fillPath(path, _bar->pixelColor(column, 0));
        painter->drawPath(path);
        x += length/2;
    }
    y += height;
    x = 0;
    for(int column = 0; column < _bar->width(); column++){
        QPainterPath path;
        if(column%2==1){
        path.moveTo(x, y);
        path.lineTo(x+length, y);
        path.lineTo(x+length/2, y-height);
        path.lineTo(x, y);
        }else{
            path.moveTo(x, y-height);
            path.lineTo(x+length, y-height);
            path.lineTo(x+length/2, y);
            path.lineTo(x, y-height);
        }
        QPen pen(Qt::white, 1);
        painter->setPen(pen);
        painter->fillPath(path, _bar->pixelColor(column, 1));
        painter->drawPath(path);
        x += length/2;
    }
    y += height;
    x = 0;
    for(int column = 0; column < _bar->width(); column++){
        if(column != 0){
            QPainterPath path;
            if(column%2==0){
            path.moveTo(x, y);
            path.lineTo(x+length, y);
            path.lineTo(x+length/2, y-height);
            path.lineTo(x, y);
            }else{
                path.moveTo(x, y-height);
                path.lineTo(x+length, y-height);
                path.lineTo(x+length/2, y);
                path.lineTo(x, y-height);
            }
            QPen pen(Qt::white, 1);
            painter->setPen(pen);
            painter->fillPath(path, _bar->pixelColor(column, 2));
            painter->drawPath(path);
        }

        x += length/2;
    }


    //left bench
    //upper row
    y += 2*height;
    x = 0;

    {
        QPainterPath path;
        path.moveTo(x, y);
        path.lineTo(x+length, y);
        path.lineTo(x+length/2, y-height);
        path.lineTo(x, y);
        QPen pen(Qt::white, 1);
        painter->setPen(pen);
        painter->fillPath(path, _leftBench->pixelColor(0, 0));
        painter->drawPath(path);
    }

    //lower row
    y += height;
    x = 0;
    for(int column = 0; column < _leftBench->width(); column++){
        QPainterPath path;
        if(column%2==1){
        path.moveTo(x, y);
        path.lineTo(x+length, y);
        path.lineTo(x+length/2, y-height);
        path.lineTo(x, y);
        }else{
            path.moveTo(x, y-height);
            path.lineTo(x+length, y-height);
            path.lineTo(x+length/2, y);
            path.lineTo(x, y-height);
        }
        QPen pen(Qt::white, 1);
        painter->setPen(pen);
        painter->fillPath(path, _leftBench->pixelColor(column, 1));
        painter->drawPath(path);
        x += length/2;
    }

    //middle bench
    //upper row
    x += _leftBench->width()*length/2;
    y -= height;

    {
        QPainterPath path;
        path.moveTo(x+length, y);
        path.lineTo(x+2*length, y);
        path.lineTo(x+1.5*length, y-height);
        path.lineTo(x+length, y);
        QPen pen(Qt::white, 1);
        painter->setPen(pen);
        painter->fillPath(path, _middleBench->pixelColor(2, 0));
        painter->drawPath(path);
    }

    //lower row
    y += height;
    for(int column = 0; column < _middleBench->width(); column++){
        QPainterPath path;
        if(column%2==1){
        path.moveTo(x, y);
        path.lineTo(x+length, y);
        path.lineTo(x+length/2, y-height);
        path.lineTo(x, y);
        }else{
            path.moveTo(x, y-height);
            path.lineTo(x+length, y-height);
            path.lineTo(x+length/2, y);
            path.lineTo(x, y-height);
        }
        QPen pen(Qt::white, 1);
        painter->setPen(pen);
        painter->fillPath(path, _middleBench->pixelColor(column, 1));
        painter->drawPath(path);
        x += length/2;
    }

    //right bench
    //upper row
    x += _rightBench->width()*length/2;
    y -= height;

    {
        QPainterPath path;
        path.moveTo(x+length, y);
        path.lineTo(x+2*length, y);
        path.lineTo(x+1.5*length, y-height);
        path.lineTo(x+length, y);
        QPen pen(Qt::white, 1);
        painter->setPen(pen);
        painter->fillPath(path, _rightBench->pixelColor(2, 0));
        painter->drawPath(path);
    }

    //lower row
    y += height;
    for(int column = 0; column < _rightBench->width(); column++){
        QPainterPath path;
        if(column%2==1){
        path.moveTo(x, y);
        path.lineTo(x+length, y);
        path.lineTo(x+length/2, y-height);
        path.lineTo(x, y);
        }else{
            path.moveTo(x, y-height);
            path.lineTo(x+length, y-height);
            path.lineTo(x+length/2, y);
            path.lineTo(x, y-height);
        }
        QPen pen(Qt::white, 1);
        painter->setPen(pen);
        painter->fillPath(path, _rightBench->pixelColor(column, 1));
        painter->drawPath(path);
        x += length/2;
    }
}

QImage *modelWidget::getBar(){
    return _bar;
}
