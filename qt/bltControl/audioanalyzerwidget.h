#ifndef AUDIOANALYZERWIDGET_H
#define AUDIOANALYZERWIDGET_H

#include <QWidget>
#include "input.h"

class audioAnalyzerWidget :
        public QWidget,
        public input
{
    Q_OBJECT
public:
    explicit audioAnalyzerWidget(QWidget *parent = 0);

signals:

public slots:
};

#endif // AUDIOANALYZERWIDGET_H
