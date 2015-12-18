#include "collision.h"
#include "iostream"
#include "math.h"

Collision::Collision()
{

}

void Collision::check(Ball* ball, Ball* ball_2){

}

bool Collision::check(Ball* ball, QRect block){
    bool isCollide = false;

    if ((abs(ball->pos.x()-block.x()) <= ball->radius ) ||
            (abs(ball->pos.x()-block.x()-block.width()) <= ball->radius ))  {
        ball->dx *= -1;
        isCollide = true;
    }

    if ((abs(ball->pos.y()-block.y()) <= ball->radius ) ||
            (abs(ball->pos.y()-block.y()-block.height()) <= ball->radius )){
        ball->dy *= -1;
        isCollide = true;
    }

    return isCollide;
}
