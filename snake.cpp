#include "snake.h"
#include "field.h"
#include "board.h"
#include "rib.h"

#include "straight.h"
#include "head.h"
#include "tail.h"
#include "toleft.h"
#include "toright.h"

Snake::Snake(Board *newBoard)
{
    board = newBoard;
    direction = UP;
    alive = true;
    eatenApples = 0;
    length = SNAKE_START_LENGHT;
    appleWasJustEaten = false;

    headLocation[0] = board->getSize()/2;
    headLocation[1] = board->getSize()/2;
    Field *ptr;

    for (int i = length-1; i>=0; i--){
        ptr = board->getField(headLocation[0],headLocation[1]+i);
        QLabel *ptrLabel = ptr->getLabel();
        delete ptr;
        //Tworzenie węża z cząstek
        if(i== length-1){
        ptr = new Tail(ptrLabel);
        }
        else if(i==0){
        ptr = new Head(ptrLabel);
        }
        else{
        ptr = new Straight(ptrLabel);
        }

        Rib *temp = dynamic_cast<Rib*>(ptr); //Rib dziedziczy z klasy Field. Wszystko co bedziemy tu castowac dziedziczy z klasy Rib.
        temp->setAngle(direction);
        ribs.push_back(temp);
    }
}

void Snake::move()
{
    //Zmiana z TYLU weza
    if (appleWasJustEaten) appleWasJustEaten = false;
    else if (alive) {
        //Zwalnianie pól
        Field *tail = *ribs.begin();
        QLabel *tailLabel = tail->getLabel();
        ribs.erase(ribs.begin());
        delete tail;
        tail = new Space(tailLabel);

        //Końcówka ogona
        Rib *lastRib = *ribs.begin();
        QLabel *lastRibLabel = lastRib->getLabel();
        int lastRibAngle = lastRib->getAngle();
        delete lastRib;
        lastRib = new Tail(lastRibLabel);
        lastRib->setAngle(lastRibAngle);
       // direction = (direction - 90)%360;
    }

    //Zmiana z "zaglowia" weza
    Rib *neckRib = ribs.at(ribs.size()- 1);
    int neckAngle = neckRib->getAngle();
    Field *newRib = board->getField(headLocation[0],headLocation[1]);
    QLabel *newRibLabel = newRib->getLabel();

    delete newRib;

    if((direction-neckAngle+360)%360==90){
    newRib = new ToRight(newRibLabel);

    }
    else if((direction-neckAngle+360)%360==270){
    newRib = new ToLeft(newRibLabel);
    }
    else{
    newRib = new Straight(newRibLabel);
    }


    Rib *temp = dynamic_cast<Rib*>(newRib);
    temp->setAngle(direction);

    //Obliczanie nowego polozenia glowy.
    if(direction == UP) {
        headLocation[1]--;
        if (headLocation[1]<0) headLocation[1]=board->getSize()-1;
    }
    else if(direction == DOWN) {
        headLocation[1]++;
        headLocation[1] = headLocation[1]%board->getSize();
    }
    else if(direction == LEFT) {
        headLocation[0]--;
        if (headLocation[0]<0) headLocation[0]=board->getSize()-1;
    }
    else if(direction == RIGHT) {
        headLocation[0]++;
        headLocation[0] = headLocation[0]%board->getSize();
    }


    //Zmiana z PRZODU weza
     newRib = board->getField(headLocation[0],headLocation[1]);
    newRib->action(this);

     newRibLabel = newRib->getLabel();
    delete newRib;
    newRib = new Head(newRibLabel);

     temp = dynamic_cast<Rib*>(newRib);
    temp->setAngle(direction);
    ribs.push_back(temp);


}

void Snake::setDirection(DIRECTION dir)
{
    if( !(dir-180==direction || dir+180==direction) )
        direction = dir;
}

bool Snake::isAlive()
{
    return alive;
}

int Snake::getEatenApples()
{
    return eatenApples;
}

void Snake::die()
{
    alive = false;
}

void Snake::eatApple()
{
    appleWasJustEaten = true;
    eatenApples++;
    length++;
}
