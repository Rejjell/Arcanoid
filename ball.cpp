#include "ball.h"
#include "QPoint"

Ball::Ball(QPoint _position, int _radius):
    pos(_position),
    radius(_radius)
{
     dx = -5;
     dy = 0;
}

Ball::Ball(int x,int y, int _radius)
{
    Ball(QPoint(x,y), _radius);
}

void Ball::move()
{
    pos.setX(pos.x() + dx);
    pos.setY(pos.y() + dy);

    if (pos.x() + radius + dx > 300 || pos.x() - radius + dx < 0)
        dx *= -1;
    if (pos.y() + radius + dy > 300 || pos.y() - radius + dy < 0)
        dy *= -1;

    int shiftX = pos.x() + radius - 310;
    shiftX = shiftX < 0? 0 : shiftX;
    pos.setX(pos.x() - shiftX);
    shiftX = pos.x() - radius;
    shiftX = shiftX > 0? 0 : shiftX;
    pos.setX(pos.x() - shiftX);

    int shiftY = pos.y() + radius - 300;
    shiftY = shiftY < 0? 0 : shiftY;
    pos.setY(pos.y() - shiftY);
    shiftY = pos.y() - radius;
    shiftY = shiftY > 0? 0 : shiftY;
    pos.setY(pos.y() - shiftY);
}
