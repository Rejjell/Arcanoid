#ifndef BALL_H
#define BALL_H
#include "QPoint"
#include "constants.h"

class Ball
{
public:
    Ball(QPoint _position, int radius);
    Ball (int x, int y, int radius);
    void move();
    void setPosition(QPoint pos);
public:
    QPoint pos;
    int radius, dx,dy;
    int clamp(int value);
};

#endif // BALL_H
