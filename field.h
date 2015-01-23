#ifndef FIELD_H
#define FIELD_H

#define TILESIZE 32

#include "pixmaps.h"
#include "snake.h"
#include <string>
#include <QLabel>



class Snake;

class Field
{
public:
    Field(QLabel *label);
    //Field(Field *field);
    virtual ~Field();
    virtual std::string fieldType();
    virtual void action(Snake *reptile);
    QLabel *getLabel();
    void setLabel(QLabel *Label);
protected:
    QLabel *label;
    QPixmap *thisPixmap;
};

QPixmap *rotatedPixmap(QPixmap* original, int newAngle);

#endif // FIELD_H
