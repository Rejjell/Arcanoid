#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "gamefield.h"

class MainWidget: public QWidget
{
public:
    MainWidget(QWidget *parent);
    void nextTact();
protected:
     void paintEvent(QPaintEvent *event);
     void timerEvent(QTimerEvent *);
     void draw();
     GameField* field;
};

#endif // MAINWIDGET_H
