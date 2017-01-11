#include "controlwidget.h"
#include <QVBoxLayout>

controlWidget::controlWidget(modelWidget *_modelWidget, QWidget *parent) :
    QWidget(parent),
    //_oscSenderBar(new QOSCSender("192.168.178.10", 8010)),
    _oscSenderBar(new QOSCSender("127.0.0.1", 8010)),
    //_oscSenderLeftBench(new QOSCSender("192.168.178.11", 8011)),
    _oscSenderLeftBench(new QOSCSender("127.0.0.1", 8011)),
    //_oscSenderMiddleBench(new QOSCSender("192.168.178.12", 8012)),
    _oscSenderMiddleBench(new QOSCSender("127.0.0.1", 8012)),
    //_oscSenderRightBench(new QOSCSender("192.168.178.13", 8013)),
    _oscSenderRightBench(new QOSCSender("127.0.0.1", 8013)),
    _modelWidget(_modelWidget),
    _inputWidget(new inputWidget()),
    _playerWidget(new playerWidget(_modelWidget))
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(_inputWidget);
    mainLayout->addWidget(_playerWidget);

    setLayout(mainLayout);


    connect(_modelWidget, SIGNAL(modelChanged()), this, SLOT(onModelChanged()));
    connect(getInputWidget()->getMetronomWidget()->getTimer(), SIGNAL(timeout()), _playerWidget, SLOT(tick()));
    //connect(getInputWidget()->getOscInputWidget(), SIGNAL(tick()), _playerWidget, SLOT(tick()));
}

inputWidget *controlWidget::getInputWidget(){
    return _inputWidget;
}

playerWidget *controlWidget::getPlayerWidget(){
    return _playerWidget;
}

void controlWidget::onModelChanged()
{
    auto barMessage = new QOSCMessage("/all", this);
    barMessage->add(_modelWidget->getSerializedBar());
    _oscSenderBar->send(barMessage);
    auto leftBenchMessage = new QOSCMessage("/all", this);
    leftBenchMessage->add(_modelWidget->getSerializedLeftBench());
    _oscSenderLeftBench->send(leftBenchMessage);
    auto middleBenchMessage = new QOSCMessage("/all", this);
    middleBenchMessage->add(_modelWidget->getSerializedMiddleBench());
    _oscSenderMiddleBench->send(middleBenchMessage);
    auto rightBenchMessage = new QOSCMessage("/all", this);
    rightBenchMessage->add(_modelWidget->getSerializedRightBench());
    _oscSenderRightBench->send(rightBenchMessage);
}
