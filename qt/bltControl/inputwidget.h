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
    oscInputWidget *getOscInputWidget();
private:
    audioAnalyzerWidget *_audioAnalyzerWidget;
    metronomWidget *_metronomWidget;
    oscInputWidget *_oscInputWidget;

signals:
    void tick();

public slots:
    void onTick();
    void onMetronomStarted();
    void onOscInputStarted();
};

#endif // INPUTWIDGET_H
