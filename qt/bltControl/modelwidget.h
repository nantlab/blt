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

    QByteArray getSerializedBar();
    QByteArray getSerializedLeftBench();
    QByteArray getSerializedMiddleBench();
    QByteArray getSerializedRightBench();

    QImage* getBar();
    QImage* getLeftBench();
    QImage* getMiddleBench();
    QImage* getRightBench();

private:
    QImage *_bar;
    QImage *_leftBench;
    QImage *_middleBench;
    QImage *_rightBench;
signals:
    void modelChanged();
public slots:
    void clearBar();
    void clearLeftBench();
    void clearMiddleBench();
    void clearRightBench();
};

#endif // MODELWIDGET_H
