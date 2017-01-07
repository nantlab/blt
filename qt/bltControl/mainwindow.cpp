#include "mainwindow.h"
#include <QDebug>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _modelWidget(new modelWidget(this)),
    _program(new programDiagonals(this)),
    _controlWidget(new controlWidget()),
    _oscSenderBar(new QOSCSender("192.168.178.10", 8010)),
    _oscSenderLeftBench(new QOSCSender("192.168.178.11", 8011)),
    _oscSenderMiddleBench(new QOSCSender("192.168.178.12", 8012)),
    _oscSenderRightBench(new QOSCSender("192.168.178.13", 8013))
{
    auto mainWidget = new QWidget(this);
    auto mainLayout = new QHBoxLayout(mainWidget);
    mainLayout->addWidget(_modelWidget);
    mainLayout->addWidget(_controlWidget);

    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    connect(_controlWidget->getInputWidget()->getMetronomWidget()->getTimer(), SIGNAL(timeout()), this, SLOT(onModelChange()));
    showFullScreen();
    _modelWidget->setMinimumSize(500, 400);

}

MainWindow::~MainWindow()
{

}

void MainWindow::onModelChange()
{
    _program->tick(_modelWidget);
    auto message = new QOSCMessage("/all", this);
    message->add(_modelWidget->getSerializedBar());
    _oscSenderBar->send(message);
}
