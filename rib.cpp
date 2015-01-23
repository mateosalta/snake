#include "rib.h"
#include <iostream>

Rib::Rib(QLabel *label) : Field(label)
{

}

Rib::~Rib()
{
    delete thisPixmap;
}

void Rib::setAngle(int newAngle)
{
    angle = newAngle;
    QPixmap *newPixmap = rotatedPixmap(thisPixmap, angle);
    delete thisPixmap;
    thisPixmap = newPixmap;
    label->setPixmap(*thisPixmap);
}

int Rib::getAngle()
{
    return angle;
}

void Rib::action(Snake *reptile)
{
    reptile->die();
}


