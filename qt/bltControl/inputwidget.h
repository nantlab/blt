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
    audioInputWidget *getAudioInputWidget();
private:
    audioInputWidget *_audioInputWidget;
    metronomWidget *_metronomWidget;
    oscInputWidget *_oscInputWidget;

signals:
    void tick();

public slots:
    void onTick();
    void onAudioInputStarted();
    void onMetronomStarted();
    void onOscInputStarted();
};

#endif // INPUTWIDGET_H
