#include "gamefield.h"

GameField::GameField()
{
    ball = new Ball(QPoint(50,50),10);

    blocks = new QList<QRect>;
    platforms = new QList<QRect>;

    platforms->append(QRect(130,290,40,10));
    platforms->append(QRect(130,0,40,10));

    //blocks->append(QRect(130,290,40,10));
    blocks->append(QRect(-5,0,5,HEIGHT));
    blocks->append(QRect(WIDTH,0,5,HEIGHT));
    blocks->append(QRect(0,-5,WIDTH,5));
    //bottom edge
    //blocks->append(QRect(0,HEIGHT,WIDTH,5));
    //test inner block
    //blocks->append(QRect(100, 100, 60,60));


}

void GameField::NextTact() {
    QRect player = (QRect) platforms->at(PLAYER);
    int x_center = player.x() + player.width() / 2;

    if (dest_x>0 && dest_x < x_center)
        movePlatformLeft(PLAYER);
    if (dest_x>0 && dest_x > x_center)
        movePlatformRight(PLAYER);

    QRect enemy = platforms->at(ENEMY);
    if (ball->pos.x() < enemy.x() + ball->radius)
        movePlatformLeft(ENEMY);
    if (ball->pos.x() > enemy.x() + enemy.width() - ball->radius)
        movePlatformRight(ENEMY);

    QList<QRect>::iterator it = blocks->begin();
    while (it != blocks->end()) {
        Collision::check(ball,*it);
        it++;
    }

    it = platforms->begin();
    while (it != platforms->end()) {
        Collision::check(ball,*it);
        it++;
    }

    ball->move();
}

void GameField::movePlatformLeft(int pos) {
    QRect platform = platforms->at(pos);
    QRect newPlatform(platform.x() - platformDx, platform.y(), platform.width(), platform.height());
    platforms->replace(pos, newPlatform);
    printf("%d %d\n",blocks->first().x(), blocks->first().y());
}

void GameField::movePlatformRight(int pos) {
    QRect platform = platforms->at(pos);
    QRect newPlatform(platform.x() + platformDx, platform.y(), platform.width(), platform.height());
    platforms->replace(pos, newPlatform);
    printf("%d %d\n",blocks->first().x(), blocks->first().y());
}

GameField::~GameField() {
    delete ball;
    delete blocks;
}
