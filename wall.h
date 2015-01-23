#ifndef WALL_H
#define WALL_H

#include "field.h"
#include <QPixmap>

class Wall : public Field
{
public:
    Wall(QLabel *label);
    //Wall(Field *field);
    void action(Snake *reptile);
private:
    static QPixmap *patternPixmap;
};

#endif // WALL_H
