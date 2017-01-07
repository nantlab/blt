#ifndef PLAYERCONTROLWIDGET_H
#define PLAYERCONTROLWIDGET_H

#include <QSlider>
#include <QWidget>

class playerControlWidget : public QWidget
{
    Q_OBJECT
public:
    explicit playerControlWidget(QWidget *parent = 0);
private:
    QSlider *_progressSlider;

signals:

public slots:
    void setProgress(int time, int percentage){
        _progressSlider->setValue(percentage);
    }
};

#endif // PLAYERCONTROLWIDGET_H
