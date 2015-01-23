#ifndef APPLE_H
#define APPLE_H

#include "field.h"

class Apple : public Field
{
public:
    Apple(QLabel *label, Board *board);
    ~Apple();
    std::string fieldType();
    void action(Snake *reptile);
private:
    static QPixmap *patternPixmap;
    Board *board;
};

#endif // APPLE_H
