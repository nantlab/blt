#ifndef PROGRAM_H
#define PROGRAM_H

#include <QDebug>
#include <QTimer>
#include <QObject>
#include "modelwidget.h"

class program : public QObject
{
    Q_OBJECT
public:
    explicit program(QString name, int duration = 120, QObject *parent = 0);
    QString getName();
    int getDuration();

protected:
    QString _name;
    int _duration;
    float _playposition;
    float _refreshTime;
    QTimer *_timer;

signals:
    void stopped();
    void progress(int seconds, int percentage);


public slots:
    void process();

    virtual void tick(modelWidget *modelWidget);

private slots:
    void timeOut(){
        _playposition += _refreshTime/1000;
        qDebug()<<"playposiiton"<<_playposition;
        emit progress(_playposition, (float)(_duration)/_playposition);
    }
};

#endif // PROGRAM_H
