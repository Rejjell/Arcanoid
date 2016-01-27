#include "gamefield.h"

GameField::GameField()
{
    ball = new Ball(QPoint(50,50),10);

    blocks = new QList<QRect>;

    blocks->append(QRect(130,290,40,10));
    blocks->append(QRect(-5,0,5,HEIGHT));
    blocks->append(QRect(WIDTH,0,5,HEIGHT));
    blocks->append(QRect(0,-5,WIDTH,5));
    //bottom edge
    //blocks->append(QRect(0,HEIGHT,WIDTH,5));
    //test inner block
    //blocks->append(QRect(100, 100, 60,60));


}

void GameField::NextTact() {
    QRect platform = (QRect) blocks->first();
    int x_center = platform.x() + platform.width() / 2;

    if (dest_x>0 && dest_x < x_center)
        movePlatformLeft();
    if (dest_x>0 && dest_x > x_center)
        movePlatformRight();

/*
    if (dir == GameField::direction::LEFT)
        movePlatformLeft();

    if (dir == GameField::direction::RIGHT)
        movePlatformRight();
*/

    QList<QRect>::iterator it = blocks->begin();
    while (it != blocks->end()) {
        Collision::check(ball,*it);
        it++;
    }
    ball->move();
}

void GameField::movePlatformLeft() {
    QRect platform = blocks->first();
    QRect newPlatform(platform.x() - platformDx, platform.y(), platform.width(), platform.height());
    blocks->replace(0, newPlatform);
    printf("%d %d\n",blocks->first().x(), blocks->first().y());
}

void GameField::movePlatformRight() {
    QRect platform = blocks->first();
    QRect newPlatform(platform.x() + platformDx, platform.y(), platform.width(), platform.height());
    blocks->replace(0, newPlatform);
    printf("%d %d\n",blocks->first().x(), blocks->first().y());
}

GameField::~GameField() {
    delete ball;
    delete blocks;
}
