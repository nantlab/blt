#ifndef PROGRAM_H
#define PROGRAM_H

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

signals:

public slots:
    virtual void tick(modelWidget *modelWidget);
};

#endif // PROGRAM_H
