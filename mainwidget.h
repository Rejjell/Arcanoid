#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "gamefield.h"
#include "QOpenGLWidget"
#include "QObject"
#include "QWidget"
#include "QPainter"
#include "gamefield.h"
#include "QPixmap"
#include "QOpenGLWidget"
#include "constants.h"
#include "QKeyEvent"

class MainWidget: public QWidget
{
    Q_OBJECT
public:
    MainWidget(QWidget *parent);
    void restart();

public slots:
    void nextTact();
protected:
     void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
     void draw();
     GameField* field;
     int count;
     virtual void  keyPressEvent(QKeyEvent *event);
     void  mousePressEvent ( QMouseEvent * event );
     void  mouseMoveEvent(QMouseEvent *event);
     void mouseReleaseEvent(QMouseEvent *);
};

#endif // MAINWIDGET_H
