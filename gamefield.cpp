#include "gamefield.h"

GameField::GameField()
{
    ball = new Ball(QPoint(50,59),10);

    blocks = new QRect[blocks_count];
    blocks[0] = QRect(-5,0,5,HEIGHT);
    blocks[1] = QRect(WIDTH,0,5,HEIGHT);
    blocks[2] = QRect(0,-5,WIDTH,5);
    blocks[3] = QRect(0,HEIGHT,WIDTH,5);
    blocks[4] = QRect(100, 100, 60,60);
}

void GameField::NextTact() {
    for (int i=0; i<blocks_count;i++)
        Collision::check(ball,blocks[i]);
    ball->move();
}
