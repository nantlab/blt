#ifndef METRONOMWIDGET_H
#define METRONOMWIDGET_H

#include <QTimer>
#include <QWidget>
#include "input.h"

class metronomWidget :
        public QWidget,
        public input
{
    Q_OBJECT
public:
    explicit metronomWidget(QWidget *parent = 0);
    QTimer* getTimer();

private:
    QTimer *_timer;

signals:

public slots:
private slots:
    void onIntervalChanged(int value);
};

#endif // METRONOMWIDGET_H
