#ifndef STRAIGHT_H
#define STRAIGHT_H

#include "rib.h"
#include <QPixmap>

class Straight : public Rib
{
public:
    Straight(QLabel *label);
    ~Straight();

private:
    static QPixmap *patternPixmap;
};

#endif // STRAIGHT_H
