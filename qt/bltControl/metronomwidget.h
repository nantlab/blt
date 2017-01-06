#ifndef METRONOMWIDGET_H
#define METRONOMWIDGET_H

#include <QLabel>
#include <QToolButton>
#include <QStateMachine>
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
    QStateMachine *_stateMachine;
    QState *_onState;
    QState *_offState;
    QToolButton *_startButton;
    QTimer *_timer;
    QLabel *_timeLabel;

signals:

public slots:
private slots:
    void onStarted();
    void onStopped();

    void onIntervalChanged(int value);
};

#endif // METRONOMWIDGET_H
