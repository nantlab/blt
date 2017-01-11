#include "playerwidget.h"
#include <QGridLayout>
#include <QHeaderView>
#include <QLabel>
#include <QVBoxLayout>

#include "programs/programdiagonals.h"
#include "programs/programrandom.h"
#include "programs/programcircles.h"
#include "programs/programhearts.h"

playerWidget::playerWidget(modelWidget *modelWidget, QWidget *parent) :
    QWidget(parent),
    _modelWidget(modelWidget),
    _thread(new QThread(this)),
    _playlistWidget(new QTableWidget(this)),
    _controlWidget(new playerControlWidget(this))
{
    _programs.push_back(new programHearts(120));
    _programs.push_back(new programHearts(120));
    _programs.push_back(new programHearts(120));
    _programs.push_back(new programHearts(120));
    _programs.push_back(new programHearts(120));
    _programs.push_back(new programHearts(120));
    _programs.push_back(new programHearts(120));
    _programs.push_back(new programHearts(120));
    _programs.push_back(new programHearts(120));
    _programs.push_back(new programHearts(120));
    _programs.push_back(new programHearts(120));
    _programs.push_back(new programDiagonals(120));
    _programs.push_back(new programRandom(120));
    _programs.push_back(new programCircles(120));
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(_playlistWidget);
    for(int i = 0; i < _programs.size(); i++) {
        auto controlWidget = _programs[i]->getControlWidget();
        mainLayout->addWidget(controlWidget);
    }
    mainLayout->addWidget(_controlWidget);
    setLayout(mainLayout);


    _playlistWidget->setRowCount(_programs.size());
    _playlistWidget->setColumnCount(2);
    QStringList headers;
    headers<<"Name"<<"Duration";
    _playlistWidget->setHorizontalHeaderLabels(headers);
    _playlistWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _playlistWidget->setShowGrid(false);
    _playlistWidget->verticalHeader()->setVisible(false);
    _playlistWidget->setSelectionBehavior(QAbstractItemView::SelectRows);


    for(int i = 0; i < _programs.size(); i++){
        _playlistWidget->setItem(i, 0, new QTableWidgetItem(_programs[i]->getName()));
        _playlistWidget->setItem(i, 1, new QTableWidgetItem(QString::number(_programs[i]->getDuration())));
    }

    connect(_controlWidget->getPreviousButton(), SIGNAL(clicked(bool)), this, SLOT(previous()));
    connect(_controlWidget->getNextButton(), SIGNAL(clicked(bool)), this, SLOT(next()));

    connect(_playlistWidget, SIGNAL(clicked(QModelIndex)), this, SLOT(onProgramSelected(QModelIndex)));
    _currentProgram = _programs[0];

}
