#include "playerwidget.h"
#include <QLabel>
#include <QVBoxLayout>

playerWidget::playerWidget(QWidget *parent) : QWidget(parent)
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(new QLabel("player"));
    setLayout(mainLayout);
}
