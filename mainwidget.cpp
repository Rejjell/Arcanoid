#include "mainwidget.h"
#include "QWidget"
#include "QPainter"
#include "gamefield.h"

MainWidget::MainWidget(QWidget* parent):
    QWidget(parent)
{
    this->move(0,0);
    this->setGeometry(0,0,300,300);
    field = new GameField();
    startTimer(600);
}

void MainWidget::nextTact() {


}

void MainWidget::timerEvent(QTimerEvent *)
{
    field->NextTact();
    update();
}

void MainWidget::draw() {
    QPainter painter;

    painter.begin(this);
    painter.drawText(QRect(400, 0, 70, 50), Qt::AlignCenter,"x =|" + QString::number(field->ball->pos.x())+"|");
    QPen pen =  QPen(Qt::black);
    QBrush brush = QBrush(QColor(0,255,0));
    pen.setWidth(2);

    painter.setPen(pen);
    painter.drawRect(0,0,size().width(),size().height());
    pen.setWidth(1);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawEllipse(field->ball->pos,field->ball->radius,field->ball->radius);
    painter.drawLine(298,0,298,300);
    painter.end();
}

void MainWidget::paintEvent(QPaintEvent *event){
    draw();
}

