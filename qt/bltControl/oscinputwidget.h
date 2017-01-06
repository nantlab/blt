#ifndef OSCINPUTWIDGET_H
#define OSCINPUTWIDGET_H

#include <QWidget>
#include "input.h"

class oscInputWidget :
        public QWidget,
        public input
{
    Q_OBJECT
public:
    explicit oscInputWidget(QWidget *parent = 0);

signals:

public slots:
};

#endif // OSCINPUTWIDGET_H
