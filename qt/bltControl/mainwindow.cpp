#include "mainwindow.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QToolButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _modelWidget(new modelWidget(this)),
    _program(new programDiagonals(120)),
    _controlWidget(new controlWidget(_modelWidget, this))
{
    auto mainWidget = new QWidget(this);
    auto mainLayout = new QHBoxLayout(mainWidget);
    auto leftWidget = new QWidget(this);
    auto leftWidgetLayout = new QVBoxLayout(leftWidget);
    auto bltControlLabel = new QLabel("bltControl");
    auto bltControlLabelFont = bltControlLabel->font();
    bltControlLabelFont.setBold(true);
    bltControlLabelFont.setPixelSize(48);
    bltControlLabel->setFont(bltControlLabelFont);
    leftWidgetLayout->addWidget(bltControlLabel);
    leftWidgetLayout->addWidget(new modelControlWidget(_modelWidget, this));
    leftWidgetLayout->addWidget(_modelWidget);
    leftWidgetLayout->addSpacerItem(new QSpacerItem(1,1,QSizePolicy::Expanding));
    auto closeButton = new QToolButton();
    connect(closeButton, SIGNAL(clicked(bool)), this, SLOT(onCloseButtonClicked()));
    leftWidgetLayout->addWidget(closeButton);
    leftWidget->setLayout(leftWidgetLayout);

    mainLayout->addWidget(leftWidget);
    mainLayout->addWidget(_controlWidget);
    //mainLayout->setAlignment(_modelWidget, Qt::AlignVCenter);

    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    _modelWidget->setMinimumSize(300, 300);
    setMinimumSize(800, 600);
    QTimer::singleShot(1000, this, SLOT(showFullScreen()));

}

MainWindow::~MainWindow()
{

}

void MainWindow::onModelChange()
{
    _program->tick(_modelWidget);

}
