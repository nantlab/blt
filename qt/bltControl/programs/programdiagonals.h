#ifndef PROGRAMDIAGONALS_H
#define PROGRAMDIAGONALS_H

#include <QObject>
#include "program.h"

class programDiagonals :
        public program
{
    Q_OBJECT
public:
    explicit programDiagonals(QObject *parent = 0);
private:
    int _index;

signals:

public slots:
    void tick(modelWidget *modelWidget);
};


#endif // PROGRAMDIAGONALS_H
