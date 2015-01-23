#ifndef BOARD_H
#define BOARD_H

#include <QApplication>
#include <QtGui>
#include <QGridLayout>
#include <QLabel>
#include "field.h"
#include "space.h"
#include "wall.h"
#include "apple.h"

class Board
{
public:
    Board(QWidget *Grid, QGridLayout *GridLayout, int Size=5);
    ~Board();
    Field *getField(int x, int y);
    int getSize();
    void createApple();

private:
    int size;
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    Field ***fields;
};

#endif // BOARD_H
