#include "playercontrolwidget.h"
#include <QHBoxLayout>
#include <QSlider>
#include <QToolButton>

playerControlWidget::playerControlWidget(QWidget *parent) :
    QWidget(parent),
    _progressSlider(new QSlider(this))
{
    auto mainLayout = new QHBoxLayout(this);
    setLayout(mainLayout);
    auto backwardButton = new QToolButton(this);
    backwardButton->setIcon(QIcon(":icons/font-awesome_4-7-0_step-backward_256_0_d35400_none.png"));
    auto playPauseButton = new QToolButton(this);
    playPauseButton->setIcon(QIcon(":icons/font-awesome_4-7-0_play_256_0_d35400_none.png"));
    auto forwardButton = new QToolButton(this);
    forwardButton->setIcon(QIcon(":icons/font-awesome_4-7-0_step-forward_256_0_d35400_none.png"));
    _progressSlider->setRange(0,100);
    _progressSlider->setOrientation(Qt::Horizontal);
    mainLayout->addWidget(backwardButton);
    mainLayout->addWidget(playPauseButton);
    mainLayout->addWidget(forwardButton);
    mainLayout->addWidget(_progressSlider);
}
