#include "modelwidget.h"
#include <QPainter>

modelWidget::modelWidget(QWidget *parent) :
    QWidget(parent)
{
    _bar.resize(3*12);
    _leftBench.resize(2*3);
    _middleBench.resize(2*5);
    _rightBench.resize(2*3);
}

void modelWidget::paintEvent(QPaintEvent *)
{
}
