#ifndef SNAKE_H
#define SNAKE_H

#include "field.h"
#include <vector>

#define SNAKE_START_LENGHT 3

enum DIRECTION {
    UP = 0,
    RIGHT = 90,
    DOWN = 180,
    LEFT = 270
};

class Board;
class Field;
class Rib;

class Snake
{
public:
    Snake(Board *board);
    void move();
    void setDirection(DIRECTION dir);
    bool isAlive();
    int getEatenApples();
    void die();
    void eatApple();

private:
    Board *board;
    DIRECTION direction; //0 - up, 90 - right... four directions, clockwise, set by enumerator.
    bool alive;
    int headLocation[2];
    int eatenApples;
    int length;
    bool appleWasJustEaten;

    std::vector<Rib *> ribs;
};

#endif // SNAKE_H
