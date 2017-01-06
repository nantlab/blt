#ifndef MODELWIDGET_H
#define MODELWIDGET_H

#include "component.h"
#include <QByteArray>
#include <QBuffer>
#include <QImage>
#include <QWidget>

class modelWidget : public QWidget
{
    Q_OBJECT
public:
    explicit modelWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent * /* event */);
    QByteArray serializeBar(){
        QByteArray ba;
        for(int row = 0; row < _bar->height(); row++){
            for(int column = 0; column < _bar->width(); column++){
                ba.append(_bar->pixelColor(column, row).red());
                ba.append(_bar->pixelColor(column, row).green());
                ba.append(_bar->pixelColor(column, row).blue());
            }
        }
        qDebug() << ba;
        return ba;
    }
    QImage* getBar();

private:
    QImage *_bar;
    QImage *_leftBench;
    QImage *_middleBench;
    QImage *_rightBench;
signals:
    void modelChanged();
public slots:
};

#endif // MODELWIDGET_H
