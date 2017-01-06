#ifndef COMPONENT_H
#define COMPONENT_H

#include <QColor>
#include <QObject>
#include <QByteArray>
#include <QBuffer>
#include <QDebug>
class component : public QObject
{
    Q_OBJECT
public:
    explicit component(int width, int height, QObject *parent = 0);
    int getIndex(int column, int row);
    int getWidth();
    int getHeight();
    QColor getColor(int column, int row);



private:
    int _width;
    int _height;
    QByteArray _pixels;

signals:

public slots:
    void setColor(int column, int row, int red, int green, int blue);
};

#endif // COMPONENT_H
