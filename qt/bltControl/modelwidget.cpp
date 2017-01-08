#include "modelwidget.h"

#include <QDebug>
#include <QtMath>
#include <QPainter>

modelWidget::modelWidget(QWidget *parent) :
    QWidget(parent),
    _bar(new QImage(12, 3, QImage::Format_RGB888)),
    _leftBench(new QImage(3, 2, QImage::Format_RGB888)),
    _middleBench(new QImage(5, 2, QImage::Format_RGB888)),
    _rightBench(new QImage(3, 2, QImage::Format_RGB888))
{

    clearBar();
    clearLeftBench();
    clearMiddleBench();
    clearRightBench();
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
        painter->fillPath(path, QColor(_bar->pixel(column, 0)));
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
        painter->fillPath(path, QColor(_bar->pixel(column, 1)));
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
            painter->fillPath(path, QColor(_bar->pixel(column, 2)));
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
        painter->fillPath(path, QColor(_leftBench->pixel(0, 0)));
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
        painter->fillPath(path, QColor(_leftBench->pixel(column, 1)));
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
        painter->fillPath(path, QColor(_middleBench->pixel(2, 0)));
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
        painter->fillPath(path, QColor(_middleBench->pixel(column, 1)));
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
        painter->fillPath(path, QColor(_rightBench->pixel(2, 0)));
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
        painter->fillPath(path, QColor(_rightBench->pixel(column, 1)));
        painter->drawPath(path);
        x += length/2;
    }
}

void modelWidget::clearBar(){
    for(int row = 0; row < _bar->height(); row++){
        for(int column = 0; column < _bar->width(); column++){
            _bar->setPixel(column, row, qRgb(0,0,0));
        }
    }
}
void modelWidget::clearLeftBench(){
    for(int row = 0; row < _leftBench->height(); row++){
        for(int column = 0; column < _leftBench->width(); column++){
            _leftBench->setPixel(column, row, qRgb(0,0,0));
        }
    }
}

void modelWidget::clearMiddleBench()
{
    for(int row = 0; row < _middleBench->height(); row++){
        for(int column = 0; column < _middleBench->width(); column++){
            _middleBench->setPixel(column, row, qRgb(0,0,0));
        }
    }
}

void modelWidget::clearRightBench()
{
    for(int row = 0; row < _rightBench->height(); row++){
        for(int column = 0; column < _rightBench->width(); column++){
            _rightBench->setPixel(column, row, qRgb(0,0,0));
        }
    }
}

void modelWidget::clear(componentEnum component, int red, int green, int blue)
{
    switch(component){
    case BAR: {
        for(int row = 0; row < _bar->height(); row++){
            for(int column = 0; column < _bar->width(); column++){
                _bar->setPixel(column, row, qRgb(red, green, blue));
            }
        }
        break;
    }
    case LEFTBENCH: {
        for(int row = 0; row < _leftBench->height(); row++){
            for(int column = 0; column < _leftBench->width(); column++){
                _leftBench->setPixel(column, row, qRgb(red, green, blue));
            }
        }
        break;
    }
    case MIDDLEBENCH: {
        for(int row = 0; row < _middleBench->height(); row++){
            for(int column = 0; column < _middleBench->width(); column++){
                _middleBench->setPixel(column, row, qRgb(red, green, blue));
            }
        }
        break;
    }
    case RIGHTBENCH: {
        for(int row = 0; row < _rightBench->height(); row++){
            for(int column = 0; column < _rightBench->width(); column++){
                _rightBench->setPixel(column, row, qRgb(red, green, blue));
            }
        }
        break;
    }
    }
}

void modelWidget::setPixel(componentEnum component, int column, int row, int red, int green, int blue){
    switch(component){
    case BAR: {
        _bar->setPixel(column, row, qRgb(red, green, blue));
        break;
    }
    case LEFTBENCH: {
        _leftBench->setPixel(column, row, qRgb(red, green, blue));
        break;
    }
    case MIDDLEBENCH: {
        _middleBench->setPixel(column, row, qRgb(red, green, blue));
        break;
    }
    case RIGHTBENCH: {
        _rightBench->setPixel(column, row, qRgb(red, green, blue));
        break;
    }
    }
}
QByteArray modelWidget::getSerializedBar(){
    QByteArray ba;
    auto bits = _bar->bits();
    for(int i = 0; i < _bar->width() * _bar->height() * 3; i++){
        qDebug()<<bits[i];
        ba.append(bits[i]);
    }
    return ba;
}

QByteArray modelWidget::getSerializedLeftBench()
{
    QByteArray ba;
    auto bits = _leftBench->bits();
    for(int i = 0; i < _leftBench->width() * _leftBench->height() * 3; i++){
        ba.append(bits[i]);
    }
    return ba;
}

QByteArray modelWidget::getSerializedMiddleBench()
{
    QByteArray ba;
    auto bits = _middleBench->bits();
    for(int i = 0; i < _middleBench->width() * _middleBench->height() * 3; i++){
        ba.append(bits[i]);
    }
    return ba;
}

QByteArray modelWidget::getSerializedRightBench()
{
    QByteArray ba;
    auto bits = _rightBench->bits();
    for(int i = 0; i < _rightBench->width() * _rightBench->height() * 3; i++){
        ba.append(bits[i]);
    }
    return ba;
}
QImage *modelWidget::getBar(){
    return _bar;
}

QImage *modelWidget::getLeftBench(){
    return _leftBench;
}

QImage *modelWidget::getMiddleBench(){
    return _middleBench;
}

QImage *modelWidget::getRightBench(){
    return _rightBench;
}
