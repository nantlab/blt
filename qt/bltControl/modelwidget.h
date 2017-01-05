#ifndef MODELWIDGET_H
#define MODELWIDGET_H

#include <QByteArray>
#include <QWidget>

class modelWidget : public QWidget
{
    Q_OBJECT
public:
    explicit modelWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent * /* event */);
private:
    QByteArray _bar;
    QByteArray _leftBench;
    QByteArray _middleBench;
    QByteArray _rightBench;
signals:

public slots:
};

#endif // MODELWIDGET_H
