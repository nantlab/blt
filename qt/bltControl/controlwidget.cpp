#include "controlwidget.h"
#include <QVBoxLayout>

controlWidget::controlWidget(modelWidget *_modelWidget, QWidget *parent) :
    QWidget(parent),
    _oscSenderBar(new QOSCSender("192.168.178.10", 8010)),
    //_oscSenderBar(new QOSCSender("127.0.0.1", 8010)),
    _oscSenderLeftBench(new QOSCSender("192.168.178.11", 8011)),
    //_oscSenderLeftBench(new QOSCSender("127.0.0.1", 8011)),
    _oscSenderMiddleBench(new QOSCSender("192.168.178.12", 8012)),
    //_oscSenderMiddleBench(new QOSCSender("127.0.0.1", 8012)),
    _oscSenderRightBench(new QOSCSender("192.168.178.13", 8013)),
    //_oscSenderRightBench(new QOSCSender("127.0.0.1", 8013)),
    _modelWidget(_modelWidget),
	_inputWidget(new inputWidget()),
	_playerWidget(new playerWidget(_modelWidget))
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(_inputWidget);
	mainLayout->addWidget(_playerWidget);

    setLayout(mainLayout);


    connect(_modelWidget, SIGNAL(modelChanged()), this, SLOT(onModelChanged()));
	connect(_inputWidget, SIGNAL(tick()), _playerWidget, SLOT(tick()));
    _inputWidget->setMaximumHeight(100);
	_playerWidget->setMaximumHeight(400);
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
    //leftBenchMessage->add(_modelWidget->getSerializedLeftBench());
    auto rgb = _modelWidget->getLeftBench()->pixel(0,0);
    QColor color(rgb);
    leftBenchMessage->addInt(color.red());
    leftBenchMessage->addInt(color.green());
    leftBenchMessage->addInt(color.blue());
    _oscSenderLeftBench->send(leftBenchMessage);
    auto middleBenchMessage = new QOSCMessage("/all", this);
    //middleBenchMessage->add(_modelWidget->getSerializedMiddleBench());
    auto middleBenchRgb = _modelWidget->getMiddleBench()->pixel(0,0);
    color.setRgba(middleBenchRgb);
    middleBenchMessage->addInt(color.red());
    middleBenchMessage->addInt(color.green());
    middleBenchMessage->addInt(color.blue());
    _oscSenderMiddleBench->send(middleBenchMessage);
    auto rightBenchMessage = new QOSCMessage("/all", this);
    //rightBenchMessage->add(_modelWidget->getSerializedRightBench());
    auto rightBenchRgb = _modelWidget->getRightBench()->pixel(0,0);
    color.setRgba(rightBenchRgb);
    rightBenchMessage->addInt(color.red());
    rightBenchMessage->addInt(color.green());
    rightBenchMessage->addInt(color.blue());
    _oscSenderRightBench->send(rightBenchMessage);
}
