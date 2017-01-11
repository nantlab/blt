#ifndef MODELCONTROLWIDGET_H
#define MODELCONTROLWIDGET_H

#include <QWidget>
#include "modelwidget.h"

class modelControlWidget : public QWidget
{
    Q_OBJECT
public:
    explicit modelControlWidget(modelWidget *modelWidget, QWidget *parent = 0);
private:
    modelWidget *_modelWidget;

signals:

public slots:
    void onBarColorButtonClicked();
    void onLeftBenchColorButtonClicked();
    void onMiddleBenchColorButtonClicked();
    void onRightBenchColorButtonClicked();
};

#endif // MODELCONTROLWIDGET_H
