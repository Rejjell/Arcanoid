#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "ball.h"
#include "block.h"
#include "block.h"
#include "QRect"
#include "collision.h"
#include "QList"

class GameField
{
public:
    GameField();
    ~GameField();
    void NextTact();
    void movePlatformLeft(int pos);
    void movePlatformRight(int pos);

public:
    Ball* ball;
    QList<QRect>* blocks;
    QList<QRect>* platforms;
    int blocks_count = 5;
    int platformDx = 5;
    const int PLAYER = 0;
    const int ENEMY = 1;
    int dest_x = -1;
};

#endif // GAMEFIELD_H
