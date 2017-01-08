#ifndef MODELWIDGET_H
#define MODELWIDGET_H

#include <QByteArray>
#include <QBuffer>
#include <QImage>
#include <QWidget>

enum componentEnum{
    BAR,
    LEFTBENCH,
    MIDDLEBENCH,
    RIGHTBENCH
};

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
    void clear(componentEnum component, int red = 0, int green = 0, int blue = 0);

    void setPixel(componentEnum component, int column, int row, int red, int green, int blue);
};

#endif // MODELWIDGET_H
