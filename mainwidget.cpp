#include "mainwidget.h"

MainWidget::MainWidget(QWidget* parent):
    QWidget(parent)
{
    this->move(0,0);
    this->setGeometry(0,0,WIDTH, HEIGHT );
    field = new GameField();
    count = 0;
}

void MainWidget::nextTact() {
    field->NextTact();
    update();

}

void MainWidget::draw() {
    QPainter painter;

    QPixmap pixmap (WIDTH, HEIGHT);

    painter.begin(&pixmap);
    QPen pen =  QPen(Qt::black);
    pen.setWidth(BORDER_WIDTH);

    QBrush brush = QBrush(QColor(0,0,0));
    painter.setBrush(brush);
    painter.drawRect(0,0,WIDTH,HEIGHT);
    pen.setWidth(BORDER_WIDTH);
    brush.setColor(QColor(255,0,0));
    painter.setBrush(brush);
    for (int i=0;i<field->blocks_count;i++) {
        painter.drawRect(field->blocks[i]);
    }


    brush = QBrush(QColor(0,255,0));
    pen.setColor(QColor(0,255,0));
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawEllipse(field->ball->pos,field->ball->radius,field->ball->radius);
    painter.end();

    painter.begin(this);
    painter.drawPixmap(0,0,WIDTH, HEIGHT ,pixmap);
    painter.end();
}

void MainWidget::paintEvent(QPaintEvent *event){
    draw();
}

