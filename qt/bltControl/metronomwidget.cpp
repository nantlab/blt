#include "metronomwidget.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpinBox>

metronomWidget::metronomWidget(QWidget *parent) :
    QWidget(parent),
    _timer(new QTimer(this))
{
    auto mainLayout = new QHBoxLayout(this);
    auto timeSpinBox = new QSpinBox(this);
    timeSpinBox->setRange(100, 10000);
    mainLayout->addWidget(new QPushButton("start"));
    mainLayout->addWidget(timeSpinBox);


    connect(timeSpinBox, SIGNAL(valueChanged(int)), this, SLOT(onIntervalChanged(int)));
    _timer->start(1000);

}

QTimer *metronomWidget::getTimer(){
    return _timer;
}

void metronomWidget::onIntervalChanged(int value)
{
    _timer->setInterval(value);

}
