#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QTime>

int main(int argc, char *argv[])
{
    qsrand(static_cast<uint>(QTime::currentTime().msec()));
    QApplication a(argc, argv);
    MainWindow w;
    QDesktopWidget wid;
    int width = w.frameGeometry().width();
    int height = w.frameGeometry().height();
    int screenWidth = wid.screen()->width();
    int screenHeight = wid.screen()->height();


    w.setGeometry((screenWidth/2)-(width/2),(screenHeight/2)-(height/2),width,height);

    w.show();
    w.show();

    return a.exec();
}
