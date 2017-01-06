#ifndef COMPONENT_H
#define COMPONENT_H

#include <QObject>

class component : public QObject
{
    Q_OBJECT
public:
    explicit component(QObject *parent = 0);

signals:

public slots:
};

#endif // COMPONENT_H