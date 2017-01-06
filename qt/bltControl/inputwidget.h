#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QTabWidget>
#include "audioanalyzerwidget.h"
#include "metronomwidget.h"
#include "oscinputwidget.h"

class inputWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit inputWidget(QWidget *parent = 0);
    metronomWidget *getMetronomWidget();

private:
    audioAnalyzerWidget *_audioAnalyzerWidget;
    metronomWidget *_metronomWidget;
    oscInputWidget *_oscInputWidget;

signals:
    void tick();

public slots:
};

#endif // INPUTWIDGET_H
