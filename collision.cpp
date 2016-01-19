#include "collision.h"
#include "iostream"
#include "math.h"

Collision::Collision()
{

}

void Collision::check(Ball* ball, Ball* ball_2){

}

bool Collision::isWork=true;

bool Collision::check(Ball* ball, QRect block){
    if (!isWork)
        return false;
    bool dx_collide = false;
    bool dy_collide = false;
    if ((ball->pos.y() + ball->radius > block.y()) && (ball->pos.y()-ball->radius /*- ball->dy*/ < block.y() + block.height())
         && ((abs(ball->pos.x()-block.x()) <= ball->radius ) ||
            (abs(ball->pos.x()-block.x()-block.width()) <= ball->radius )))  {
        std::cout << "dx: " <<ball->pos.x() << " " << ball->pos.y() << " Rect: " << block.x() << " " << block.y() << std::endl;
        dx_collide = true;
    }
    if ((ball->pos.x()+ball->radius > block.x()) && (ball->pos.x()-ball->radius /*- dx_orig*/< block.x() + block.width())
         && ((abs(ball->pos.y()-block.y()) <= ball->radius ) ||
            (abs(ball->pos.y()-block.y()-block.height()) <= ball->radius ))){
        std::cout << "dy: " << ball->pos.x() << " " << ball->pos.y() << " Rect: " << block.x() << " " << block.y() << std::endl;
        dy_collide = true;
    }

    int prev_x = ball->pos.x() - ball->dx;
    int prev_y = ball->pos.y() - ball->dy;
    if (dx_collide && dy_collide) {
    if (( prev_x < block.x()) && (prev_y < block.y()) ||
            (prev_x < block.x()) && (prev_y > block.y() + block.width()) ||
            ( prev_x > block.x() +block.width()) && (prev_y < block.y()) ||
            ( prev_x > block.x() + block.width()) && (prev_y > block.y() + block.height())) {

        float cornerX = prev_x < block.x() ? block.x() : block.x() + block.width();
        float cornerY =  prev_x < block.y() ? block.y() : block.y() + block.height() ;



        float ballX = ball->pos.x();
        float ballY = ball->pos.y();
        float x = ballX - cornerX;
        float y = ballY - cornerY;
        float c = -2 * (ball->dx * x + ball->dy * y) / (x * x + y * y);
        ball->dx = ball->dx + c * x;
        ball->dy = ball->dy + c * y;


       /* simple edge reflect
        if (ball->pos.x() < block.x() - 50) {
            ball->dx *= -1;
            ball->dy *= -1;*/

    } else {
        if (prev_y > block.y() && prev_y < block.y() + block.height())
            ball->dx *= -1;
        if (prev_x > block.x() && prev_x < block.x() + block.height())
            ball->dy *= -1;
    }
    } else {
        if (dx_collide)
            ball->dx*=-1;
        if (dy_collide)
            ball->dy *=-1;
    }
    return dx_collide || dy_collide;
}
