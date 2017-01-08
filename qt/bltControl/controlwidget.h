#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QWidget>
#include "qoscsender.h"
#include "inputwidget.h"
#include "modelwidget.h"
#include "playerwidget.h"

class controlWidget : public QWidget
{
    Q_OBJECT
public:
    explicit controlWidget(modelWidget *_modelWidget, QWidget *parent = 0);
    inputWidget* getInputWidget();
    playerWidget *getPlayerWidget();

private:
    QOSCSender *_oscSenderBar;
    QOSCSender *_oscSenderLeftBench;
    QOSCSender *_oscSenderMiddleBench;
    QOSCSender *_oscSenderRightBench;

    modelWidget *_modelWidget;
    inputWidget *_inputWidget;
    playerWidget *_playerWidget;


signals:

public slots:
    void onModelChanged();
};

#endif // CONTROLWIDGET_H
