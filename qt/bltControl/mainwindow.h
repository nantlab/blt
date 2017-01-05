#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "modelwidget.h"
#include "playerwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    modelWidget *_modelWidget;
    playerWidget *_playerWidget;
};

#endif // MAINWINDOW_H
