#include "mainwindow.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _modelWidget(new modelWidget()),
    _playerWidget(new playerWidget())
{
    auto mainWidget = new QWidget(this);
    auto mainLayout = new QHBoxLayout(mainWidget);
    mainLayout->addWidget(_modelWidget);
    mainLayout->addWidget(_playerWidget);

    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);
}

MainWindow::~MainWindow()
{

}
