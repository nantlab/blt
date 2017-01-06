#ifndef PROGRAM_H
#define PROGRAM_H

#include <QObject>
#include "modelwidget.h"

class program : public QObject
{
    Q_OBJECT
public:
    explicit program(QObject *parent = 0);

signals:

public slots:
    virtual void tick(modelWidget *modelWidget);
};

#endif // PROGRAM_H
