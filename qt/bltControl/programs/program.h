#ifndef PROGRAM_H
#define PROGRAM_H

#include <QObject>

class program : public QObject
{
    Q_OBJECT
public:
    explicit program(QObject *parent = 0);

signals:

public slots:
};

#endif // PROGRAM_H