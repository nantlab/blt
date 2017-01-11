#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "modelwidget.h"
#include "modelcontrolwidget.h"
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
    void closeEvent(QCloseEvent *event){
        _modelWidget->clearBar();
        _modelWidget->clear(BAR);
        _modelWidget->clear(LEFTBENCH);
        _modelWidget->clear(MIDDLEBENCH);
        _modelWidget->clear(RIGHTBENCH);
        emit _modelWidget->modelChanged();
    }

private:
    modelWidget *_modelWidget;
    program *_program;
    controlWidget *_controlWidget;

public slots:
    void onModelChange();
};

#endif // MAINWINDOW_H
