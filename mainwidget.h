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

class MainWidget: public QWidget
{
    Q_OBJECT
public:
    MainWidget(QWidget *parent);

public slots:
    void nextTact();
protected:
     void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
     void draw();
     GameField* field;
     int count;
};

#endif // MAINWIDGET_H
