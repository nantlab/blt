#ifndef PLAYERCONTROLWIDGET_H
#define PLAYERCONTROLWIDGET_H

#include <QSlider>
#include <QToolButton>
#include <QWidget>

class playerControlWidget : public QWidget
{
    Q_OBJECT
public:
    explicit playerControlWidget(QWidget *parent = 0);
    QToolButton *getPreviousButton(){
        return _previousButton;
    }
    QToolButton *getNextButton(){
        return _nextButton;
    }

private:
    QToolButton *_previousButton;
    QToolButton *_nextButton;
    QToolButton *_playPauseButton;
    QSlider *_progressSlider;

signals:

public slots:
    void setProgress(int time, int percentage){
        _progressSlider->setValue(percentage);
    }
};

#endif // PLAYERCONTROLWIDGET_H
