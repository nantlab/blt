#include "component.h"
#include <QDebug>

component::component(int width, int height, QObject *parent) :
    QObject(parent),
    _width(width),
    _height(height)
{
    _pixels.resize(_width * _height * 3);
}

int component::getIndex(int column, int row)
{
    return (row * _width + column) * 3;
}

int component::getWidth()
{
    return _width;
}

int component::getHeight()
{
    return _height;
}

QColor component::getColor(int column, int row)
{
    auto index = getIndex(column, row);
    int red = _pixels[index];
    int green = _pixels[index+1];
    int blue = _pixels[index+2];
    qDebug()<<red<<green<<blue;
    return QColor(red, green, blue);
}

void component::setColor(int column, int row, int red, int green, int blue)
{
    auto index = getIndex(column, row);
    _pixels[index] = red;
    _pixels[index+1] = green;
    _pixels[index+2] = blue;
    qDebug()<<_pixels;
}
