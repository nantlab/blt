#ifndef PROGRAMRANDOM_H
#define PROGRAMRANDOM_H

#include <QObject>

class programRandom : public QObject
{
    Q_OBJECT
public:
    explicit programRandom(QObject *parent = 0);

signals:

public slots:
};

#endif // PROGRAMRANDOM_H