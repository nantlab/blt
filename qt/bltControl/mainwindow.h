#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "modelwidget.h"
#include "controlwidget.h"

#include "qoscsender.h"

#include "programs/programrandom.h"
#include "programs/programdiagonals.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    modelWidget *_modelWidget;
    program *_program;
    controlWidget *_controlWidget;
    QOSCSender *_oscSenderBar;
    QOSCSender *_oscSenderLeftBench;
    QOSCSender *_oscSenderMiddleBench;
    QOSCSender *_oscSenderRightBench;
public slots:
    void onModelChange();
};

#endif // MAINWINDOW_H
