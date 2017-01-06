#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QWidget>
#include "inputwidget.h"
#include "playerwidget.h"

class controlWidget : public QWidget
{
    Q_OBJECT
public:
    explicit controlWidget(QWidget *parent = 0);
    inputWidget* getInputWidget();
    playerWidget *getPlayerWidget();

private:
    inputWidget *_inputWidget;
    playerWidget *_playerWidget;


signals:

public slots:
};

#endif // CONTROLWIDGET_H
