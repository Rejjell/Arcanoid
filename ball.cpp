#include "ball.h"



Ball::Ball(QPoint _position, int _radius):
    pos(_position),
    radius(_radius)
{
     dx = 4;
     dy = 2;
}

Ball::Ball(int x,int y, int _radius)
{
    Ball(QPoint(x,y), _radius);
}

int Ball::clamp(int value)
{
    int shift = value + radius - WIDTH;
    shift = shift < 0? 0 : shift;
    if (shift == 0) {
        shift = value - radius;
        shift = shift > 0? 0 : shift;
    }
    return value - shift;
}

void Ball::move()
{
    pos.setX(clamp(pos.x() + dx));
    pos.setY(clamp(pos.y() + dy));
}
