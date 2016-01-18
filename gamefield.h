#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "ball.h"
#include "block.h"
#include "block.h"
#include "QRect"
#include "collision.h"

class GameField
{
public:
    GameField();
    void NextTact();

public:
    Ball* ball;
    QRect* blocks;
    int blocks_count = 5;
};

#endif // GAMEFIELD_H
