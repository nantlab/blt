#include "modelcontrolwidget.h"
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>
#include <QColorDialog>

modelControlWidget::modelControlWidget(modelWidget *modelWidget, QWidget *parent) :
    QWidget(parent),
    _modelWidget(modelWidget)

{
    auto mainLayout = new QVBoxLayout(this);
    auto barColorButton = new QPushButton("color bar", this);
    auto leftBenchColorButton = new QPushButton("color leftBench", this);
    auto middleBenchColorButton = new QPushButton("color middleBench", this);
    auto rightBenchColorButton = new QPushButton("color ightBench", this);
    mainLayout->addWidget(barColorButton);
    mainLayout->addWidget(leftBenchColorButton);
    mainLayout->addWidget(middleBenchColorButton);
    mainLayout->addWidget(rightBenchColorButton);

    setLayout(mainLayout);

    connect(barColorButton, SIGNAL(clicked(bool)), this, SLOT(onBarColorButtonClicked()));
    connect(leftBenchColorButton, SIGNAL(clicked(bool)), this, SLOT(onLeftBenchColorButtonClicked()));
    connect(middleBenchColorButton, SIGNAL(clicked(bool)), this, SLOT(onMiddleBenchColorButtonClicked()));
    connect(rightBenchColorButton, SIGNAL(clicked(bool)), this, SLOT(onRightBenchColorButtonClicked()));

}

void modelControlWidget::onBarColorButtonClicked(){
    QColor color = QColorDialog::getColor(Qt::yellow, this );
    if( color.isValid() )
    {
        _modelWidget->clear(BAR, color.red(), color.green(), color.blue());
        _modelWidget->update();
    }
}

void modelControlWidget::onLeftBenchColorButtonClicked(){
    QColor color = QColorDialog::getColor(Qt::yellow, this );
    if( color.isValid() )
    {
        _modelWidget->clear(LEFTBENCH, color.red(), color.green(), color.blue());
        _modelWidget->update();
    }
}

void modelControlWidget::onMiddleBenchColorButtonClicked()
{
    QColor color = QColorDialog::getColor(Qt::yellow, this );
    if( color.isValid() )
    {
        _modelWidget->clear(MIDDLEBENCH, color.red(), color.green(), color.blue());
        _modelWidget->update();
    }
}
void modelControlWidget::onRightBenchColorButtonClicked()
{
    QColor color = QColorDialog::getColor(Qt::yellow, this );
    if( color.isValid() )
    {
        _modelWidget->clear(RIGHTBENCH, color.red(), color.green(), color.blue());
        _modelWidget->update();
    }
}
