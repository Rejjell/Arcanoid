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
    void movePlatformLeft();
    void movePlatformRight();

public:
    Ball* ball;
    QList<QRect>* blocks;
    int blocks_count = 5;
    int platformDx = 5;
    enum direction {NONE, LEFT, RIGHT};
    direction dir = NONE;
    int dest_x = -1;
};

#endif // GAMEFIELD_H
