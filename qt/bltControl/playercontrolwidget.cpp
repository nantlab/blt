#include "playercontrolwidget.h"
#include <QHBoxLayout>
#include <QSlider>
#include <QToolButton>

playerControlWidget::playerControlWidget(QWidget *parent) :
    QWidget(parent),
    _progressSlider(new QSlider(this)),
    _previousButton(new QToolButton(this)),
    _playPauseButton(new QToolButton(this)),
    _nextButton(new QToolButton(this))
{
    auto mainLayout = new QHBoxLayout(this);
    setLayout(mainLayout);
    _previousButton->setIcon(QIcon(":icons/font-awesome_4-7-0_step-backward_256_0_d35400_none.png"));
    _playPauseButton->setIcon(QIcon(":icons/font-awesome_4-7-0_play_256_0_d35400_none.png"));
    _nextButton->setIcon(QIcon(":icons/font-awesome_4-7-0_step-forward_256_0_d35400_none.png"));
    _progressSlider->setRange(0,100);
    _progressSlider->setOrientation(Qt::Horizontal);
    mainLayout->addWidget(_previousButton);
    mainLayout->addWidget(_playPauseButton);
    mainLayout->addWidget(_nextButton);
    mainLayout->addWidget(_progressSlider);
}
