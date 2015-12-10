#include "gamefield.h"

GameField::GameField()
{
    ball = new Ball(QPoint(37,20),10);

}

void GameField::NextTact() {
    ball->move();
}
