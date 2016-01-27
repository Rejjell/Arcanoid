#ifndef COLLISION_H
#define COLLISION_H
#include "QRect"
#include "ball.h"

class Collision
{
public:
    Collision();
    static void check(Ball* ball, Ball* ball_2);
    static bool check(Ball* ball, QRect block);
};

#endif // COLLISION_H
