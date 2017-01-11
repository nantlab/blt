#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QListView>
#include <QTableWidget>
#include <QThread>
#include <QVector>
#include <QWidget>
#include "modelwidget.h"
#include "playercontrolwidget.h"
#include "programs/program.h"

class playerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit playerWidget(modelWidget *modelWidget, QWidget *parent = 0);
    void play(program *program){
        _currentProgram = program;
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
    modelWidget *_modelWidget;
    QThread *_thread;
    QVector<program*> _programs;
    QListView *_playlistWidget;
    playerControlWidget *_controlWidget;
    program* _currentProgram;
    int _currentProgramIndex;



signals:

public slots:
    void onProgramSelected(QModelIndex index){
        play(index.row());
    }

    void play(int index){
        if(_currentProgram != nullptr){
            _currentProgram->getControlWidget()->setVisible(false);
        }
        _currentProgramIndex = index;
        _currentProgram = _programs[_currentProgramIndex];
        _currentProgram->getControlWidget()->setVisible(true);
    }

    void play(){

    }
    void pause(){

    }

    void stop(){
        _currentProgram = 0;
        _currentProgramIndex = -1;
    }

    void previous(){
        _currentProgramIndex--;
        _currentProgramIndex %= _programs.size();
        if(_currentProgramIndex<0){
            _currentProgramIndex = _programs.size()-1;
        }
        _currentProgram = _programs[_currentProgramIndex];
    }

    void next(){
        _currentProgramIndex++;
        _currentProgramIndex %= _programs.size();
        _currentProgram = _programs[_currentProgramIndex];
    }
    void tick(){
        if(_currentProgram != nullptr){
            _currentProgram->tick(_modelWidget);
        }
    }
};

#endif // PLAYERWIDGET_H
