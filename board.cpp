#include "board.h"

#include <stdlib.h>
#include <time.h>

Board::Board(QWidget *GridWidget, QGridLayout *GridLayout, int Size)
{
    this->gridWidget = GridWidget;
    this->gridLayout = GridLayout;
    this->size = Size;

    fields = new Field**[size];
    for (int i=0; i< size; i++){
        fields[i] = new Field*[size];
    }

    gridWidget->setGeometry(QRect( 5, 25, size*TILESIZE, size*TILESIZE ));

    for (int i = 0; i<size; i++){
        for (int k=0; k<size; k++){
            QLabel *label = new QLabel();
            fields[k][i] = new Space(label);
            gridLayout->addWidget(label,k,i);
        }
    }

    srand(time(0));

    createApple();
}

Board::~Board()
{
    //deleteChildWidgets(gridLayout);
    for (int i = 0; i<size; i++){
        for (int k=0; k<size; k++){
            Field* oldField = getField(i,k);
            QLabel *oldLabel = oldField->getLabel();
            gridLayout->removeWidget(oldLabel);
            delete oldLabel;
            delete oldField;
        }
    }
}

Field *Board::getField(int x, int y)
{
    return fields[y][x];
}

int Board::getSize()
{
    return size;
}

void Board::createApple()
{
    Field *newApple;
    do {
        int x = rand()%(size-1);
        int y = rand()%(size-1);
        newApple = getField(x,y);
    } while (newApple->fieldType() != "Space");


    QLabel *newAppleLabel = newApple->getLabel();
    delete newApple;
    newApple = new Apple(newAppleLabel, this);
}
