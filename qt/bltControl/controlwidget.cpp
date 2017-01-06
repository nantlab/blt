#include "controlwidget.h"
#include <QVBoxLayout>

controlWidget::controlWidget(QWidget *parent) :
    QWidget(parent),
    _inputWidget(new inputWidget()),
    _playerWidget(new playerWidget())
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(_inputWidget);
    mainLayout->addWidget(_playerWidget);

    setLayout(mainLayout);

}

inputWidget *controlWidget::getInputWidget(){
    return _inputWidget;
}

playerWidget *controlWidget::getPlayerWidget(){
    return _playerWidget;
}
