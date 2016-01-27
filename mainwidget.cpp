#include "mainwidget.h"
#include "iostream"
#include <QDebug>

MainWidget::MainWidget(QWidget* parent):
    QWidget(parent)
{
    this->move(0,0);
    this->setGeometry(0,0,WIDTH, HEIGHT );
    field = new GameField();
    count = 0;
    setFocus();
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


    QList<QRect>::iterator it = field->blocks->begin();
    while (it != field->blocks->end()) {
        painter.drawRect(*it);
        it++;
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

void MainWidget::keyPressEvent( QKeyEvent * event )
{
    qDebug() << "keyPressed";
    std::cout << event->key() << std::endl;
    if (event->key() == Qt::Key_Left )
    {
        field->movePlatformLeft();
        qDebug() << "Left pressed";
    }

    if (event->key() == Qt::Key_Right) {
        field->movePlatformRight();
        qDebug() << "Right pressed";
    }
}

void MainWidget::mousePressEvent(QMouseEvent *event) {
    qDebug() << "Mouse pressed";
    QRect platform = (QRect) field->blocks->first();
    int x_center = platform.x() + platform.width() / 2;
    if (event->x() < x_center)
        field->dir = GameField::LEFT;
    else
        field->dir = GameField::RIGHT;
    field->dest_x = event->x();
    setFocus();
}

void MainWidget::mouseMoveEvent(QMouseEvent *event) {
    qDebug() << "Mouse move";
    if (event->buttons() & Qt::LeftButton) {
    QRect platform = (QRect) field->blocks->first();
    int x_center = platform.x() + platform.width() / 2;
    if (event->x() < x_center)
        field->dir = GameField::LEFT;
    else
        field->dir = GameField::RIGHT;
    }
    field->dest_x = event->x();
}

void MainWidget::mouseReleaseEvent(QMouseEvent *) {
    field->dir = GameField::NONE;
    field->dest_x = -1;
}

void MainWidget::restart() {
    delete field;
    field = new GameField();
}
