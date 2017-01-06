#ifndef INPUT_H
#define INPUT_H

#include <QObject>

class input : public QObject
{
    Q_OBJECT
public:
    explicit input(QObject *parent = 0);

signals:

public slots:
};

#endif // INPUT_H