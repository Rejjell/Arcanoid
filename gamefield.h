#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "ball.h"
#include "block.h"
#include "block.h"

class GameField
{
public:
    GameField();
    void NextTact();

    Ball* ball;
    Block** blocks;
};

#endif // GAMEFIELD_H
