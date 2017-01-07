#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QTableWidget>
#include <QVector>
#include <QWidget>
#include "playercontrolwidget.h"
#include "programs/program.h"

class playerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit playerWidget(QWidget *parent = 0);
private:
    QVector<program*> _programs;
    QTableWidget *_playlistWidget;
    playerControlWidget *_controlWidget;

signals:

public slots:
};

#endif // PLAYERWIDGET_H
