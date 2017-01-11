#include "playerwidget.h"
#include <QGridLayout>
#include <QHeaderView>
#include <QLabel>
#include <QVBoxLayout>

#include "programs/programdiagonals.h"
#include "programs/programrandom.h"
#include "programs/programcircles.h"
#include "programs/programhearts.h"

#include <QStringListModel>

playerWidget::playerWidget(modelWidget *modelWidget, QWidget *parent) :
    QWidget(parent),
    _modelWidget(modelWidget),
    _thread(new QThread(this)),
    _playlistWidget(new QListView(this)),
    _controlWidget(new playerControlWidget(this))
{
    _programs.push_back(new programHearts(120));
    _programs.push_back(new programHearts(120));
    _programs.push_back(new programHearts(120));
    _programs.push_back(new programHearts(120));
    _programs.push_back(new programHearts(120));
    _programs.push_back(new programHearts(120));
    _programs.push_back(new programDiagonals(120));
    _programs.push_back(new programRandom(120));
    _programs.push_back(new programCircles(120));
    QStringList listModel;
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(_playlistWidget);
    for(int i = 0; i < _programs.size(); i++) {
        listModel<<_programs[i]->getName();
        auto controlWidget = _programs[i]->getControlWidget();
        mainLayout->addWidget(controlWidget);
    }
    QStringListModel *model = new QStringListModel();
    model->setStringList(listModel);
    _playlistWidget->setModel(model);
    mainLayout->addWidget(_controlWidget);
    mainLayout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Expanding));
    setLayout(mainLayout);


    /*
    _playlistWidget->setRowCount(_programs.size());
    _playlistWidget->setColumnCount(1);
    QStringList headers;
    headers<<"Name";
    _playlistWidget->setHorizontalHeaderLabels(headers);
    _playlistWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _playlistWidget->setShowGrid(false);
    _playlistWidget->verticalHeader()->setVisible(false);
    _playlistWidget->horizontalHeader()->setVisible(false);
    _playlistWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
*/

    connect(_controlWidget->getPreviousButton(), SIGNAL(clicked(bool)), this, SLOT(previous()));
    connect(_controlWidget->getNextButton(), SIGNAL(clicked(bool)), this, SLOT(next()));

    connect(_playlistWidget, SIGNAL(clicked(QModelIndex)), this, SLOT(onProgramSelected(QModelIndex)));
    _currentProgram = _programs[0];

    _playlistWidget->setMaximumHeight(100);

}
