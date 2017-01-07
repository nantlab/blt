#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QTableWidget>
#include <QThread>
#include <QVector>
#include <QWidget>
#include "playercontrolwidget.h"
#include "programs/program.h"

class playerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit playerWidget(QWidget *parent = 0);
    void play(program *program){
        program->moveToThread(_thread);
        //connect(worker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
        connect(_thread, SIGNAL(started()), program, SLOT(process()));
        connect(program, SIGNAL(progress(int,int)), _controlWidget, SLOT(setProgress(int,int)));
        connect(program, SIGNAL(stopped()), _thread, SLOT(quit()));
        //connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
        //connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        _thread->start();
    }
private:
    QThread *_thread;
    QVector<program*> _programs;
    QTableWidget *_playlistWidget;
    playerControlWidget *_controlWidget;



signals:

public slots:
    void play(){

    }
    void pause(){

    }
    void stop(){

    }
    void previous(){

    }

    void next(){

    }
};

#endif // PLAYERWIDGET_H
