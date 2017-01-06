#include "mainwindow.h"
#include <QDebug>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _modelWidget(new modelWidget(this)),
    _program(new programDiagonals(this)),
    _controlWidget(new controlWidget()),
    _oscSender(new QOSCSender("192.168.178.10", 8010))
{
    auto mainWidget = new QWidget(this);
    auto mainLayout = new QHBoxLayout(mainWidget);
    mainLayout->addWidget(_modelWidget);
    mainLayout->addWidget(_controlWidget);

    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    connect(_controlWidget->getInputWidget()->getMetronomWidget()->getTimer(), SIGNAL(timeout()), this, SLOT(onModelChange()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::onModelChange()
{
    _program->tick(_modelWidget);
    qDebug()<<"model changed";
    auto message = new QOSCMessage("/all", this);
    message->add(_modelWidget->serializeBar());
    _oscSender->send(message);
}
