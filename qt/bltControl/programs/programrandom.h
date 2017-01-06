#ifndef PROGRAMRANDOM_H
#define PROGRAMRANDOM_H

#include <QObject>
#include "program.h"

class programRandom :
        public program
{
    Q_OBJECT
public:
    explicit programRandom(QObject *parent = 0);

signals:

public slots:
    void tick(modelWidget *modelWidget);
};

#endif // PROGRAMRANDOM_H
